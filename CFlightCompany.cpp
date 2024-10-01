
#include <iostream>
#include <typeinfo>
#include "CFlightCompany.h"
#include "CPilot.h"
#include "CHost.h"
#include "Cargo.h"
//Still get warnings about uninitalized variables
CFlightCompany::CFlightCompany(const string& company_name)
	: company_name(company_name), numOfCrewMembers(0), numOfPlanes(0), numOfFlights(0)
{
	for (auto& crewMember : this->crewMembers)
	{
		crewMember = nullptr;
	}
	for (auto& plane : this->planes)
	{
		plane = nullptr;
	}
	for (auto& flight : this->flights)
	{
		flight = nullptr;
	}
}

CFlightCompany::~CFlightCompany()
{
	//delete crew members
	for (int i = 0; i < this->numOfCrewMembers; i++)
	{
		delete this->crewMembers[i];
		this->crewMembers[i] = nullptr;
	}
	//delete planes
	for (int i = 0; i < this->numOfPlanes; i++)
	{
		delete this->planes[i];
		this->planes[i] = nullptr;
	}
	//delete flights
	for (int i = 0; i < this->numOfFlights; i++)
	{
		delete this->flights[i];
		this->flights[i] = nullptr;
	}
}

const string CFlightCompany::getName() const
{
	return this->company_name;
}

void CFlightCompany::setName(const string& new_company_name)
{
	if (new_company_name.empty())
	{
		cout << "Company name must not be empty" << endl;
		return;
	}
	this->company_name = new_company_name;
}

void CFlightCompany::print(ostream& out) const
{
    out << *this << endl;
}

CCrewMember* CFlightCompany::GetCrewMember (int index) const
{
    if(index < 0 || index >= this->numOfCrewMembers)
        return nullptr;

    return this->crewMembers[index];

}

CFlight* CFlightCompany::GetFlightByID(int id) const
{
	for(int i = 0; i < this->numOfFlights; i++)
	{
		if(this->flights[i]->getId() == id)
		{
			return this->flights[i];
		}
	}
	return nullptr;
}

CPlane* CFlightCompany::GetPlane(int index) const
{
	if(index < 0 || index >= this->numOfPlanes)
		return nullptr;
		
	return this->planes[index];
}

bool CFlightCompany::AddCrewMember(CCrewMember& crewMember)
{
    if(this->numOfCrewMembers >= MAX_CREW_MEMBERS)
    {
        cout << "cant add more crew members" << endl;
        return false;
    }

    for (int i = 0; i < numOfCrewMembers; ++i)
    {// Check if they are of the same type and if they are equal
        if (typeid(*this->crewMembers[i]) == typeid(crewMember) &&  *this->crewMembers[i] == crewMember)
        {
            cout << "This crew member already  in the company" << endl;
            return false;
        }

    }
    // Add the correct type of crew member to the company
    if (CPilot* pilot = dynamic_cast<CPilot*>(&crewMember)) {
        // Add a new CPilot
        this->crewMembers[numOfCrewMembers] = new CPilot(*pilot);
    }
    else if (CHost* host = dynamic_cast<CHost*>(&crewMember)) {
        // Add a new CHost
        this->crewMembers[numOfCrewMembers] = new CHost(*host);
    }
    numOfCrewMembers++;
    return true;
}

bool CFlightCompany::AddPlane(CPlane& plane)
{
    if(this->numOfPlanes >= MAX_PLANES)
    {
        cout << "cant add more planes" << endl;
        return false;
    }

    for (int i = 0; i < numOfPlanes; ++i)
    {
        if (typeid(plane) == typeid(*planes[i]) && *this->planes[i] == plane)
        {
            cout << "This plane already in the company" << endl;
            return false;
        }
    }
    CCargo* cargo = dynamic_cast<CCargo*>(&plane);
    if(cargo)
    {
        this->planes[numOfPlanes] = new CCargo(*cargo);
		numOfPlanes++;
        return true;
    }
    this->planes[numOfPlanes] = new CPlane(plane);
	numOfPlanes++;
	return true;
}

bool CFlightCompany::AddFlight(CFlight& flight)
{
    if(this->numOfFlights >= MAX_FLIGHTS)
    {
        cout << "cant add more flight" << endl;
        return false;
    }

    for (int i = 0; i < numOfFlights; ++i)
    {
        if (*this->flights[i] == flight)
        {
            cout << "This flight already in the company" << endl;
            return false;
        }
    }
    this->flights[numOfFlights] = new CFlight(flight);
	numOfFlights++;
	return true;
}

bool CFlightCompany::AddCrewToFlight(int flightID, int index) const
{
    CCrewMember* crewMember = this->GetCrewMember(index);
    CFlight* flight = this->GetFlightByID(flightID);
    if(!crewMember || !flight)
        return false;

    *flight = *flight + crewMember;
    return true;
}

bool CFlightCompany::operator==(const CFlightCompany& r) const
{
	if(this->company_name != r.company_name)
		return false;
	
	// Compare crew members
	if(this->numOfCrewMembers != r.numOfCrewMembers)
		return false;
	for (int i = 0; i < this->numOfCrewMembers; i++)
	{
		if(this->crewMembers[i] != r.crewMembers[i])
			return false;
	}
	
	// Compare planes
	if(this->numOfPlanes != r.numOfPlanes)
		return false;
	for (int i = 0; i < this->numOfPlanes; i++)
	{
		if(this->planes[i] != r.planes[i])
			return false;
	}
	
	// Compare flights
	if(this->numOfFlights != r.numOfFlights)
		return false;
	for (int i = 0; i < this->numOfFlights; i++)
	{
		if(this->flights[i] != r.flights[i])
			return false;
	}

	return true;
}

ostream& operator<<(ostream& out, const CFlightCompany& r)
{
	out << "Flight company: " << r.company_name << endl;
	// Print crew members
	out << "*******************************************************" << endl;
	out << "There are " << r.numOfCrewMembers << " crew members:" << endl;
	for (int i = 0; i < r.numOfCrewMembers; i++)
	{
		out << *(r.crewMembers[i]) << endl;
	}
	// Print planes
	out << "*******************************************************" << endl;
	out << "There are " << r.numOfPlanes << " planes:" << endl;
	for (int i = 0; i < r.numOfPlanes; i++)
	{
		out << *r.planes[i] << endl;
	}
	// Print flights
	out << "*******************************************************" << endl;
	out << "There are " << r.numOfFlights << " flights:" << endl;
	for (int i = 0; i < r.numOfFlights; i++)
	{
		out << *r.flights[i] << endl;
	}
	return out;
}

int CFlightCompany::GetCargoCount() const
{
    int numOfCargo =0;
    for (int i =0; i<numOfPlanes; i++)
    { //// check if it is cargo plane withe dynamic casting
        CCargo* cargo = dynamic_cast<CCargo*>(planes[i]);
        if(cargo)
            numOfCargo++;
    }

    return numOfCargo;
}

void CFlightCompany::CrewGetPresent() const
{
    for (int i = 0; i < numOfCrewMembers; i++)
    {
        crewMembers[i]->getHolidayGift();
    }
}

void CFlightCompany::PilotsToSimulator() const
{
    for (auto& crewM:crewMembers)
    {
        CPilot* pilot = dynamic_cast<CPilot*>(crewM);
        if(pilot)
            pilot->comeToSimulator();
    }

}

void CFlightCompany::CrewGetUniform() const
{
    for (int i = 0; i<numOfCrewMembers; i++)
    {
        crewMembers[i]->changeUniform();
    }
}

//** WE dont wanna be able to clone a company **//
// 
//const CFlightCompany& CFlightCompany::operator=(const CFlightCompany& r)
//{
//	if(this == &r)
//		return *this;
//	
//	this->company_name = r.company_name;
//	
//	// Copy crew members
//	for (int i = 0; i < r.numOfCrewMembers; i++)
//	{
//		this->crewMembers[i] = r.crewMembers[i];
//	}
//	this->numOfCrewMembers = r.numOfCrewMembers;
//	
//	// Copy planes
//	for (int i = 0; i < r.numOfPlanes; i++)
//	{
//		this->planes[i] = r.planes[i];
//	}
//	this->numOfPlanes = r.numOfPlanes;
//	
//	// Copy flights
//	for (int i = 0; i < r.numOfFlights; i++)
//	{
//		this->flights[i] = r.flights[i];
//	}
//	this->numOfFlights = r.numOfFlights;
//	
//	return *this;
//}

