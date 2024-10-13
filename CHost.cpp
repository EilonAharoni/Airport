//
// Created by אילון אהרוני on 23/09/2024.
//

#include "CHost.h"
#include <fstream>
#include <utility>

CHost::CHost(string name, eType type) : CCrewMember(std::move(name))
{
    setType(type);
}

CHost::CHost(CHost &other) : CCrewMember(other), type(other.type)
{
}
CHost::CHost(ifstream &inFile) : CCrewMember(inFile){

    int typeInt;
    inFile >> typeInt;  // Read the integer representing the enum
    type = static_cast<eType>(typeInt);  // Cast the integer to the enum
}

void CHost::changeUniform()
{
    cout << name + ": I think the new uniform is very nice!" << endl;
}

void CHost::setType(CHost::eType type) {
    if(type  < eRegular || type > eCalcelan + 1 )
        throw CCompLimitException(type);
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





