#include <fstream>
#include <utility>
#include "CPlane.h"

using namespace std;
int CPlane::SERIAL_ID = START_ID;

CPlane::CPlane(const int num, string model) : planeId(SERIAL_ID++)
{
	setNumOfSeats(num);
	setModelName(model);
}

CPlane::CPlane(ifstream& inFile)
{
    static bool isFirstPlane = true;
    if (isFirstPlane) // Last ID
    {
		inFile >> SERIAL_ID;
        setPlaneLastId(SERIAL_ID);
		isFirstPlane = false;
	}
    inFile >> this->planeId >> this->planeModel >> this->seats;
}

void CPlane::setModelName(const string& model)
{
    if(model.empty())
		throw CCompStringException("Model name cannot be empty");
    this->planeModel = model;
}

void CPlane::setNumOfSeats(const int num)
{
	if(num < 0)
		throw CCompStringException("Number of seats must be a positive number");
	this->seats = num;
}

void CPlane::setPlaneLastId(int id)
{
    SERIAL_ID = id;
}

const int CPlane::getId() const 
{
    return this->planeId;
}

const string CPlane::getModel() const 
{
    return this->planeModel;
}

const int CPlane::getNumOfSeats() const 
{
    return this->seats;
}

bool CPlane::isEqual(CPlane& other) const 
{
    return this->planeId == other.planeId;
}

void CPlane::print(ostream& os) const
{
    static bool isFirstPlane = true;  // Static to persist between calls
    if (!dynamic_cast<ofstream*>(&os))  // Check if os is an ofstream
    {
        os << "Plane ID: " << this->planeId << " Model: " << this->getModel() << " seats: " << this->seats << endl;
    }
    else // write to file
    {
        if (isFirstPlane)
        {
            os << SERIAL_ID << " ";  
            isFirstPlane = false;  
        }
        os << this->planeId << " " << this->getModel() << " " << this->seats << endl;
    }
}

const CPlane &CPlane::operator++() 
{
    this->seats++;
    return *this;
}

CPlane CPlane::operator++(int) 
{
    return CPlane(seats++,planeModel);
}

ostream &operator<<(ostream &os, const CPlane &plane)
{
    plane.print(os);
    return os;
}

const CPlane& CPlane::operator=(const CPlane &other) 
{
    if(this != &other)// prevent unnecessary duplication
    {
       this->planeId = other.planeId;
       this->seats = other.seats;
       this->planeModel = other.planeModel;
    }
    return *this;
}

bool CPlane::operator==(const CPlane &other) const 
{
    return this->planeId == other.planeId;
}




