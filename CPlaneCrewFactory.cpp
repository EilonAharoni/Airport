#include "CPlaneCrewFactory.h"
#include <fstream>

PlaneType CPlaneCrewFactory::GetPlaneType(const CPlane *pPlane) noexcept
{
    if (dynamic_cast<const CCargo*>(pPlane)) 
    {
        return eCargo;
    } else 
    {   
        return eRegular;
    }
}

CrewType CPlaneCrewFactory::GetCrewType(const CCrewMember *pCrew) noexcept
{
    if (dynamic_cast<const CPilot*>(pCrew)) {
        return ePilot;
    }
    return eHost;
}

int CPlaneCrewFactory::GetNumberFromUser(const string& itemType)
{
    int number;
    cout << "Enter number of " << itemType << ": ";
    if(!(cin >> number) || number < 0)
		throw CCompStringException("Invalid input for number of " + itemType);
    return number;
}

void CPlaneCrewFactory::GetCompanyName(CFlightCompany& comp)
{
    string name;
	cout << "Enter company name: ";
	cin.ignore();
	getline(cin, name);
	comp.setName(name);
}

void CPlaneCrewFactory::GetCompanyDataFromUser(CFlightCompany& comp) 
{   
    // Delete all the existing data in the company
    comp.clear();

    // Get company name from user
    GetCompanyName(comp);

    // Get crew members from user
    int nofCrewMembers = GetNumberFromUser("crew members");
    for (int i = 0; i < nofCrewMembers; i++) 
    {
        CCrewMember* pCrew = GetCrewMemberFromUser();
        comp.AddCrewMember(*pCrew);
    }

    // Get planes from user
    int nofPlanes = GetNumberFromUser("planes");
    for (int i = 0; i < nofPlanes; i++) 
    {
        CPlane* pPlane = GetPlaneFromUser();
        comp.AddPlane(*pPlane);
    }

    //Get flights from user
    int nofFlights = GetNumberFromUser("flights");
    for (int i = 0; i < nofFlights; i++) 
    {
        CFlight* pFlight = GetFlightFromUser(comp);
        comp.AddFlight(*pFlight);

        // Select crew members for the flight
        SelectCrewMembersForFlight(comp, pFlight);
    }
}   

CFlight *CPlaneCrewFactory::GetFlightFromUser(CFlightCompany& comp)
{
    //Get flightinfo from user
    string destination;
	cout << "Enter flight destination: ";
	cin >> destination;

    int flightNumber;
    cout << "Enter flight number: ";
    cin >> flightNumber;

    int flightDuration;
    cout << "Enter flight duration in minutes: ";
	cin >> flightDuration;

    int flightDistance;
    cout << "Enter flight distance in KM: ";
	cin >> flightDistance;

    CFlightInfo* Info = new CFlightInfo(destination, flightNumber, flightDuration, flightDistance);
    
    //Select a plane for the flight
    CPlane* selectedPlane = SelectPlaneForFlight(comp);

    if(selectedPlane)
    {
        return new CFlight(*Info, selectedPlane);
	}
	else
	{
		return new CFlight(*Info);
	}
}

void CPlaneCrewFactory::SelectCrewMembersForFlight(CFlightCompany& comp, CFlight* pFlight)
{
	// Add crew members to the flight
	cout << "Enter how many crew members you wanna add for this flight: ";
	int nofCrewMembers;
	cin >> nofCrewMembers;
    if (nofCrewMembers < 0 || nofCrewMembers > comp.GetCrewCount())
        throw CCompStringException("Invalid input for number of crew members for the flight");

    for (int i = 0; i < nofCrewMembers; i++)
    {
		//Show the crew members to the user
        for (int j = 0; j < comp.GetCrewCount(); j++)
        {
			cout << j << ". " << comp.GetCrewMember(j)->getName() << endl;
		}
        cout << "Enter the index of the crew member you want to add: ";
        int crewIndex;
        if (!(cin >> crewIndex) || crewIndex < 0 || crewIndex >= comp.GetCrewCount())
            throw CCompLimitException(crewIndex);

		comp.AddCrewToFlight(pFlight->getId(), crewIndex);
	}
}

CPlane* CPlaneCrewFactory::SelectPlaneForFlight(CFlightCompany& comp)
{
    int addPlane = getValidInput<int>("Would you like to add a plane to the flight? (1 for Yes, 0 for No): ", 0, 1);

    if (addPlane)
    {
        cout << "Planes in the company: " << endl;
        comp.PrintPlanes(cout, comp);
        cout << "Enter the plane ID: ";
        int planeID;
        cin >> planeID;

        return comp.GetPlaneByID(planeID);
    }
    return nullptr; 
}

CPlane *CPlaneCrewFactory::GetPlaneFromUser() {
    int type = getValidInput<int>("Enter plane type (0 for Regular, 1 for Cargo): ", 0, 1);

    string model;
    int seats;
    cout << "Enter Plane Model: ";
    cin >> model;
    cout << "Enter number of seats: ";
    cin >> seats;

    if (type == eCargo) 
    {
        float maxCargoWeight;
        cout << "Enter cargo Weight: ";
        cin >> maxCargoWeight;
        if (maxCargoWeight < 0)
            throw CCompStringException("Weight cannot be negative");

        float maxCargoVolume;
        cout << "Enter cargo Volume: ";
        cin >> maxCargoVolume;
        if (maxCargoVolume < 0)
			throw CCompStringException("Volume cannot be negative");

        return new CCargo(seats,model, maxCargoWeight,maxCargoVolume);  // Creating a cargo plane
    } else 
    {
        return new CPlane(seats,model);  // Creating a regular plane
    }
}

CCrewMember *CPlaneCrewFactory::GetCrewMemberFromUser()
{
    int choice = getValidInput<int>("Enter crew member type (0 for Host, 1 for Pilot): ", 0, 1);

    string name;
    cout << "Enter the name of the crew member: ";
    cin >> name;

    int airTime;
    cout << "Enter the Air time of the crew member (in minutes): ";
    cin >> airTime;

    // If the user selects a Host
    if (choice == eHost) 
    {
        int hostTypeChoice = getValidInput<int>("Enter Host type (0 for Regular, 1 for Super, 2 for Calcelan): ", 0, 2);
        return new CHost(name, static_cast<CHost::eType>(hostTypeChoice), airTime);
    }
    // If the user selects a Pilot
    else if (choice == ePilot) 
    {
        bool isCaptain = getValidInput<bool>("Is the pilot a captain? (1 for Yes, 0 for No): ", 0, 1);

        // Assuming the CAddress is optional and can be nullptr
        CAddress* address = nullptr;
        int addressChoice = getValidInput<int>("Would you like to enter an address ? (1 for Yes, 0 for No) : ", 0, 1);

        if (addressChoice == 1) 
            address = GetAddressFromUser();
		
        return new CPilot(name, isCaptain, address, airTime);
    }
    return nullptr;
}

CAddress* CPlaneCrewFactory::GetAddressFromUser() 
{
	string street;
	cout << "Enter street name: ";
    cin >> street;

	int number;
	cout << "Enter house number: ";
	cin >> number;

	string city;
    cout << "Enter city name: ";
    cin >> city;

    return new CAddress(number, street, city);
}   

CCrewMember *CPlaneCrewFactory::GetCrewMemberFromFile(ifstream &inFile)
{
    int type;
    inFile >> type;  // First read the type of the crew member (host/pilot)

    if (type == eHost) {
        return new CHost(inFile);  
    } else if (type == ePilot) 
    {
        return new CPilot(inFile);  
    }
    throw CCompStringException("Invalid crew member type");
    return nullptr;
}

CPlane *CPlaneCrewFactory::GetPlaneFromFile(ifstream &inFile)
{
    int type;
    inFile >> type;  // First read the type of the plane (regular/cargo)

    if (type == eRegular)
    {
        return new CPlane(inFile);  
    } else if (type == eCargo) 
    {
        return new CCargo(inFile); 
    }
    throw CCompStringException("Invalid plane type");
    return nullptr;
}

void CPlaneCrewFactory::cleanCin()
{
    cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

template <typename T>
T CPlaneCrewFactory::getValidInput(const string& prompt, T lowerBound, T upperBound)
{
	T input;
	cout << prompt;
	cin >> input;
    while (input < lowerBound || input > upperBound)
    {
		cout << "Invalid input. Please enter a value between " << lowerBound << " and " << upperBound << ": ";
		cleanCin();
		cin >> input;
	}
	return input;
}
