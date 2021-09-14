//
//  CampusLocation.h
//  eecrews_asg3
//
//  Created by Erin Crews on 3/23/21.
//

#ifndef CampusLocation_h
#define CampusLocation_h
#include <stdlib.h>
#include "Location.h"

class CampusLocation: public Location {
    public:
        CampusLocation();
        bool Reserve() override;
        void Cancel() override;
        void Print() const override;
        void Read(std::istream& s) override;
        void Write(std::ostream& s) const override;
}; 


#endif /* CampusLocation_h */
