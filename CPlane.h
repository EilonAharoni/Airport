
#ifndef AIRPORT_CPLANE_H
#define AIRPORT_CPLANE_H

#include <string>

using namespace std;

class CPlane
{
private:
    const int planeId;
    string planeModel;
    const int seats;

public:
    CPlane(const int id, const int num, string model);
    CPlane(const CPlane& other) = default; //copy constructor
    ~CPlane() = default;                   //destructor    
    const int getId() const;
    const string getModel() const;
    const int getNumOfSeats() const;

    bool isEqual(CPlane& other) const;

    void print() const;
};
#endif //AIRPORT_CPLANE_H
