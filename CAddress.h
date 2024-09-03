//
// Created by אילון אהרוני on 01/09/2024.
//

#ifndef AIRPORT_CADDRESS_H
#define AIRPORT_CADDRESS_H
#include <string>

using namespace std;

class CAddress {
private:
    string city ;
    string street;
    int houseNumber;

public:
    CAddress(int houseNum, const string& street, const string& city = "Tel Aviv");//constructor
    CAddress(const CAddress& other);
    void updateAddress( const string& newCity,const string& newStreet,  int houseNum);
    string getCity() const;
    string getStreet() const;
    int getHouseNumber() const;
    void print() const;


    };


#endif //AIRPORT_CADDRESS_H
