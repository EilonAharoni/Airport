
#include "CFlightCompany.h"
#include <iostream>

CFlightCompany::CFlightCompany(const string company_name)
	: company_name(company_name)
{
}

const string CFlightCompany::GetName() const
{
	return this->company_name;
}

void CFlightCompany::SetName(const string new_company_name)
{
	if (new_company_name.empty())
	{
		cout << "Company name must not be empty" << endl;
		return;
	}
	this->company_name = new_company_name;
}

void CFlightCompany::Print() const
{
	std::cout << "Company name: " << this->company_name << std::endl;
}

