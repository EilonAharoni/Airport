
#ifndef AIRPORT_CCREWMEMBER_H
#define AIRPORT_CCREWMEMBER_H
#include "CAddress.h"
#include <string>

using namespace std;

class CCrewMember
{
private:
    string name;
    int airTime = 0; // in minutes
    CAddress address;

public:
    CCrewMember(string name, const CAddress& address, int airTime = 0);
    CCrewMember(CCrewMember& other) = default; // copy constructor
    ~CCrewMember() = default;                  // destructor
    bool UpdateMinutes(int minutes);
    const int getAirTime() const;

    void setName(const string& newName);
    const string getName() const;

    void setAddress(CAddress& newAddress);
    CAddress getAddress() const;

    void print() const;

    bool IsEqual(CCrewMember& other) const;
};


#endif //AIRPORT_CCREWMEMBER_H
