
#include <iostream>
#include <utility>
#include "CCrewMember.h"


CCrewMember::CCrewMember(string  name, const CAddress& newAddress, int airTime) :
    name(std::move(name)), address(newAddress)
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



