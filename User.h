//
//  User.h
//  eecrews_asg3
//
//  Created by Erin Crews on 3/3/21.
//

#ifndef User_h
#define User_h
#include <stdlib.h>
#include <string>
#include "LocationList.h"

struct User {
    public:
        std::string firstName;
        std::string lastName;
        std::string user_filename;
        std::string reservations_filename;
        int age;
        float height;
        float weight;
        LocationList* reservations;
        User();
        void MakeReservation(const Location& new_reservation);
        void to_string();
        void PrintData();
        void PrintReservations();
        void Read(bool& is_imperial, std::string fname = "");
        void Write(const bool is_imperial) const;
};


#endif /* User_h */
