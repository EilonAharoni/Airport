//
// Created by אילון אהרוני on 01/09/2024.
//

#ifndef AIRPORT_CCREWMEMBER_H
#define AIRPORT_CCREWMEMBER_H
#include "CAddress.h"
#include <string>

using namespace std;

class CCrewMember {
private:
    string name;
    int airTime; // in minutes
    CAddress* address;

public:
    CCrewMember(const string& name,const CAddress& address,int airTime = 0);

    bool UpdateMinutes(int minuets);
    int getAirTime() const;

    void setName(string& newName);
    string getName() const;

    void setAddress(CAddress& newAddress);
    CAddress getAddress() ;

    void print();

    bool IsEqual(CCrewMember& other);

    ~CCrewMember();
};


#endif //AIRPORT_CCREWMEMBER_H
