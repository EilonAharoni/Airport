#include "Cargo.h"
#include <utility>
#include <fstream>

CCargo::CCargo(
	int numOfSeats, 
	string modelName, 
	const float maxCargoWeight,
	const float maxCargoVolume) : currentCargoVolume(0), currentCargoWeight(0), CPlane(numOfSeats, std::move(modelName))
{
	setMaxCargoWeight(maxCargoWeight);
	setMaxCargoVolume(maxCargoVolume);
}

CCargo::CCargo(ifstream& inFile) : CPlane(inFile)
{
    inFile >> this->maxCargoVolume >> this->maxCargoWeight >> this->currentCargoVolume >> this->currentCargoWeight;
}

void CCargo::setMaxCargoWeight(float weight)
{
	if(weight < 0)
		throw CCompStringException("Weight cannot be negative");
	this->maxCargoWeight = weight;
}

void CCargo::setMaxCargoVolume(float volume)
{
	if(volume < 0)
		throw CCompStringException("Volume cannot be negative");
	this->maxCargoVolume = volume;
}

bool CCargo::load(float weight, float volume)
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
	throw CCompStringException("Cargo is too heavy or too big...");
	return false;
}

void CCargo::takeOff(int minutes) const
{
	cout << "Need to add " << minutes << " minutes to my log book" << endl;
}

void CCargo::print(ostream& out) const
{
    CPlane::print(out);
    if (typeid(out) != typeid(ofstream))
    {
        out << "Cargo M_vol: " << this->maxCargoVolume << " M_Kg: " << this->maxCargoWeight;
        out << " C_vol: " << this->currentCargoVolume << " C_KG: " << this->currentCargoWeight << endl;
    }
    else
    {
        out << " " << this->maxCargoVolume << " " << this->maxCargoWeight;
        out << " " << this->currentCargoVolume << " " << this->currentCargoWeight << endl;
    }
}

