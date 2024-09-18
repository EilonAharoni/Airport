
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
    ~CCrewMember() = default;                  // destructor

    //Getters
    const int getAirTime() const;
    const int getId() const;
    CAddress getAddress() const;
    const string getName() const;
    // Setters
    void setName(const string& newName);
    void setAddress(CAddress& newAddress);

    void print() const;
    bool UpdateMinutes(int minutes);
    friend ostream& operator<<(ostream& os,const CCrewMember& crewMember);
    const CCrewMember& operator=(const CCrewMember& other);
    friend bool operator+=(CCrewMember& crewMember, int minutes);
    bool operator==(const CCrewMember& other);
    bool IsEqual(CCrewMember& other) const;
    static int START_ID; // start from 1000
};


#endif //AIRPORT_CCREWMEMBER_H
