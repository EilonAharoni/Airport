//
// Created by אילון אהרוני on 01/09/2024.
//

#ifndef AIRPORT_CPLANE_H
#define AIRPORT_CPLANE_H

#include <string>

using namespace std;

class CPlane {
private:
    int planeId;
    string planeModel;
    int seats;

public:
    CPlane(const int id,const string& model,const int num);

    int getId() const;
    string getModel() const;
    int getNumOfSeats() const;

    bool isEqual(CPlane& other) const;

    void print() const;
};
#endif //AIRPORT_CPLANE_H
