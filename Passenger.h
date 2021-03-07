/*
 * NAME - RAJAS BHATT
 * ROLL NO - 19CS30037
 * VERSION - 1.0
 */
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
        Passenger(std::string, std::string, Date, std::string, std::string, std::string);
        Passenger(const char *, const char *, Date, const char *, const char *, const char *);
        virtual inline ~Passenger() {};
        static const Passenger sNullPassenger;
};




#endif  // _PASSENGER_H