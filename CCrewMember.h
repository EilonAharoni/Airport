
#ifndef AIRPORT_CCREWMEMBER_H
#define AIRPORT_CCREWMEMBER_H
#include "CAddress.h"
#include "CFlightCompException.h"
#include <string>

using namespace std;

class CCrewMember
{
protected:
    string name;
    int airTime = 0; // in minutes


public:
    CCrewMember(string name, int airTime = 0);
    CCrewMember(CCrewMember& other) = default; // copy constructor
    CCrewMember() = delete;
    virtual ~CCrewMember() = default;                  // destructor

    //Getters
    const int getAirTime() const;
//    CAddress getAddress() const;
    const string getName() const;
    // Setters
    void setName(const string& newName);
//    void setAddress(CAddress& newAddress);


    bool UpdateMinutes(int minutes);
    friend ostream& operator<<(ostream& os,const CCrewMember& crewMember);
    const CCrewMember& operator=(const CCrewMember& other);
    friend bool operator+=(CCrewMember& crewMember, int minutes);

    bool IsEqual(CCrewMember& other) const;

    ////virtual func
    virtual void changeUniform() = 0;
    virtual bool operator==(const CCrewMember& other);
    virtual void print(ostream& os) const;
    virtual void takeoff(int flightTime);
    virtual void getHolidayGift();

};


#endif //AIRPORT_CCREWMEMBER_H
