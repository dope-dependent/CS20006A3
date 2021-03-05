#ifndef _PASSENGER_H
#define _PASSENGER_H

#include "Date.h"
#include <string>

class Passenger{
    private:
        std::string name_;
        std::string aadhar_;
        Date dob_;
        std::string gender_;
        std::string mobile_;
        std::string category_;
    
    public:
        Passenger();
        virtual ~Passenger();
};




#endif  // _PASSENGER_H