//
//  CampusLocation.cpp
//  eecrews_asg3
//
//  Created by Erin Crews on 3/23/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>
#include "CampusLocation.h"

CampusLocation::CampusLocation() : Location("N/A","N/A","N/A",0) {}

bool CampusLocation::Reserve() {
    return false;
}

void CampusLocation::Cancel() {
    
}

void CampusLocation::Print() const {
    std::cout << "\n*** On-Campus ***\nLocation: " + name + "\nAddress: " + address + "\nHours: " + hours +
    + "\nAvailable Reservations: 0";
}

void CampusLocation::Read(std::istream& s) {
  /*  std::vector<std::string> vec;
    std::string info;
    
    while(getline(s, info, ',')) {
        vec.push_back(info);
    }
    
    name = vec.at(0);
    address = vec.at(1);
    hours = vec.at(2); */
        
    //std::string line(std::istreambuf_iterator<char>(s), {});
    //std::stringstream ss(line);
        
    std::getline(s,name,',');
    std::getline(s,address,',');
    std::getline(s,hours,',');
//    std::string res;
 //   std::getline(s,res,',');
//    reservation = stoi(res);
    
    
    //std::cout << address;
        
}

void CampusLocation::Write(std::ostream& s) const {
    s << "campuslocation\n";
    s << name << ',' << address << ',' << hours << "\n";
}

