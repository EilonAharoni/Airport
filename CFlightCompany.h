
#ifndef AIRPORT_CFLIGHTCOMPANY_H
#define AIRPORT_CFLIGHTCOMPANY_H

#include <string>
#include "CCrewMember.h"
#include "CPlane.h"
#include "CFlight.h"
#include "CFlightCompException.h"

#define MAX_PLANES 10
#define MAX_FLIGHTS 10

class CFlightCompany
{
public:
	CFlightCompany(const string& name);
	CFlightCompany(const CFlightCompany& other) = delete; // Copy Constructor
	~CFlightCompany();									  // Destructor
    CFlightCompany() = delete;
	const string getName() const;
	void setName(const string& name);
	void print(ostream& out) const; // Print function

	// Part 2
	CCrewMember* GetCrewMember(int index) const;
	CFlight* GetFlightByID(int id) const;
	CPlane& operator[](int index) const;
    int GetCargoCount() const;

	bool AddCrewMember(CCrewMember& crewMember);
	bool AddPlane(CPlane& plane);
	bool AddFlight(CFlight& flight);
	bool AddCrewToFlight(int flightID, int crewMemberIndex) const;

    //part3
    void CrewGetPresent() const;
    void PilotsToSimulator() const;
    void CrewGetUniform() const;
	int GetCrewCount() const;

	bool operator == (const CFlightCompany& r) const;	
	friend ostream& operator << (ostream& out, const CFlightCompany& r); // operator << friend
	//** WE dont wanna be able to clone a company **//
	const CFlightCompany& operator = (const CFlightCompany& r) = delete;

private:
	string company_name;
	
	CCrewMember* crewMembers[MAX_CREW_MEMBERS];
	int numOfCrewMembers;
	
	CPlane* planes[MAX_PLANES];
	int numOfPlanes;

	CFlight* flights[MAX_FLIGHTS];
	int numOfFlights;
};


#endif //AIRPORT_CFLIGHTCOMPANY_H
