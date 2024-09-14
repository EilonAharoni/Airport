
#ifndef AIRPORT_CFLIGHTCOMPANY_H
#define AIRPORT_CFLIGHTCOMPANY_H
using namespace std;
#include <string>
#include "CCrewMember.h"
#include "CPlane.h"
#include "CFlight.h"

#define MAX_CREW_MEMBERS 10
#define MAX_PLANES 10
#define MAX_FLIGHTS 10

class CFlightCompany
{
	friend ostream& operator << (ostream& out, const CFlightCompany& r); // operator << friend
public:
	CFlightCompany(const string name);
	CFlightCompany(const CFlightCompany& other) = default; // Copy Constructor
	~CFlightCompany() = default;						   // Destructor
	const string GetName() const;
	void SetName(const string name);

	void Print(ostream& out) const; // Print function

	// Part 2
	CCrewMember* GetCrewMemberByID(int id) const;
	CFlight* GetFlightByID(int id) const;
	CPlane* GetPlane(int index) const;

	bool AddCrewMember(const CCrewMember& crewMember);
	bool AddPlane(const CPlane& plane);
	bool AddFlight(const CFlight& flight);
	bool AddCrewToFlight(int crewMemberID, int flightID);

	const CFlightCompany& operator = (const CFlightCompany& r);
	bool operator == (const CFlightCompany& r) const;	


private:
	string company_name;
	
	// part 2
	CCrewMember* crewMembers[MAX_CREW_MEMBERS]; 
	int numOfCrewMembers;
	
	CPlane* planes[MAX_PLANES]; 
	int numOfPlanes;

	CFlight* flights[MAX_FLIGHTS]; 
	int numOfFlights;
};


#endif //AIRPORT_CFLIGHTCOMPANY_H
