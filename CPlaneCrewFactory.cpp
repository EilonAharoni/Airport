//
// Created by אילון אהרוני on 13/10/2024.
//
#include "CPlaneCrewFactory.h"
#include "CPlane.h"
#include "Cargo.h"
#include "CCrewMember.h"
#include "CHost.h"
#include "CPilot.h"
#include "CFlightCompException.h"
#include <fstream>
PlaneType CPlaneCrewFactory::GetPlaneType(const CPlane *pPlane)
{
    if (dynamic_cast<const CCargo*>(pPlane)) {
        return eCargo;
    } else {
        return eRegular;
    }
}

CrewType CPlaneCrewFactory::GetCrewType(const CCrewMember *pCrew)
{
    if (dynamic_cast<const CPilot*>(pCrew)) {
        return ePilot;
    }
    return eHost;

}

void CPlaneCrewFactory::GetCompanyDataFromUser(CFlightCompany &comp) {

}

CPlane *CPlaneCrewFactory::GetPlaneFromUser() {
    int type;
    cout << "Enter Plane Type (0: Regular, 1: Cargo): ";
    cin >> type;

    string model;
    int seats;

    cout << "Enter Plane Model: ";
    cin >> model;
    cout << "Enter number of seats: ";
    cin >> seats;

    if (type == eCargo) {
        float maxCargoWeight;
        cout << "Enter cargo Weight: ";
        cin >> maxCargoWeight;

        float maxCargoVolume;
        cout << "Enter cargo Volume: ";
        cin >> maxCargoVolume;

        return new CCargo(seats,model, maxCargoWeight,maxCargoVolume);  // Creating a cargo plane
    } else {
        return new CPlane(seats,model);  // Creating a regular plane
    }

}

CCrewMember *CPlaneCrewFactory::GetCrewFromUser()
{
    int choice;
    cout << "Enter the crew member type (0 for Host, 1 for Pilot): ";
    cin >> choice;

    while (choice < 0 || choice >= nofCrewType) {
        cout << "Invalid input. Please enter 0 for Host or 1 for Pilot: ";
        cin >> choice;
    }

    string name;
    cout << "Enter the name of the crew member: ";
    cin.ignore();  // To ignore any leftover newline character
    getline(cin, name);

    // If the user selects a Host
    if (choice == eHost) {
        int hostTypeChoice;
        cout << "Enter Host type (0 for Regular, 1 for Super, 2 for Calcelan): ";
        cin >> hostTypeChoice;

        while (hostTypeChoice < 0 || hostTypeChoice >= CHost::eCalcelan + 1) {
            cout << "Invalid input. Please enter a valid Host type (0-2): ";
            cin >> hostTypeChoice;
        }

        return new CHost(name, static_cast<CHost::eType>(hostTypeChoice));
    }
        // If the user selects a Pilot
    else if (choice == ePilot) {
        bool isCaptain;
        cout << "Is the pilot a captain? (1 for Yes, 0 for No): ";
        cin >> isCaptain;

        // Assuming the CAddress is optional and can be nullptr
        CAddress* address = nullptr;
        cout << "Would you like to enter an address? (1 for Yes, 0 for No): ";
        int addressChoice;
        cin >> addressChoice;

        if (addressChoice == 1) {
            string street;
            cout << "Enter street name: ";
            getline(cin,street);

            int number;
            cout << "Enter house number: ";
            cin >> number;

            string city;
            cout << "Enter city name: ";
            getline(cin,city);
            address = new CAddress(number,street,city);
        }

        return new CPilot(name, isCaptain, address);
    }

    return nullptr;
}

CCrewMember *CPlaneCrewFactory::GetCrewMemberFromFile(ifstream &inFile)
{
    int type;
    inFile >> type;  // First read the type of the crew member (host/pilot)

    if (type == eHost) {
        return new CHost(inFile);  // Assuming CHost has a constructor that takes an ifstream
    } else if (type == ePilot) {
        return new CPilot(inFile);  // Assuming CPilot has a constructor that takes an ifstream
    }

    return nullptr;
}

CPlane *CPlaneCrewFactory::GetPlaneFromFile(ifstream &inFile) {
    int type;
    inFile >> type;  // First read the type of the plane (regular/cargo)

    if (type == eRegular) {
        return new CPlane(inFile);  // need to finish CPlane constructor that takes an ifstream
    } else if (type == eCargo) {
        return new CCargo(inFile);  // Assuming CCargo has a constructor that takes an ifstream
    }
    return nullptr;
}
