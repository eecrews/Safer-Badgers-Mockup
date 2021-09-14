//
//  LocationList.cpp
//  eecrews_asg2
//
//https://stackoverflow.com/questions/7868936/read-file-line-by-line-using-ifstream-in-c
//  Created by Erin Crews on 3/1/21.
//c

#include "LocationList.h"
#include <iostream>
#include <fstream>
#include <string>

void LocationList::Grow() {
    Location** newList = new Location*[arrSize*2];
    
    for(int i=0; i<arrSize; i++) {
        newList[i] = list[i];
        delete list[i];
    }
    
    delete[] list;
    list = newList;
    arrSize = arrSize*2;
}

LocationList::LocationList() {
    arrSize = 16;
    numLocs = 0;
    list = new Location*[arrSize];
}

LocationList::~LocationList() {
    for(int i=0; i<arrSize; i++) {
        delete list[i];
    }
    delete[] list;
    list = NULL;
}

int LocationList::GetCount() const {
    return numLocs;
}

Location* LocationList::GetLocation(int index) const {
    return list[index];
}

void LocationList::AddLocation(Location* new_loc) {
    if(numLocs == arrSize)
        Grow();
    list[numLocs++] = new_loc;
}

void LocationList::FromFile(std::string fname) {
    std::ifstream readFile(fname);
    if(!readFile)
        std::cout << "\nCould not open file.";

    std::string line;
    getline(readFile, line);
    arrSize = stoi(line);
        
    while(getline(readFile,line)) {
        readFile.clear();
        std::cout << line + "\n";
        if(line == "citylocation") {
            Location *cityLoc = new CityLocation();
            list[numLocs++] = cityLoc;
            cityLoc->Read(std::getline(readFile,line));
        } else if(line == "campuslocation") {
            Location *campusLoc = new CampusLocation();
            list[numLocs++] = campusLoc;
            campusLoc->Read(std::getline(readFile,line));
        }
    }
    
    
    readFile.close();
}

void LocationList::ToFile(std::string fname) {
    std::ofstream toFile(fname);
    toFile << numLocs;
    
    for(int i=0; i<numLocs; i++) {
        GetLocation(i)->Write(toFile);
    }
}
