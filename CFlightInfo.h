
#ifndef AIRPORT_CFLIGHTINFO_H
#define AIRPORT_CFLIGHTINFO_H
#include <string>
#include "CFlightCompException.h"
using namespace std;

class CFlightInfo {
	friend ostream& operator << (ostream& out, const CFlightInfo& r); 
public:
	CFlightInfo() = delete;
    CFlightInfo(ifstream& inFile);
	CFlightInfo(const string& destination, int flight_number, int flight_duration, int flight_distance);
	CFlightInfo(const CFlightInfo& other) = default; // Copy Constructor
	~CFlightInfo() = default;						 // Destructor
	const int getFNum() const;
	void setFlightNumber(const int flight_number);
	const string getDestination() const;
	void setDest(const string& new_destination);
	const int getFlightTime() const;
	void setFlightTime(const int new_flight_time);
	const int getFlightDistance() const;
	void setFlightDistance(const int new_flight_distance);
	bool isEqual(int flight_number);
	const CFlightInfo& operator = (const CFlightInfo& r);
	bool operator == (const CFlightInfo& r) const;
	bool operator != (const CFlightInfo& r) const;
	operator int() const;

private:
	string destination;
	int flight_number;
	int flight_duration;
	int flight_distance;
};


#endif //AIRPORT_CFLIGHTINFO_H
