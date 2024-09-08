//
// Created by אילון אהרוני on 01/09/2024.
//

#ifndef AIRPORT_CFLIGHTINFO_H
#define AIRPORT_CFLIGHTINFO_H

#include <string>


class CFlightInfo {
public:
    CFlightInfo(const string destination, int flight_number, int flight_time, int flight_distance);
    CFlightInfo(const CFlightInfo& other); // Copy Constructor
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
