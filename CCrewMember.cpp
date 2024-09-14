
#include <iostream>
#include <utility>
#include "CCrewMember.h"

int CCrewMember::SERIAL_ID = 1000;
CCrewMember::CCrewMember(string  name, const CAddress& newAddress, int airTime) :
    id(SERIAL_ID++),name(std::move(name)), address(newAddress)
{
    UpdateMinutes(airTime);
}

bool CCrewMember::UpdateMinutes(int minutes) {
    if (minutes + this->airTime >= 0)
    {
        this->airTime += minutes;
        return true;
    }
    return false;

}

const int CCrewMember::getAirTime() const {
    return this->airTime;
}

void CCrewMember::setName(const string& newName) {
    this->name = newName;

}

const string CCrewMember::getName() const {
    return this->name;
}

void CCrewMember::setAddress(CAddress& newAddress) {
    this->address.updateAddress(newAddress.getCity(), newAddress.getStreet(), newAddress.getHouseNumber());

}

CAddress CCrewMember::getAddress() const {
    return this->address;
}

void CCrewMember::print() const {
    cout << "Name:" << this->name << ", " << "Air Time(Minutes):" << this->airTime << " , ";
    this->address.Print();


}

bool CCrewMember::IsEqual(CCrewMember& other) const {
    return this->name == other.name;
}

const CCrewMember &CCrewMember::operator+=(int minutes) {
    if (airTime + minutes >= 0)
        airTime+=minutes;// air Time must be >= 0;
    return *this;
}

bool CCrewMember::operator==(const CCrewMember &other) {
    return (this->name == other.name && this->id == other.id);
}

const CCrewMember &CCrewMember::operator=(const CCrewMember &other) {
    if(this != &other) // prevent unnecessary duplication
    {
        this->name = other.name;
        this->airTime = other.airTime;
        this->address = other.address;
        this->id = other.id;
    }
    return *this;
}

ostream &operator<<(ostream &os, const CCrewMember &crewMember) {
    os << "Name:" << crewMember.name << ", " << "Air Time(Minutes):" << crewMember.airTime << " , ";
}

const int CCrewMember::getId() const {
    id;
}



