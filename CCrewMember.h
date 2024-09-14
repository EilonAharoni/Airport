
#ifndef AIRPORT_CCREWMEMBER_H
#define AIRPORT_CCREWMEMBER_H
#include "CAddress.h"
#include <string>

using namespace std;

class CCrewMember
{
private:
    static int SERIAL_ID;
    int id;
    string name;
    int airTime = 0; // in minutes
    CAddress address;

public:
    CCrewMember(string name, const CAddress& address, int airTime = 0);
    CCrewMember(CCrewMember& other) = default; // copy constructor
    CCrewMember() = delete;
    const CCrewMember& operator=(const CCrewMember& other);
    ~CCrewMember() = default;                  // destructor
    bool UpdateMinutes(int minutes);
    const CCrewMember& operator+=(int minutes);

    const int getAirTime() const;
    const int getId() const;
    void setName(const string& newName);
    const string getName() const;

    void setAddress(CAddress& newAddress);
    CAddress getAddress() const;

    void print() const;
    friend ostream& operator<<(ostream& os,const CCrewMember& crewMember);
    bool IsEqual(CCrewMember& other) const;
    bool operator==(const CCrewMember& other);
};


#endif //AIRPORT_CCREWMEMBER_H
