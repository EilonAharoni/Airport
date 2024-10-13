
#ifndef AIRPORT_CPLANE_H
#define AIRPORT_CPLANE_H

#include <string>
#include "CFlightCompException.h"
constexpr int START_ID = 100;
using namespace std;

class CPlane
{
private:
    static int SERIAL_ID; //start from 100
    int planeId;
    string planeModel;
    int seats;


public:
    CPlane(const int num, string model);
    CPlane(const CPlane& other) = default; //copy constructor
    virtual ~CPlane() = default;                   //destructor
    CPlane() = delete;

    const int getId() const;
    const string getModel() const;
    const int getNumOfSeats() const;

    void setModelName(const string& model);
    void setNumOfSeats(const int num);

    const CPlane& operator++();
    CPlane operator++(int);
    friend ostream& operator<<(ostream& os,const CPlane& plane);
    const CPlane& operator=(const CPlane& other);
    bool operator==(const CPlane& other) const;

    bool isEqual(CPlane& other) const;
    virtual void print(ostream& os) const;
};
#endif //AIRPORT_CPLANE_H
