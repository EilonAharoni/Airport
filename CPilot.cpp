//
// Created by אילון אהרוני on 23/09/2024.
//

#include "CPilot.h"
#include <fstream>
CPilot::CPilot(string name, bool isCaptain, CAddress* address) : CCrewMember(name),captain(isCaptain)
{
    if (address)
        this->address = new CAddress(*address);
    else
        this->address = nullptr;
}


CPilot::CPilot(CPilot &other) : CCrewMember(other)
{
    if (other.address)
        this->address = new CAddress(*other.address);
    else
        this->address = nullptr;
    this->captain = other.captain;
}
CPilot::CPilot(ifstream &inFile) : CCrewMember(inFile)
{
    int thereAdress;
    inFile >> thereAdress;
    if(thereAdress == 1)
    {
        int num;
        string street,city;
        inFile >> num >> street >> city;
        address = new CAddress(num,street,city);
    } else
        this->address = nullptr;

    int intCaptain;
    inFile >> intCaptain;
    captain = intCaptain;
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
    address = nullptr;
}

void CPilot::changeUniform()
{
    cout << name + ": this is the fifth time I get a new uniform - this is a waste of money!" << endl;
}

void CPilot::takeoff(int flightTime) {
    if(!captain)
        CCrewMember::takeoff(flightTime);
    else
        UpdateMinutes(flightTime + (int)((FACTOR*flightTime)));

}

void CPilot::print(ostream &os) const {
    os << "Pilot" << endl;
    CCrewMember::print(os);
    if(captain)
        os << " a Captain";
    if (address)
        os << "\nAddress:" << *address;
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
    cout << "Pilot " + name +  " got the message will come soon" << endl;
}



