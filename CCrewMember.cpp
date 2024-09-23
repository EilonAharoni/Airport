
#include <iostream>
#include <utility>
#include "CCrewMember.h"
//int CCrewMember::START_ID = 1000;
//int CCrewMember::SERIAL_ID = START_ID;
CCrewMember::CCrewMember(string name, int airTime) :name(std::move(name))
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

//void CCrewMember::setAddress(CAddress& newAddress) {
//    this->address.updateAddress(newAddress.getCity(), newAddress.getStreet(), newAddress.getHouseNumber());
//
//}

//CAddress CCrewMember::getAddress() const {
//    return this->address;
//}

void CCrewMember::print(ostream& os) const {
    os << "Name:" << this->name << ", " << "Air Time(Minutes):" << this->airTime;// << " , ";
 //   this->address.Print();
}

bool CCrewMember::IsEqual(CCrewMember& other) const {
    return this->name == other.name;
}

bool CCrewMember::operator==(const CCrewMember &other) {
    return (this->name == other.name);
}

const CCrewMember &CCrewMember::operator=(const CCrewMember &other) {
    if(this != &other) // prevent unnecessary duplication
    {
        this->name = other.name;
        this->airTime = other.airTime;
    }
    return *this;
}

ostream &operator<<(ostream &os, const CCrewMember &crewMember)
{
    os << "Name:" << crewMember.name << ", " << "Air Time(Minutes):" << crewMember.airTime << ", Address: ";// << crewMember.address;
    return os;
}

bool operator+=(CCrewMember& crewMember, int minutes)
{
    if (crewMember.getAirTime() + minutes >= 0)
    {
		crewMember.UpdateMinutes(minutes);
		return true;
	}
    return false;
}

void CCrewMember::takeoff(int flightTime)
{
    UpdateMinutes(flightTime);
}

void CCrewMember::getHolidayGift()
{
    cout << name + " thanking the company for receiving the holiday gift." << endl;
}

//const int CCrewMember::getId() const
//{
//    return id;
//}



