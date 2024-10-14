#include "CFlight.h"
#include "Cargo.h"
#include "CPilot.h"
#include "CHost.h"
#include <fstream>

//Ctors
CFlight::CFlight(const CFlightInfo& flightInfo)
{
	this->plane = nullptr;
	this->flightInfo = new CFlightInfo(flightInfo);
	this->numOfCrewMembers = 0;
	for (int i = 0; i < MAX_CREW_MEMBERS; i++)
	{
		this->crewMembers[i] = nullptr;
	}
}

CFlight::CFlight(const CFlightInfo& flightInfo, CPlane* plane)
{
	this->plane = plane;
	this->flightInfo = new CFlightInfo(flightInfo);
	this->numOfCrewMembers = 0;
	for(int i = 0; i < MAX_CREW_MEMBERS; i++)
	{
		this->crewMembers[i] = nullptr;
	}
}



CFlight::CFlight(const CFlight& other)
{
	this->flightInfo = new CFlightInfo(*other.flightInfo);
	this->plane = other.plane;
	this->numOfCrewMembers = other.numOfCrewMembers;
	for(int i = 0; i < other.numOfCrewMembers; i++)
	{
		this->crewMembers[i] = other.crewMembers[i];
	}
}

CFlight::~CFlight()
{
	delete this->flightInfo;
	this->flightInfo = nullptr;
}

void CFlight::setPlane(CPlane* plane)
{
	this->plane = plane;
}

CFlight& CFlight::operator+(CCrewMember* crewMember)
{
	if(this->numOfCrewMembers < MAX_CREW_MEMBERS)
	{
	//Check if the crew member is already in the flight
		for(int i = 0; i < this->numOfCrewMembers; i++)
			{
				if(*this->crewMembers[i] == *crewMember)
				{
					cout << "The crew member is already in the flight" << endl;
					return *this;
				}
			}
		this->crewMembers[this->numOfCrewMembers] = crewMember;
		++(this->numOfCrewMembers);
		}
	return *this;
}

CFlight& CFlight::operator=(const CFlight& r)
{
	if(this != &r)
	{
		delete this->flightInfo;
		this->flightInfo = new CFlightInfo(*r.flightInfo);
		this->plane = r.plane;
		this->numOfCrewMembers = r.numOfCrewMembers;
		for(int i = 0; i < r.numOfCrewMembers; i++)
		{
			this->crewMembers[i] = r.crewMembers[i];
		}
	}
	return *this;
}

bool CFlight::operator==(const CFlight& r) const
{
if(*this->flightInfo == *r.flightInfo && this->plane == r.plane && 
	this->numOfCrewMembers == r.numOfCrewMembers)
	{
		for(int i = 0; i < this->numOfCrewMembers; i++)
		{
			if(this->crewMembers[i] != r.crewMembers[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

ostream& operator<<(ostream& os, const CFlight& r)
{
    os << *r.flightInfo;
    if (typeid(os) != typeid(ofstream))
    {
        os << endl;
        if(r.plane)
            os << "Plane: " << *r.plane << endl;
        else
            os << "There is no plane yet" << endl;
        if (r.numOfCrewMembers == 0)
        {
            os << "There are 0 crew members in the flight" << endl;
            return os;
        }
        else
        {
            os << "There are " <<  r.numOfCrewMembers << " crew memebers in flight:" <<endl;
            for(int i = 0; i < r.numOfCrewMembers; i++)
            {
                os << *(r.crewMembers[i]) << endl;
            }
        }
    } else
    {
        if(r.plane)
            os << 1 << " " << r.plane->getId() << endl;

        else
            os << 0 << endl;

        os << r.numOfCrewMembers << endl;
        for (int i = 0; i < r.numOfCrewMembers; ++i)
        {
            os << r.crewMembers[i] << endl;
        }
    }

	return os;
}

int CFlight::getId() const
{
    return this->flightInfo->getFNum();
}

const CFlightInfo &CFlight::GetFlightInfo() const
{
    return *this->flightInfo;
}

bool CFlight::TakeOff() const
{
    int numOfPilots = 0;
    int numOfSeniorHost = 0;
    for (int i = 0; i < numOfCrewMembers; ++i)
    {
        CHost* host = dynamic_cast<CHost*>(crewMembers[i]);
        if(host)
        {
            if (host->types[host->getType()] == "Super")
                numOfSeniorHost++;
        } else
            numOfPilots++;
    }
    CCargo* cargo = dynamic_cast<CCargo*>(plane);
    if(cargo)
    {
        if (numOfPilots < 1)
            return false;

        cargo->takeOff(flightInfo->getFlightTime());
    }
    else
    {
        if(numOfPilots != 1 || numOfSeniorHost > 1)
            return false;
    }
    for (int i = 0; i < numOfCrewMembers; i++)
    {
        crewMembers[i]->takeoff(flightInfo->getFlightTime());
    }
    return true;
}
