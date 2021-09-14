//
//  Location.cpp
//  eecrews_asg2
//
//  Created by Erin Crews on 3/1/21.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Location.h"

Location::Location() {
    name = "N/A";
    address = "N/A";
    hours = "N/A";
    reservation = 0;
}

Location::Location(std::string n, std::string a, std::string h, int res) {
    name = n;
    address = a;
    hours = h;
    reservation = res;
}

Location::Location(const Location& copy_from) {
    name = copy_from.name;
    address = copy_from.address;
    hours = copy_from.hours;
    reservation = copy_from.reservation;
}

bool Location::IsReservable() const {
    return reservation != 0;
}

std::string Location::to_string() const {
    return name;
}

void Location::Print() const {
    std::cout << "\nLocation: " + name + "\nAddress: " + address + "\nHours: " + hours +
    + "\nAllows Reservations: ";
    if(reservation != 0)
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
}

void Location::Read(std::istream& s) {
    
}
void Location::Write(std::ostream& s) const {
    
}

bool Location::Reserve() {
    return true;
}
void Location::Cancel() {
    
}



