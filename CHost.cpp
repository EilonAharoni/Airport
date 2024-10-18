#include "CHost.h"
#include "CPlaneCrewFactory.h"
#include <fstream>
#include <utility>

CHost::CHost(string name, eType type, int minutes) : CCrewMember(std::move(name), minutes)
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
    ///write to console
    if (typeid(os) != typeid(ofstream))
    {
        cout << "Host " << types[this->type] << endl;
        CCrewMember::print(os);
        cout << endl;
    }///write to file
    else
    {
        os << 0 << " ";
        CCrewMember::print(os);
        os << " "  << (int)type;
    }
}





