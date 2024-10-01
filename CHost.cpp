//
// Created by אילון אהרוני on 23/09/2024.
//

#include "CHost.h"
#include <iostream>
#include <utility>

CHost::CHost(string name, eType type) : CCrewMember(std::move(name)) ,type(type)
{
}

CHost::CHost(CHost &other) : CCrewMember(other), type(other.type)
{
}


void CHost::changeUniform()
{
    cout << name + ": I think the new uniform is very nice!" << endl;
}

void CHost::setType(CHost::eType type) {
    this->type = type;
}

CHost::eType CHost::getType() const {
    return this->type;
}

void CHost::getHolidayGift()
{
    CCrewMember::getHolidayGift();
    cout << "I wasn't expecting it" << endl;

}

void CHost::print(ostream &os) const {
    cout << "Host " << types[this->type] << endl;
    CCrewMember::print(os);
    cout << endl;

}



