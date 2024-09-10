
#ifndef AIRPORT_CFLIGHTCOMPANY_H
#define AIRPORT_CFLIGHTCOMPANY_H
using namespace std;
#include <string>

class CFlightCompany
{
public:
	CFlightCompany(const string name);
	CFlightCompany(const CFlightCompany& other) = default; // Copy Constructor
	~CFlightCompany() = default;						   // Destructor
	const string GetName() const;
	void SetName(const string name);
	void Print() const;

private:
	string company_name;
};


#endif //AIRPORT_CFLIGHTCOMPANY_H
