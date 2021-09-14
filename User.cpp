//
//  User.cpp
//  eecrews_asg3
//
//  Created by Erin Crews on 3/3/21.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include "User.h"

User::User() {
    firstName = "N/A";
    lastName = "N/A";
    age = 0;
    height = 0;
    weight = 0;
    reservations = new LocationList();
    user_filename = "default.txt";
    reservations_filename = "default_reservations.txt";
}

void User::MakeReservation(const Location& new_reservation) {
    CityLocation *new_loc = new CityLocation(new_reservation);
    CityLocation *new_loc_copy = new_loc->Copy();
    new_loc_copy->Reserve();
    reservations->AddLocation(new_loc_copy);
}

void User::to_string() {
    std::cout << firstName + " " + lastName;
}

void User::PrintData() {
    std::cout << "\nYour data:\nName:\t" + firstName + " " + lastName + "\nAge:\t" + std::to_string(age) +
    "\nHeight: " + std::to_string(height) + " " + "\nWeight: " + std::to_string(weight); 
}

void User::PrintReservations() {
    std::cout << "\nHere are your reservations:\n";
    for(int i=0; i<reservations->GetCount(); i++) {
        reservations->GetLocation(i)->Print();
    }
}

void User::Read(bool& is_imperial, std::string fname) {
    std::ifstream fs;
    if(fname == "")
        fs.open(user_filename);
    else
        fs.open(fname);
    
    int imperial;
    
    fs >> firstName;
    fs >> lastName;
    fs >> age;
    fs >> height;
    fs >> weight;
    fs >> imperial;
    
    is_imperial = imperial;
    
    reservations->FromFile(reservations_filename);

}

// TODO: Come back to this 
void User::Write(const bool is_imperial) const {
    std::ofstream fs;
    fs.open(user_filename);
    fs << firstName << " " << lastName << " " << age << " " << height << " "
        << weight << " ";
    if(is_imperial)
        fs << 1;
    else
        fs << 0;
    
    reservations->ToFile(reservations_filename);
}
