//
// Created by אילון אהרוני on 12/09/2024.
//

#ifndef AIRPORT_CFLIGHT_H
#define AIRPORT_CFLIGHT_H
#include "CFlightInfo.h"
#include "CPlane.h"
#include "CCrewMember.h"
#define MAX_CREW_MEMBERS 10

class CFlight {
	friend ostream& operator <<(ostream& os, const CFlight& r);
private:
	CFlightInfo* flightInfo;
	CPlane* plane;
	CCrewMember* crewMembers[MAX_CREW_MEMBERS];
	int numOfCrewMembers;

public:
	CFlight(const CFlightInfo& flightInfo);
	CFlight(const CFlightInfo& flightInfo, CPlane* plane);
	CFlight(const CFlight& other);
	~CFlight();

	void setPlane(CPlane* plane);
	CFlight &operator+(CCrewMember* crewMember);
	CFlight &operator=(const CFlight& r);/////changed
	bool operator == (const CFlight& r) const;////changed
	////
	int getId() const;
    ////
};


#endif //AIRPORT_CFLIGHT_H
