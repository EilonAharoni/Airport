#include "Cargo.h"

#include <utility>

CCargo::CCargo(int numOfSeats, string modelName, const float maxCargoWeight, const float maxCargoVolume) : CPlane(numOfSeats, std::move(modelName)),
maxCargoWeight(maxCargoWeight), maxCargoVolume(maxCargoVolume), currentCargoWeight(0), currentCargoVolume(0)
{
}

bool CCargo::load(float volume, float weight)
{
	float currentWeight = this->currentCargoWeight;
	float currentVolume = this->currentCargoVolume;
	float maxWeight = this->maxCargoWeight;
	float maxVolume = this->maxCargoVolume;
	if (currentVolume + volume <= maxVolume && currentWeight + weight <= maxWeight)
	{
		this->currentCargoVolume += volume;
		this->currentCargoWeight += weight;
		return true;
	}
	return false;
}

void CCargo::takeOff(int minutes) const
{
	cout << "Need to add " << minutes << " minutes to my log book" << endl;
}

void CCargo::print(ostream& out) const
{
	CPlane::print();
	cout <<"Cargo Weight: " << this->currentCargoWeight << endl << "Cargo Volume: " << this->currentCargoVolume << endl;
}

