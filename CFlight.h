

#ifndef AIRPORT_CFLIGHT_H
#define AIRPORT_CFLIGHT_H
#include "CFlightInfo.h"
#include "CPlane.h"
#include "CCrewMember.h"
#define MAX_CREW_MEMBERS 10

class CFlight {
private:
	CFlightInfo* flightInfo;
	CPlane* plane;
	CCrewMember* crewMembers[MAX_CREW_MEMBERS];
	int numOfCrewMembers;

public:
	CFlight(const CFlightInfo& flightInfo);
	CFlight(const CFlightInfo& flightInfo, CPlane* plane);
	CFlight(const CFlight& other);
	CFlight() = delete;
	~CFlight();

	void setPlane(CPlane* plane);
	CFlight &operator+(CCrewMember* crewMember);
	CFlight &operator=(const CFlight& r);
	bool operator == (const CFlight& r) const;
	friend ostream& operator <<(ostream& os, const CFlight& r);
	int getId() const;
};


#endif //AIRPORT_CFLIGHT_H
