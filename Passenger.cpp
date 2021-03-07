/*
 * NAME - RAJAS BHATT
 * ROLL NO - 19CS30037
 * VERSION - 1.0
 */
#include "Passenger.h"

Passenger::Passenger()
    :   name_(std::string("NO Name")), 
        aadhar_(std::string("0000 0000 0000")),
        dob_(Date(1,1,2001)),
        gender_(std::string("M")),
        mobile_(std::string("+910000000000")),
        category_(std::string("General")) {}

Passenger::Passenger(std::string name, 
                    std::string aadhar, 
                    Date dob, 
                    std::string gender, 
                    std::string mobile, 
                    std::string category) :
    name_(name), aadhar_(aadhar), dob_(dob), gender_(gender), mobile_(mobile), category_(category) {}

Passenger::Passenger(const char * name, 
                    const char * aadhar, 
                    Date dob, 
                    const char * gender, 
                    const char * mobile, 
                    const char * category) :
    name_(std::string(name)), 
    aadhar_(std::string(aadhar)), 
    dob_(dob), 
    gender_(std::string(gender)), 
    mobile_(std::string(mobile)), 
    category_(std::string(category)) {}

const Passenger Passenger::sNullPassenger = Passenger();