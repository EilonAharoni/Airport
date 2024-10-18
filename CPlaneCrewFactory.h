#ifndef AIRPORT_CPLANECREWFACTORY_H
#define AIRPORT_CPLANECREWFACTORY_H

enum PlaneType
{
	eRegular,
	eCargo,
	nofPlaneType
};

enum CrewType
{
	eHost,
	ePilot,
	nofCrewType
};

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "CPlane.h"
#include "Cargo.h"
#include "CCrewMember.h"
#include "CHost.h"
#include "CPilot.h"
#include "CFlightCompException.h"
#include "CFlightCompany.h"

using namespace std;

const string PlaneType_TITLE[nofPlaneType] = {"Regular","Cargo"};
const string CrewType_TITLE[nofCrewType] = {"Host","Pilot"};

class CPlane;
class CCrewMember;
class CFlightCompany;
class CAddress;
class CPlaneCrewFactory
{
public:
	// User input functions
	static void GetCompanyDataFromUser(CFlightCompany& comp);
	static PlaneType GetPlaneType(const CPlane* pPlane) noexcept;
	static CrewType GetCrewType(const CCrewMember* pCrew) noexcept;
	static int GetNumberFromUser(const string& prompt);
	static void GetCompanyName(CFlightCompany& comp);
	static CPlane* GetPlaneFromUser();
	static CCrewMember* GetCrewMemberFromUser();
	static CAddress* GetAddressFromUser();
	static CFlight* GetFlightFromUser(CFlightCompany& comp);
	// Helper functions
	static void SelectCrewMembersForFlight(CFlightCompany& comp, CFlight* pFlight);
	static CPlane* SelectPlaneForFlight(CFlightCompany& comp);
	// File functions
	static CCrewMember* GetCrewMemberFromFile(ifstream& inFile);
	static CPlane* GetPlaneFromFile(ifstream& inFile);
	static void cleanCin();
	template <typename T>
	static T getValidInput(const string& promp, T lowerBound, T upperBound);


private:
	CPlaneCrewFactory(void) { ;}
};

#endif //AIRPORT_CPLANECREWFACTORY_H