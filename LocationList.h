//
//  LocationList.h
//  eecrews_asg2
//
//  Created by Erin Crews on 3/1/21.
//

#ifndef LocationList_h
#define LocationList_h
#include "Location.h"
#include "CityLocation.h"
#include "CampusLocation.h"

class LocationList {
    private:
        Location** list;
        int numLocs;
        int arrSize;
        void Grow();

    public:
        LocationList();
        ~LocationList();
        int GetCount() const;
        Location* GetLocation(int index) const;
        void AddLocation(Location* new_loc);
        void FromFile(std::string fname);
        void ToFile(std::string fname);
};

#endif /* LocationList_h */
