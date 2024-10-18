//
// Created by אילון אהרוני on 23/09/2024.
//

#ifndef AIRPORT_CHOST_H
#define AIRPORT_CHOST_H
#include "CCrewMember.h"

class CHost :public CCrewMember{
public:
    enum eType{eRegular,eSuper,eCalcelan};
    const string types[3]{"Regular","Super","Calcelan"};
    CHost(string name, eType type, int minutes);
    CHost(CHost& other);
    CHost(ifstream &inFile);

    void setType(eType type);
    eType getType() const;
    void getHolidayGift();
    void changeUniform();
    void print(ostream& os) const;

private:
    eType type;

};


#endif //AIRPORT_CHOST_H
