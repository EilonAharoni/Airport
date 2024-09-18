
#include <iostream>
#include "CAddress.h"
#include <string>

CAddress::CAddress(const int houseNum, const string& street, const string& city) 
{
    updateAddress(city, street, houseNum);
}

void CAddress::updateAddress(const string& newCity, const string& newStreet, int houseNum) 
{

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

const string CAddress::getCity() const 
{
    return this->city;
}

const string CAddress::getStreet() const 
{
    return this->street;
}

const int CAddress::getHouseNumber() const 
{
    return this->houseNumber;
}

void CAddress::Print() const 
{
    cout << this->street << ", " << this->houseNumber << ", " << this->city << endl;
}

ostream &operator<<(ostream &os,const CAddress &address) 
{
    os << address.street << ", " << address.houseNumber << ", " << address.city;
    return os;
}
istream &operator>>(istream &in,  CAddress &address) 
{
    cout << "Enter street (multiple words allowed): ";
    getline(in,address.street);

    cout << "Enter city (multiple words allowed): ";
    getline(in, address.city);

    cout << "Enter house number: ";
    in >> address.houseNumber;
    if (address.houseNumber < 0)
    {
        // invalid house number
		address.houseNumber = 0;
	}
    cin.sync();
    return in;
}

bool CAddress::operator==(const CAddress &other) const 
{
    return (this->city == other.city && this->street == other.street && this->houseNumber == other.houseNumber);
}

bool CAddress::operator!=(const CAddress &other) const 
{
    return !(*this == other);
}

string CAddress::GetCurrentAddress() const 
{
   string address = this->street;
   address+= ", ";
   address += to_string(this->houseNumber);
   address+= ", ";
   address += this->city;
    return address;
}

const CAddress &CAddress::operator=(const CAddress &other) 
{
    if(this != &other)// prevent unnecessary duplication
    {
        this->city = other.city;
        this->street = other.street;
        this->houseNumber = other.houseNumber;
    }
    return *this;
}
