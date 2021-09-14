//
//  main.cpp
//  eecrews_asg3
//
//  Created by Erin Crews on 3/3/21.
//

#include <iostream>
#include <string>
#include "menus.h"
#include "LocationList.h"
#include "User.h"
using namespace std;

LocationList *locations = new LocationList();
User *theUser = new User();
bool isImperial = true;

/*
 * Static array of strings that initializes each of the 6 COVID symptoms tracked by this app.
 */
static string symptoms[] = {"Fever","Cough","Shortness of breath","Loss of taste or smell","Fatigue","Sore throat"};

/*
 * Static boolean array of size 6. Each index corresponds to a symptom.
 * When an index contains true, the user has selected the corresponding symptom.
 */
static bool selected[6];

/*
 * Helper method that is called when user inputs option [1] on the main menu.
 * Handles output and user input for the View Testing Locations menu.
 */
void viewTestingLocationHandler() {
    
    printTestingLocations(*locations);
    
    int locationsInput;
    while(!(cin >> locationsInput) || (locationsInput > 5) || (locationsInput < 0)) {
        cin.clear();
        cin.ignore();
        cout << "Please enter a valid input: ";
    } // checking for invalid input
        
    if(locationsInput == 5) {
        return; // returns to main menu
    }
    
    Location *selectedLoc = locations->GetLocation(locationsInput);
    selectedLoc->Print();
    cout << "Press enter to return.";
            
    int exitInput;
    exitInput = cin.get();
    cin.ignore();
    viewTestingLocationHandler();
}

void setReservationHandler() {
    
    printReservationLocations(*locations);
    
    int reservationInput;
    while(!(cin >> reservationInput) || (reservationInput < 0)) {
        cin.clear();
        cin.ignore();
        cout << "Please enter a valid input: ";
    }
    
    if(reservationInput == 6) {
        return; // returns to main menu
    }
    
    theUser->MakeReservation(*(locations->GetLocation(reservationInput)));
    cout << "\nPress enter to return to main menu.";

    
    int exitInput;
    exitInput = cin.get();
    cin.ignore();
    return;
}

void viewReservationHandler() {
    
    theUser->PrintReservations();
    
    cout << "\nPress enter to return to main menu.";
    
    int exitInput;
    exitInput = cin.get();
    cin.ignore();
    return;
}

void viewPersonalDataHandler() {
    theUser->PrintData();
    cout << "\nPress enter to return to main menu.";
    
    int exitInput;
    exitInput = cin.get();
    cin.ignore();
    return;
}

void setPersonalDataHandler() {
    string currWeightUnit = "lbs";
    string currHeightUnit = "ft";
    if(!isImperial) {
        currWeightUnit = "kg";
        currHeightUnit = "m";
    }
    
    bool menuIsRunning = true;
    
    while(menuIsRunning) {
        cout << "\nSet your personal data:\n[1] First name (" + theUser->firstName + ")" +
        "\n[2] Last name (" + theUser->lastName + ")" + "\n[3] Age (" + to_string(theUser->age) + ")" +
            "\n[4] Height (" + to_string(theUser->height) + " " + currHeightUnit + ")" + "\n[5] Weight (" + to_string(theUser->weight) + " " + currWeightUnit + 
               ")" + "\n[6] Return to main menu\nPlease enter a menu item:";
        int setDataInput;
        cin >> setDataInput;
        switch(setDataInput) {
            case 1: {
                cout << "Enter your first name:";
                string firstNameInput;
                cin >> firstNameInput;
                theUser->firstName = firstNameInput;
                break; }
            case 2: {
                cout << "Enter your last name:";
                string lastNameInput;
                cin >> lastNameInput;
                theUser->lastName = lastNameInput;
                theUser->user_filename = lastNameInput + ".txt";
                theUser->reservations_filename = lastNameInput + "_reservations.txt";
                break; }
            case 3: {
                cout << "Enter your age:";
                int ageInput;
                cin >> ageInput;
                while(ageInput > 122 || ageInput < 0) {
                    cin.clear();
                    cin.ignore();
                    cout << "Please enter a valid age:";
                    cin >> ageInput;
                }
                theUser->age = ageInput;
                break; }
            case 4:
                cout << "Enter your height:";
                float heightInput;
                cin >> heightInput;
                if(isImperial) {
                    while(heightInput > 9 || heightInput < 0) {
                        cin.clear();
                        cin.ignore();
                        cout << "Please enter a valid height:";
                        cin >> heightInput;
                    }
                } else {
                    while(heightInput > 2.75 || heightInput < 0) {
                        cin.clear();
                        cin.ignore();
                        cout << "Please enter a valid height:";
                        cin >> heightInput;
                    }
                }
                theUser->height = heightInput;
                break;
            case 5:
                cout << "Enter your weight:";
                float weightInput;
                cin >> weightInput;
                if(isImperial) {
                    while(weightInput > 975 || weightInput < 0) {
                        cin.clear();
                        cin.ignore();
                        cout << "Please enter a valid weight:";
                        cin >> weightInput;
                    }
                } else {
                    while(weightInput > 445 || weightInput < 0) {
                        cin.clear();
                        cin.ignore();
                        cout << "Please enter a valid weight:";
                        cin >> weightInput;
                    }
                }
                theUser->weight = weightInput;
                break;
            case 6:
                menuIsRunning = false;
                break;
            default:
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Error. Please enter a valid number.";
                break;
        }
    }
}

void changeSettingsHandler() {
    bool menuIsRunning = true;

    while(menuIsRunning) {
        printSettingsMenu(!isImperial);
        int changeSettingsInput;
        cin >> changeSettingsInput;

        switch(changeSettingsInput) {
            case 1:
                if(isImperial) {
                    theUser->height = theUser->height/3.28;
                    theUser->weight = theUser->weight/2.20;
                } else {
                    theUser->height = theUser->height * 3.28;
                    theUser->weight = theUser->weight * 2.20;
                }
                isImperial = !isImperial;
                break;
            case 2: {
                cout << "\nEnter your last name: ";
                string lastNameInput;
                cin >> lastNameInput;
                theUser->Read(isImperial, lastNameInput + ".txt");
                cout << "\nData successfully loaded.";
                break; }
            case 3: 
                theUser->Write(isImperial);
                cout << "\nData successfully saved.";
                break;
            case 4:
                menuIsRunning = false;
                break;
            default:
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\nError. Please enter a valid number.\n";
                break;
            }
        }
}

/*
 * Helper method that is called when user inputs option [2] on the main menu.
 * Handles output and user input for the Symptom Checker menu.
 */
void printSymptomCheckerHandler() {
    while(1) {
        printSymptomChecker(symptoms, selected);
        int symptomInput;
        while(!(cin >> symptomInput) || (symptomInput > 8) || (symptomInput < 1)) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a valid input: ";
        } // checking for invalid input

        if(symptomInput == 7) {
            int numSelected = 0;
            for(int i=0; i<sizeof(selected); i++) { // checks how many symptoms are selected
                if(selected[i])
                    numSelected++;
            }
            
            if(numSelected >= 3)
                cout << "\nPlease go to an available testing site to be tested for Covid-19.";
            else if(numSelected == 0)
                cout << "\nYou seem to be feeling fine. Remember to test regularly for Covid-19.";
            else
                cout << "\nPlease stay home and monitor your symptoms. If your symptoms persist or you develop new symptoms"
                " please go to an available testing site to be tested for Covid-19.";
            
            cout << "\nPress enter to return to main menu.";
            
            int exitInput;
            exitInput = cin.get();
            cin.ignore();
            return;
        }
        else if(symptomInput == 8) { // returns to main menu
            return;
        }
        
        selected[symptomInput-1] = !selected[symptomInput-1]; // toggles or untoggles the selected symptom

    }
}
/*
 * Main method. Handles output and user input for the main menu.
 */
int main() {
    
   // Load();
    locations->FromFile("/Users/erincrews/Desktop/xcode_workspace/eecrews_asg3/eecrews_asg3/locations.txt");
    
    while(1) {
        printMainMenu();
        int mainInput;
        while(!(cin >> mainInput) || (mainInput > 8) || (mainInput < 1)) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a valid input: ";
        } // checking for invalid input
        
        switch(mainInput) {
            case(1): {
                viewTestingLocationHandler();
                break;
            }
            case(2): {
                setReservationHandler();
                break;
            }
            case(3): {
                printSymptomCheckerHandler();
                break;
            }
            case(4): {
                viewReservationHandler();
                break;
            }
            case(5): {
                viewPersonalDataHandler();
                break;
            }
            case(6): {
                setPersonalDataHandler();
                break;
            }
            case(7): {
                changeSettingsHandler();
                break;
            }
            case(8): {
                theUser->Write(isImperial);
                locations->ToFile("locations.txt");
                free(locations);
                locations = NULL;
                exit(0);
            }
        }
    }
    
    return 0;
}
