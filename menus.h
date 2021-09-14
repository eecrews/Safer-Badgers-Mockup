//
//  menus.h
//  eecrews_asg2
//
//  Created by Erin Crews on 2/21/21.
//  WiscID: eecrews
//

#ifndef menus_h
#define menus_h
#include "LocationList.h"
#include "User.h"

void printMainMenu();
void printTestingLocations(const LocationList&);
void printSymptomChecker(std::string symptoms[], bool selected[]);
void printSettingsMenu(const bool is_metric);
void printReservationLocations(const LocationList& locations);
void printUserDataMenu(const User& user);

#endif /* menus_h */
