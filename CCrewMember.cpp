
//#include <iostream>
#include <fstream>
#include <ostream>
#include <utility>
#include "CCrewMember.h"
//int CCrewMember::START_ID = 1000;
//int CCrewMember::SERIAL_ID = START_ID;
CCrewMember::CCrewMember(string name, int airTime)
{

        setName(name);
        UpdateMinutes(airTime);

}

CCrewMember::CCrewMember(ifstream& inFile)
{
    inFile >> this->name >> this->airTime;
}

bool CCrewMember::UpdateMinutes(int minutes) {
    if (minutes + this->airTime >= 0)
    {
        this->airTime += minutes;
        return true;
    }
    throw CCompStringException("Air time must be a positive number");
    return false;
}

const int CCrewMember::getAirTime() const 
{
	return this->airTime;
}

void CCrewMember::setName(const string& newName) {
    if(newName.empty())
		throw CCompStringException("Name cannot be empty");
    this->name = newName;
}

const string CCrewMember::getName() const {
    return this->name;
}

void CCrewMember::print(ostream& os) const {
    if (typeid(os) == typeid(ofstream))
        os << this->name << " " << this->airTime;
    else
        os << "Name:" << this->name << ", " << "Air Time(Minutes):" << this->airTime;
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
    crewMember.print(os);
    return os;
}

bool operator+=(CCrewMember& crewMember, int minutes)
{
    try 
    {
		crewMember.UpdateMinutes(minutes);
	}
    catch (CCompStringException& e) {
		e.show();
        return false;
	}
	return true;

}

void CCrewMember::takeoff(int flightTime)
{
    try 
    {
		UpdateMinutes(flightTime);
	}
    catch (CCompStringException& e) {
		e.show();
	}
}

void CCrewMember::getHolidayGift()
{
    cout << name + " thanking the company for receiving the holiday gift." << endl;
}

//const int CCrewMember::getId() const
//{
//    return id;
//}



