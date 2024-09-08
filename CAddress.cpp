//
// Created by אילון אהרוני on 01/09/2024.
//
#include <iostream>
#include "CAddress.h"

CAddress::CAddress(const int houseNum, const string& street, const string& city) {
    updateAddress(city, street,houseNum);
}
CAddress::CAddress(const CAddress &other) {
    updateAddress(other.city,other.street,other.houseNumber);

}

void CAddress::updateAddress(const string& newCity,const string& newStreet,int houseNum) {

    if (newStreet.empty() || newCity.empty())
    {
        cout << "Must not be empty" << endl;
        return;
    }
    this->city = newCity;


    this->street = newStreet;

    if (houseNum > 0)
        this->houseNumber = houseNum;

}

const string CAddress::getCity() const{
    return this->city;
}

const string CAddress::getStreet() const{
    return this->street;
}

const int CAddress::getHouseNumber() const {
    return this->houseNumber;
}

void CAddress::print() const{
    cout << this->street << ", " << this->houseNumber << ", " << this->city << endl;

}




