//
//  menus.cpp
//  eecrews_asg2
//
//  Created by Erin Crews on 2/21/21.
//  WiscID: eecrews
//

#include <iostream>
#include <stdio.h>
#include <string>
#include "menus.h"
#include "LocationList.h"
#include "User.h"
using namespace std;

/*
 * Outputs the main menu.
 */
void printMainMenu() {
    cout << "\nWelcome (back) to Safe-ish Badgers!\n[1] View testing locations\n[2] Make test reservation\n[3] Use symptom checker\n[4] View my reservations\n[5] View my personal data\n[6] Adjust my personal data\n[7] Change settings\n[8] Exit program\nPlease enter a menu item: ";
}

// TODO: UPDATE FUNCTION COMMENTS!!

/*
 * Outputs the given testing locations.
 *
 * @param locations[]   list of the names of the testing locations
 * @param count         the size of the given location array
 */
void printTestingLocations(const LocationList& locations) {
    cout << "\nTesting Locations:";
    for(int i=0; i<locations.GetCount(); i++) {
        cout << "\n[" + std::to_string(i) + "] " + locations.GetLocation(i)->to_string();
    }
    cout << "\n[5] Return to main menu\nChoose a location for more information, or return to the menu: ";
}

/*
 * Outputs the list of given symptoms. Displays a * by a symptom if the user
 * has selected it.
 *
 * @param symptoms  list of COVID symptoms the user is able to select/deselect
 * @param selected  contains data correspondong to which symptoms are selected
 */
void printSymptomChecker(std::string symptoms[], bool selected[]) {
    cout << "\nSelect Your Symptoms:";
    for(int i=0; i<=symptoms->size(); i++) {
        cout << "\n[" + std::to_string(i+1);
        
        if(selected[i])
            cout << "*";
        
        cout << "] " + symptoms[i];
    }
    cout << "\n[7] Submit symptoms\n[8] Cancel and return to main menu";
}

void printUserDataMenu(const User& user) {
    cout << "\nSet your personal data:\n[1] First name (" + user.firstName + ")" +
    "\n[2] Last name (" + user.lastName + ")" + "\n[3] Age (" + std::to_string(user.age) + ")" +
        "\n[4] Height (" + std::to_string(user.height) + " " + ")" + "\n[5] Weight (" + std::to_string(user.weight) +
           " " + ")" + "\n[6] Return to main menu\nPlease enter a menu item:";
}

void printSettingsMenu(const bool is_metric) {
        cout << "\nChange your app settings.\n[1] Switch units (";
        if(is_metric) {
            cout << "metric";
        } else {
            cout << "imperial";
        }
        cout << ")\n[2] Load Data\n[3] Save Data\n[4] Return to main menu\nPlease enter a menu item:";
}

void printReservationLocations(const LocationList& locations) {
    cout << "\nTesting Locations:";
    for(int i=0; i<locations.GetCount(); i++) {
        if(locations.GetLocation(i)->IsReservable()) {
            cout << "\n[" + std::to_string(i) + "] " + locations.GetLocation(i)->to_string();
        }
    }
    cout << "\n[6] Return to main menu\nChoose a location to reserve, or return to the menu: ";
}
