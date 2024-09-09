//
// Created by אילון אהרוני on 01/09/2024.
//

#ifndef AIRPORT_CFLIGHTCOMPANY_H
#define AIRPORT_CFLIGHTCOMPANY_H
using namespace std;
#include <string>

class CFlightCompany {
public:
	CFlightCompany(const string name);
	CFlightCompany(const CFlightCompany& other); // Copy Constructor
	string GetName() const;
	void SetName(string name);
	void Print() const;

private:
	string company_name;
};


#endif //AIRPORT_CFLIGHTCOMPANY_H
