//
//  CityLocation.h
//  eecrews_asg3
//
//  Created by Erin Crews on 3/19/21.
//

#ifndef CityLocation_h
#define CityLocation_h
#include <stdlib.h>
#include "Location.h"

class CityLocation: public Location {
    public:
        CityLocation();
        CityLocation(std::string name, std::string address, std::string hours, int reservation);
        CityLocation(const Location& copy_from);
        bool Reserve() override;
        void Cancel() override;
        void Print() const override;
        void Read(std::istream& s) override;
        void Write(std::ostream& s) const override;
        CityLocation* Copy();
};


#endif /* CityLocation_h */
