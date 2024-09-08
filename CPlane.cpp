//
// Created by אילון אהרוני on 01/09/2024.
//
#include <iostream>
#include <utility>
#include "CPlane.h"



using namespace std;

CPlane::CPlane(const int id,const int num ,string  model) : planeId(id),planeModel(std::move(model)),seats(num)
{

}

const int CPlane::getId() const {
    return this->planeId;
}

const string CPlane::getModel() const {
    return this->planeModel;
}

const int CPlane::getNumOfSeats() const {
    return this->seats;
}

bool CPlane::isEqual(CPlane &other) const {
    return this->planeId == other.getId();
}

void CPlane::print() const {
    cout << "Plane Number: " << this->planeId << " Model: " << this->getModel() << " seats: " << this->seats << endl;

}
