
#ifndef AIRPORT_CCARGO_H
#define AIRPORT_CCARGO_H


#include <iostream>
#include "CPlane.h"

class CCargo : public CPlane
{
public:
	CCargo(int numOfSeats, string modelName,const float maxCargoWeight, const float maxCargoVolume);
	bool load(float weight, float volume);

	//Called by flight class
	void takeOff(int minutes) const;
	void setMaxCargoWeight(float weight);
	void setMaxCargoVolume(float volume);

	void print(ostream& out) const override;

private:
	float maxCargoWeight;
	float currentCargoWeight;
	float maxCargoVolume;
	float currentCargoVolume;
};

#endif //AIRPORT_CCARGO_H




