#include "CFlight.h"
//
// Created by אילון אהרוני on 12/09/2024.
//

#include "CFlight.h"
#include <iostream>

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
	this->flightInfo =  new CFlightInfo(*other.flightInfo);
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
    os << *r.flightInfo << endl;
    if(r.plane)
	    os << "Plane: " << *r.plane << endl;
    else
        os << "There is no plane yet" << endl;
	if (r.numOfCrewMembers == 0)
	{
		os << "There are no crew members in the flight" << endl;
		return os;
	}
	else
	{
		os << "Crew members: " << endl;
		for(int i = 0; i < r.numOfCrewMembers; i++)
		{
			os << *(r.crewMembers[i]) << endl;
		}
	}
	return os;
}

////
int CFlight::getId() const {
    return this->flightInfo->GetFNum();
}
////