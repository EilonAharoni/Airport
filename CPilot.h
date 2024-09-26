//
// Created by אילון אהרוני on 23/09/2024.
//

#ifndef AIRPORT_CPILOT_H
#define AIRPORT_CPILOT_H
#include "CCrewMember.h"
constexpr double FACTOR = 0.1;

class CPilot : public CCrewMember{
private:
    bool captain;
    CAddress* address;

public:
    CPilot(string name,bool isCaptain, CAddress* address = nullptr);
    CPilot(CPilot& other);
    ~CPilot() override;
    const CPilot& operator=(const CPilot& other);

    void comeToSimulator();
    void changeUniform();
    void takeoff(int flightTime);
    void print(ostream& os) const;
    bool operator==(const CPilot& other);
};


#endif //AIRPORT_CPILOT_H
