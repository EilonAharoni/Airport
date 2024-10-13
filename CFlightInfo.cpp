

#include <iostream>

#include "CFlightInfo.h"

CFlightInfo::CFlightInfo(const string& destination, int flight_number, int flight_time, int flight_distance)
{

        setDest(destination);
		setFlightTime(flight_time);
		setFlightDistance(flight_distance);
        setFlightNumber(flight_number);

}

// setters
void CFlightInfo::setFlightNumber(const int flight_number)
{
    if (flight_number < 0)
		throw CCompStringException("Flight number must be a positive number");
    this->flight_number = flight_number;
}

void CFlightInfo::setDest(const string& new_destination)
{
    if (new_destination.empty())
        throw CCompStringException("Destination name cannot be empty");
    if (new_destination.length() > 30)
        throw CCompStringException("Destination name is too long (max 30)");
    
    this->destination = new_destination;
}

void CFlightInfo::setFlightTime(const int new_flight_time)
{
    if (new_flight_time < 0)
        throw CCompStringException("Flight time must be a positive number");
    
    this->flight_duration = new_flight_time;
}

void CFlightInfo::setFlightDistance(const int new_flight_distance)
{
    if (new_flight_distance < 0)
        throw CCompStringException("Flight distance must be a positive number");

    this->flight_distance = new_flight_distance;
}
// getters
const int CFlightInfo::getFNum() const
{
    return this->flight_number;
}

const string CFlightInfo::getDestination() const
{
    return this->destination;
}

const int CFlightInfo::getFlightTime() const
{
    return this->flight_duration;
}

const int CFlightInfo::getFlightDistance() const
{
    return this->flight_distance;
}


bool CFlightInfo::isEqual(int flight_number)
{
    return this->flight_number == flight_number;
}

const CFlightInfo& CFlightInfo::operator=(const CFlightInfo& r)
{
    if (this != &r)
	{
		this->flight_number = r.flight_number;
		this->destination = r.destination;
		this->flight_duration = r.flight_duration;
		this->flight_distance = r.flight_distance;
	}
	return *this;
}

bool CFlightInfo::operator==(const CFlightInfo& r) const
{
	return this->flight_number == r.flight_number;
}

bool CFlightInfo::operator!=(const CFlightInfo& r) const
{
	return !(*this == r);
}

CFlightInfo::operator int() const
{
    return this->flight_duration;
}

ostream& operator<<(ostream& out, const CFlightInfo& r)
{
    out << "Flight info:" << endl;
    out << "Flight number: " << r.flight_number  << endl;
    out << "Destination: " << r.destination  << endl;
    out << "Flight duration: " << r.flight_duration << " Minutes" <<endl;
    out << "Flight distance: " << r.flight_distance << " KM";
    return out; 
}
