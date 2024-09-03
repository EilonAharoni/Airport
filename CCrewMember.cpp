//
// Created by אילון אהרוני on 01/09/2024.
//
#include <iostream>
#include "CCrewMember.h"



CCrewMember::CCrewMember(const string& name,const CAddress& newAddress, int airTime) {
    this->name = name;
    this->address = new CAddress(newAddress);
    UpdateMinutes(airTime);

}
CCrewMember::CCrewMember(CCrewMember &other) {
    this->name = other.name;
    this->address = new CAddress(other.getAddress());
    UpdateMinutes(other.airTime);
}


bool CCrewMember::UpdateMinutes(int minuets) {
    if (minuets + this->airTime >= 0)
    {
        this->airTime+=minuets;
        return true;
    }
    return false;

}

int CCrewMember::getAirTime() const {
    return this->airTime;
}

void CCrewMember::setName(string &newName) {
    this-> name = newName;

}

string CCrewMember::getName() const{
    return this->name;
}

void CCrewMember::setAddress(CAddress &newAddress) {
    this->address->updateAddress(newAddress.getCity(),newAddress.getStreet(), newAddress.getHouseNumber());

}

CAddress CCrewMember::getAddress() const{
    return *this->address;
}

void CCrewMember::print() const{
    cout << "Name:" << this->name << ", " << "Air Time(Minutes):" << this->airTime << " , ";
    this->address->print();


}

bool CCrewMember::IsEqual(CCrewMember &other) const{
    return this->name == other.name;
}

CCrewMember::~CCrewMember() {
    delete address;
    address = nullptr;
}



