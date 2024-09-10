
#ifndef AIRPORT_CFLIGHTINFO_H
#define AIRPORT_CFLIGHTINFO_H
#include <string>

class CFlightInfo {
public:
	CFlightInfo(const string destination, int flight_number, int flight_time, int flight_distance);
	CFlightInfo(const CFlightInfo& other) = default; // Copy Constructor
	~CFlightInfo() = default;						 // Destructor
	const int getFlightNumber() const;
	void setFlightNumber(const int flight_number);
	const string getDestination() const;
	void SetDest(const string new_destination);
	const int getFlightTime() const;
	void setFlightTime(const int new_flight_time);
	const int getFlightDistance() const;
	void setFlightDistance(const int new_flight_distance);
	bool isEqual(int flight_number);
	void Print() const;

private:
	string destination;
	int flight_number;
	int flight_time;
	int flight_distance;
};


#endif //AIRPORT_CFLIGHTINFO_H
