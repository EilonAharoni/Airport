
#ifndef AIRPORT_CFLIGHTCOMPANY_H
#define AIRPORT_CFLIGHTCOMPANY_H
using namespace std;
#include <string>
#include "CCrewMember.h"
#include "CPlane.h"
#include "CFlight.h"

#define MAX_PLANES 10
#define MAX_FLIGHTS 10

class CFlightCompany
{
	friend ostream& operator << (ostream& out, const CFlightCompany& r); // operator << friend
public:
	CFlightCompany(const string name);
	CFlightCompany(const CFlightCompany& other) = delete; // Copy Constructor
	~CFlightCompany();									  // Destructor
    CFlightCompany() = delete;
	const string GetName() const;
	void SetName(const string name);

	void Print(ostream& out) const; // Print function

	// Part 2
	CCrewMember* GetCrewMemberByID(int id) const;
	CFlight* GetFlightByID(int id) const;
	CPlane* GetPlane(int index) const;

	bool AddCrewMember(CCrewMember& crewMember);
	bool AddPlane(CPlane& plane);
	bool AddFlight(CFlight& flight);
	bool AddCrewToFlight(int flightID, int crewMemberID) const;

	const CFlightCompany& operator = (const CFlightCompany& r);
	bool operator == (const CFlightCompany& r) const;	


private:
	string company_name;
	
	// part 2   ////// maybe it need to be arrayed of elements and not pointers (clones)?
	CCrewMember* crewMembers[MAX_CREW_MEMBERS];
	int numOfCrewMembers;
	
	CPlane* planes[MAX_PLANES];
	int numOfPlanes;

	CFlight* flights[MAX_FLIGHTS];
	int numOfFlights;
};


#endif //AIRPORT_CFLIGHTCOMPANY_H
