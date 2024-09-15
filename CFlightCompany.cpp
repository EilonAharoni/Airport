
#include "CFlightCompany.h"
#include <iostream>

CFlightCompany::CFlightCompany(const string company_name)
	: company_name(company_name), numOfCrewMembers(0), numOfPlanes(0), numOfFlights(0)
{
	for(int i = 0; i < MAX_CREW_MEMBERS; i++)
	{
		this->crewMembers[i] = nullptr;
	}
	for(int i = 0; i < MAX_PLANES; i++)
	{
		this->planes[i] = nullptr;
	}
	for(int i = 0; i < MAX_FLIGHTS; i++)
	{
		this->flights[i] = nullptr;
	}
}

const string CFlightCompany::GetName() const
{
	return this->company_name;
}

void CFlightCompany::SetName(const string new_company_name)
{
	if (new_company_name.empty())
	{
		cout << "Company name must not be empty" << endl;
		return;
	}
	this->company_name = new_company_name;
}

void CFlightCompany::Print(ostream& out) const
{
	out << "Company name: " << this->company_name << endl;
}


//void CFlightCompany::Print() const
//{
//	cout << "Company name: " << this->company_name << endl;
//}

//Need to implement
CCrewMember* CFlightCompany::GetCrewMemberByID(int id) const
{
	for(int i = 0; i < this->numOfCrewMembers; i++)
	{
		if(this->crewMembers[i]->getId() == id)
		{
			return this->crewMembers[i];
		}
	}
	return nullptr;
}

//Need to implement
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

bool CFlightCompany::AddCrewMember(const CCrewMember& crewMember)
{
    if(this->numOfCrewMembers >= MAX_CREW_MEMBERS)
    {
        cout << "cant add more crew members" << endl;
        return false;
    }
    for (int i = 0; i < numOfCrewMembers; ++i)
    {
        if (*this->crewMembers[i] == crewMember)
        {
            cout << "This crew member already  in the company" << endl;
            return false;
        }

    }
    *this->crewMembers[numOfCrewMembers++] = crewMember;
	return true;
}

bool CFlightCompany::AddPlane(const CPlane& plane)
{
    if(this->numOfPlanes >= MAX_PLANES)
    {
        cout << "cant add more planes" << endl;
        return false;
    }

    for (int i = 0; i < numOfPlanes; ++i)
    {
        if (*this->planes[i] == plane)
        {
            cout << "This plane already in the company" << endl;
            return false;
        }
    }
    *this->planes[numOfPlanes++] = plane;
	return true;
}

bool CFlightCompany::AddFlight(const CFlight& flight)
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
    *this->flights[numOfFlights++] = flight;
	return true;
}

bool CFlightCompany::AddCrewToFlight(int flightID, int crewMemberID) const
{
    CCrewMember* crewMember = this->GetCrewMemberByID(crewMemberID);
    CFlight* flight = this->GetFlightByID(flightID);
    if(!crewMember || !flight)
        return false;


    *flight = *flight + crewMember;
    return true;


}

const CFlightCompany& CFlightCompany::operator=(const CFlightCompany& r)
{
	if(this == &r)
		return *this;
	
	this->company_name = r.company_name;
	
	// Copy crew members
	for (int i = 0; i < r.numOfCrewMembers; i++)
	{
		this->crewMembers[i] = r.crewMembers[i];
	}
	this->numOfCrewMembers = r.numOfCrewMembers;
	
	// Copy planes
	for (int i = 0; i < r.numOfPlanes; i++)
	{
		this->planes[i] = r.planes[i];
	}
	this->numOfPlanes = r.numOfPlanes;
	
	// Copy flights
	for (int i = 0; i < r.numOfFlights; i++)
	{
		this->flights[i] = r.flights[i];
	}
	this->numOfFlights = r.numOfFlights;
	
	return *this;
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
	out << "Company name: " << r.company_name << endl;
	// Print crew members
	out << "There are " << r.numOfCrewMembers << " crew members" << endl;
	for (int i = 0; i < r.numOfCrewMembers; i++)
	{
		out << r.crewMembers[i] << endl;
	}
	// Print planes
	out << "There are " << r.numOfPlanes << " planes" << endl;
	for (int i = 0; i < r.numOfPlanes; i++)
	{
		out << r.GetPlane(i) << endl;
	}
	// Print flights
	out << "There are " << r.numOfFlights << " flights" << endl;
	for (int i = 0; i < r.numOfFlights; i++)
	{
		out << r.flights[i] << endl;
	}
	return out;
}
