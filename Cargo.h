
#ifndef AIRPORT_CCARGO_H
#define AIRPORT_CCARGO_H

using namespace std;
#include <iostream>
#include "CPlane.h"

////To check cargo code in main
//cout << "Checking Cargo Plane" << endl;
//CCargo c1(100, "Boeing737", 120, 100);
//c1.print(cout);
//c1.load(50, 20);
//cout << "After loading 50kg and 20m3" << endl;
//c1.print(cout);

class CCargo : public CPlane
{
public:
	CCargo(int numOfSeats, string modelName, const float maxCargoWeight, const float maxCargoVolume);
	bool load(float volume, float weight);

	//Called by flight class
	void takeOff(int minutes) const; 

	void print(ostream& out) const; 

private:
	float maxCargoWeight;
	float currentCargoWeight;
	float maxCargoVolume;
	float currentCargoVolume;
};

#endif //AIRPORT_CCARGO_H




