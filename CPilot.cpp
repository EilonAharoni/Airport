//
// Created by אילון אהרוני on 23/09/2024.
//

#include "CPilot.h"
#include <iostream>
CPilot::CPilot(string name, bool isCaptain, CAddress* address) : CCrewMember(name),captain(isCaptain)
{
    if (address)
        this->address = new CAddress(*address);
    else
        this->address = nullptr;
}


CPilot::CPilot(CPilot &other) : CCrewMember(other)
{
    this->address = new CAddress(*other.address);
    this->captain = other.captain;
}

const CPilot &CPilot::operator=(const CPilot &other){
    if(this != &other)
    {
        CCrewMember:operator=(other);
        delete address;
        address = new CAddress(*other.address);
        this->captain = other.captain;

    }
    return *this;
}


CPilot::~CPilot()
{
    delete address;
}

void CPilot::changeUniform()
{
    cout << name + "  this is the fifth time I get a new uniform – this is a waste of money!" << endl;
}

void CPilot::takeoff(int flightTime) {
    if(!captain)
        CCrewMember::takeoff(flightTime);
    else
        UpdateMinutes(flightTime + (int)((FACTOR*flightTime)));

}

void CPilot::print(ostream &os) const {
    os << "Pilot ";
    CCrewMember::print(os);
    if(captain)
        os << " a Captain";
    os << endl;
}

bool CPilot::operator==(const CPilot &other)
{
    if(this->address && other.address)
    {
        return CCrewMember::operator==(other) && this->address == other.address;
    }
    else if(!this->address && !other.address)
    {
        return CCrewMember::operator==(other);
    }

    return false;
}

void CPilot::comeToSimulator()
{
    cout << name +  " got the message will come soon" << endl;
}



