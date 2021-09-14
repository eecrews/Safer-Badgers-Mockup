//
//  Location.h
//  eecrews_asg2
//
//  Created by Erin Crews on 3/1/21.
//

#ifndef Location_h
#define Location_h
#include <string>

class Location {
    protected:
        std::string name;
        std::string address;
        std::string hours;
        int reservation;
    public:
        Location();
        Location(std::string name, std::string address, std::string hours, int reservation);
        Location(const Location& copy_from);
        bool IsReservable() const;
        std::string to_string() const;
    
        virtual void Print() const = 0;
        virtual void Read(std::istream& s) = 0;
        virtual void Write(std::ostream& s) const = 0;
        virtual bool Reserve() = 0;
        virtual void Cancel() = 0;
        
};

#endif /* Location_h */
