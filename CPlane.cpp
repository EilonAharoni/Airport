//
// Created by אילון אהרוני on 01/09/2024.
//
#include <iostream>
#include "CPlane.h"



using namespace std;

CPlane::CPlane(const int id,const string& model,const int num) {
    this->planeId = id;
    this->planeModel = model;
    this->seats = num;
}

int CPlane::getId() const {
    return this->planeId;
}

string CPlane::getModel() const {
    return this->planeModel;
}

int CPlane::getNumOfSeats() const {
    return this->seats;
}

bool CPlane::isEqual(CPlane &other) const {
    return this->planeId == other.getId();
}

void CPlane::print() const {
    cout << "Plane Number: " << this->planeId << " Model: " << this->getModel() << " seats: " << this->seats << endl;

}
