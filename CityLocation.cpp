//
//  CityLocation.cpp
//  eecrews_asg3
//
//  Created by Erin Crews on 3/19/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>
#include "CityLocation.h"

CityLocation::CityLocation() :Location(){}

CityLocation::CityLocation(std::string name, std::string address,
             std::string hours, int reservation) : Location(name, address, hours, reservation){}

CityLocation::CityLocation(const Location& copy_from) : Location(copy_from){}

bool CityLocation::Reserve() {
    if(reservation != 0) {
        reservation--;
        return true;
    }
    return false;
}

void CityLocation::Cancel() {
    reservation++;
}

void CityLocation::Print() const {
    std::cout << "\n*** Off-Campus ***\nLocation: " + name + "\nAddress: " + address + "\nHours: " + hours +
    + "\nAvailable Reservations: " + std::to_string(reservation);
}

void CityLocation::Read(std::istream& s) {
   /* std::vector<std::string> vec;
    std::string info;
    
    while(getline(s, info, ',')) {
        vec.push_back(info);
    }
    
    name = vec.at(0);
    address = vec.at(1);
    hours = vec.at(2);
    reservation = stoi(vec.at(3)); */
    
    std::string line(std::istreambuf_iterator<char>(s), {});
    std::stringstream ss(line);
    getline(ss,name,',');
    getline(ss,address,',');
    getline(ss,hours,',');
}

void CityLocation::Write(std::ostream& s) const {
    s << "citylocation\n";
    s << name << ',' << address << ',' << hours << ',' << reservation << "\n";
}

CityLocation* CityLocation::Copy() {
    CityLocation *copy = new CityLocation(this->name, this->address, this->hours, this->reservation);
    return copy;
}
