/*
 * NAME - RAJAS BHATT
 * ROLL NO - 19CS30037
 * VERSION - 1.0
 */

#include "Station.h"        
#include "Railways.h"       // To use the GetDistance Functionality of the Railways Class

#include <iostream>

// Station using c++ string
Station::Station(std::string name) : name_(name){}

// Station using const char * (C style string)
Station::Station(const char * name) : name_(std::string(name)) {}

// Copy constructor
Station::Station(const Station & station) : name_(station.name_) {}     // We may need this while facilitating Bookings

// Copy assignment
Station & Station::operator=(const Station & station){
    name_ = station.name_;
    return *this;
}

// The GetDistance method
float Station::GetDistance(const Station & b) const {
    // Passes the current station and the station to which we need the distance
    return Railways::IndianRailways().GetDistance(*this, b);
}

// Overloading the << operator for debugging purpose
std::ostream & operator<<(std::ostream &os, const Station &s){
    os << s.GetName();
    return os;
}

// Unit Test for the Station Class
void Station::StationUnitTest(){
    std::cout << "\n ++++ UNIT TEST FOR Station CLASS ++++ \n";
    // Station Creation Test
    Station Mumbai_("Mumbai");
    Station Delhi_("Delhi");
    Station Kolkata_(std::string("Kolkata"));
    Station Bangalore_("Bangalore");
    Station Chennai_(std::string("Chennai"));
    Station Hyderabad_("Hyderabad");

    // Getting the names of each station
    std::cout << "\nGetName() testing \n";
    std::cout << Mumbai_.GetName() << std::endl;
    std::cout << Delhi_.GetName() << std::endl;
    std::cout << Bangalore_.GetName() << std::endl;
    std::cout << Mumbai_.GetName() << std::endl;
    std::cout << Chennai_.GetName() << std::endl;
    std::cout << Hyderabad_.GetName() << std::endl;

    std::cout << "\nGetDistance() testing \n";
    // Getting the distances between various Stations
    std::cout << "Mumbai    -> Delhi         :   " << Mumbai_.GetDistance(Delhi_) << std::endl;
    std::cout << "Mumbai    -> Bangalore     :   " << Mumbai_.GetDistance(Bangalore_) << std::endl;
    std::cout << "Mumbai    -> Kolkata       :   " << Mumbai_.GetDistance(Kolkata_) << std::endl;
    std::cout << "Mumbai    -> Chennai       :   " << Mumbai_.GetDistance(Chennai_) << std::endl;
    std::cout << "Delhi     -> Bangalore     :   " << Delhi_.GetDistance(Bangalore_) << std::endl;
    std::cout << "Delhi     -> Kolkata       :   " << Delhi_.GetDistance(Kolkata_) << std::endl;
    std::cout << "Delhi     -> Chennai       :   " << Delhi_.GetDistance(Chennai_) << std::endl;
    std::cout << "Bangalore -> Kolkata       :   " << Bangalore_.GetDistance(Kolkata_) << std::endl;
    std::cout << "Bangalore -> Chennai       :   " << Bangalore_.GetDistance(Chennai_) << std::endl;
    std::cout << "Kolkata   -> Chennai       :   " << Kolkata_.GetDistance(Chennai_) << std::endl;

    // Check for any discrepencies
    if ( Mumbai_.GetDistance(Delhi_) != 1447.0 ){
        std::cout << "Error in Distance from Mumbai to Delhi \n";
    }
    else if ( Chennai_.GetDistance(Mumbai_) != 1338.0 ){
        std::cout << "Error in Distance from Chennai to Mumbai \n";
    }
    else if ( Bangalore_.GetDistance(Kolkata_) != 1871.0 ){
        std::cout << "Error in Distance from Bangalore to Chennai \n";
    }
    else if (Bangalore_.GetDistance(Bangalore_) != 0){
        std::cout << "Distance from Bangalore to Bangalore is not zero \n";
    }
    else if (Kolkata_.GetDistance(Delhi_) != 1472.0){
        std::cout << "Error in Distance from Kolkata to Delhi \n";
    }
    else {
        std::cout << "\n All clear in distances \n";
    }

    
    // Testing the << operator
    std::cout << "\n << operator testing\n";
    std::cout << Delhi_ << std::endl;
    std::cout << Mumbai_ << std::endl;
    std::cout << Kolkata_ << std::endl;  
    std::cout << Chennai_ << std::endl;
}



