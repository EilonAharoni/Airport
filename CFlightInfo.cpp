//
// Created by אילון אהרוני on 01/09/2024.
//

using namespace std;
#include <iostream>

#include "CFlightInfo.h"

CFlightInfo::CFlightInfo(const string destination, int flight_number, int flight_time, int flight_distance)
        : flight_number(flight_number),

          destination(destination)
{
    setFlightDistance(flight_distance);
    setFlightDistance(flight_time);
}

CFlightInfo::CFlightInfo(const CFlightInfo& other) :
        flight_number(other.flight_number),
        destination(other.destination)
{
    setFlightDistance(other.flight_distance);
    setFlightTime(other.flight_time);
}

// setters
void CFlightInfo::setFlightNumber(const int flight_number)
{
    this->flight_number = flight_number;
}

void CFlightInfo::SetDest(const string new_destination)
{
    if (new_destination.empty())
    {
        cout << "Destination must not be empty" << endl;
        return;
    }
    this->destination = new_destination;
}

void CFlightInfo::setFlightTime(const int new_flight_time)
{
    if (new_flight_time < 0)
    {
        cout << "Flight time must be a positive number" << endl;
        return;
    }
    this->flight_time = new_flight_time;
}

void CFlightInfo::setFlightDistance(const int new_flight_distance)
{
    if (new_flight_distance < 0)
    {
        cout << "Flight distance must be a positive number" << endl;
        return;
    }
    this->flight_distance = new_flight_distance;
}
// getters
const int CFlightInfo::getFlightNumber() const
{
    return this->flight_number;
}

const string CFlightInfo::getDestination() const
{
    return this->destination;
}

const int CFlightInfo::getFlightTime() const
{
    return this->flight_time;
}

const int CFlightInfo::getFlightDistance() const
{
    return this->flight_distance;
}


bool CFlightInfo::isEqual(int flight_number)
{
    return this->flight_number == flight_number;
}

void CFlightInfo::Print() const
{
    cout << "Flight info: " << endl;
    cout << "Flight number: " << this->getFlightNumber() << endl;
    cout << "Destination: " << this->getDestination() << endl;
    cout << "Flight time: " << this->getFlightTime() << endl;
    cout << "Flight distance: " << this->getFlightDistance()<< endl;
}
