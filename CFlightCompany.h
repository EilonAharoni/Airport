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
	// ctor's and dtor
	CFlightCompany(const string& name);
	CFlightCompany(const CFlightCompany& other) = delete; // Copy Constructor
    CFlightCompany(const string fileName, int i);
	// file ctor helpers
	void initializeCrewMembersFromFile(ifstream& inFile);
	void initializePlanesFromFile(ifstream& inFile);
	void initializeFlightsFromFile(ifstream& inFile);
	void initializeFlight(ifstream& inFile, int index);
    ~CFlightCompany();									  // Destructor
    CFlightCompany() = delete;

	// Getters
	const string getName() const;
	CCrewMember* GetCrewMember(int index) const;
    int getCrewMemberIndex(CCrewMember& crew) const;
	CFlight* GetFlightByID(int id) const;
    int GetCargoCount() const;
    CPlane* GetPlaneByID(int id) const;
	int GetCrewCount() const;

	// Setters
	void setName(const string& name);

	// Adders
	bool AddCrewMember(CCrewMember& crewMember);
	bool AddPlane(CPlane& plane);
	bool AddFlight(CFlight& flight);
	bool AddCrewToFlight(int flightID, int crewMemberIndex) const;

	// Operators overloading
	CPlane& operator[](int index) const;
	bool operator == (const CFlightCompany& r) const;
	friend ostream& operator << (ostream& out, const CFlightCompany& r); // operator << friend
	const CFlightCompany& operator = (const CFlightCompany& r) = delete; 	//** WE dont wanna be able to clone a company **//

	// Printers
	void PrintCrewMembers(ostream& out, const CFlightCompany& r) const;
	void PrintPlanes(ostream& out, const CFlightCompany& r) const;
	void PrintFlights(ostream& out, const CFlightCompany& r) const;
	void print(ostream& out) const; 

	// File handling
    void SaveToFile(string& fileName) const;

    void CrewGetPresent() const;
    void PilotsToSimulator() const;
    void CrewGetUniform() const;
	void clear();


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
