/*
 * NAME - RAJAS BHATT
 * ROLL NO - 19CS30037
 * VERSION - 1.0
 */

#include "Railways.h"       // Include the header file first

#include <algorithm>        // Use for the find() method
#include <iostream>         // Use for the Unit Test


// All the stations in the form of a vector
// Since these are fixed, we kept them in the .cpp file
const std::vector <std::string> Railways::sStations = {std::string("Mumbai"),
                                        std::string("Delhi"),
                                        std::string("Bangalore"), 
                                        std::string("Kolkata"), 
                                        std::string("Chennai")};

// All the distance between the stations in the form of a matrix
// Since these distances are not expected to change, we keep them in the .cpp file itself
const std::vector<std::vector<float>> Railways::sDistStations = {
    {0,    1447, 981 , 2014, 1338},
    {1447, 0   , 2150, 1472, 2180},
    {981 , 2150, 0   , 1871, 350 },
    {2014, 1472, 1871, 0   , 1659},
    {1338, 2180, 350 , 1659, 0   }
};

// Railways::IndianRailways() provides access to the singleton object which helps us to fetch distances
// This is called Meyer's Singleton
const Railways & Railways::IndianRailways(){
    static Railways obj;        // obj is created only once, no pointers needed at all
    return obj;     
}

// The functionality using the GetDistance function using iterators and static casting.
float Railways::GetDistance(const Station &a, const Station &b) const {
    std::string sa = a.GetName();
    std::string sb = b.GetName();

    std::vector<std::string>::const_iterator it1 = find(sStations.begin(), sStations.end(), sa);
    std::vector<std::string>::const_iterator it2 = find(sStations.begin(), sStations.end(), sb);

    size_t i1 = static_cast<size_t>(it1 - sStations.begin());
    size_t i2 = static_cast<size_t>(it2 - sStations.begin());
    return sDistStations.at(i1).at(i2);         // Vector access using at method
}

// Unit test for the railways class
void Railways::RailwaysUnitTest(){
    // Create the stations
    std::cout << "\n ++++ UNIT TEST FOR Railways CLASS ++++ \n";
    Station Mumbai_("Mumbai");
    Station Delhi_("Delhi");
    Station Kolkata_("Kolkata");
    Station Bangalore_("Bangalore");
    Station Chennai_("Chennai");

    std::cout << "Mumbai    -> Delhi         :   " << Railways::IndianRailways().GetDistance(Mumbai_, Delhi_) << std::endl;
    std::cout << "Mumbai    -> Bangalore     :   " << Railways::IndianRailways().GetDistance(Mumbai_, Bangalore_) << std::endl;
    std::cout << "Mumbai    -> Kolkata       :   " << Railways::IndianRailways().GetDistance(Mumbai_, Kolkata_) << std::endl;
    std::cout << "Mumbai    -> Chennai       :   " << Railways::IndianRailways().GetDistance(Mumbai_, Chennai_) << std::endl;
    std::cout << "Delhi     -> Bangalore     :   " << Railways::IndianRailways().GetDistance(Delhi_, Bangalore_) << std::endl;
    std::cout << "Delhi     -> Kolkata       :   " << Railways::IndianRailways().GetDistance(Delhi_, Kolkata_) << std::endl;
    std::cout << "Delhi     -> Chennai       :   " << Railways::IndianRailways().GetDistance(Delhi_, Chennai_) << std::endl;
    std::cout << "Bangalore -> Kolkata       :   " << Railways::IndianRailways().GetDistance(Bangalore_, Kolkata_) << std::endl;
    std::cout << "Bangalore -> Chennai       :   " << Railways::IndianRailways().GetDistance(Bangalore_, Chennai_) << std::endl;
    std::cout << "Kolkata   -> Chennai       :   " << Railways::IndianRailways().GetDistance(Kolkata_, Chennai_) << std::endl;

    // Now in reverse order
    std::cout <<"\nStation names but in reverse order \n";
    std::cout << "Delhi     -> Mumbai        :   " << Railways::IndianRailways().GetDistance(Delhi_, Mumbai_) << std::endl;
    std::cout << "Chennai   -> Bangalore     :   " << Railways::IndianRailways().GetDistance(Chennai_, Bangalore_) << std::endl;
    std::cout << "Chennai   -> Kolkata       :   " << Railways::IndianRailways().GetDistance(Chennai_, Kolkata_) << std::endl;
    std::cout << "Kolkata   -> Delhi         :   " << Railways::IndianRailways().GetDistance(Kolkata_, Delhi_) << std::endl;
    
    if ( Mumbai_.GetDistance(Delhi_) != 1447.0 ){
        std::cout << "ERROR in Distance from Mumbai to Delhi \n";
    }
    else if ( Chennai_.GetDistance(Mumbai_) != 1338.0 ){
        std::cout << "ERROR in Distance from Chennai to Mumbai \n";
    }
    else if ( Bangalore_.GetDistance(Kolkata_) != 1871.0 ){
        std::cout << "ERROR in Distance from Bangalore to Chennai \n";
    }
    else if (Bangalore_.GetDistance(Bangalore_) != 0){
        std::cout << "Distance from Bangalore to Bangalore is not zero \n";
    }
    else if (Kolkata_.GetDistance(Delhi_) != 1472.0){
        std::cout << "ERROR in Distance from Kolkata to Delhi \n";
    }
    else if (Chennai_.GetDistance(Delhi_) != 2180.0){
        std::cout << "ERROR in Distance from Chennai to Delhi \n";
    }
    else {
        std::cout << "\n All clear in distances \n";
    }

    std::cout << "\nTesting if the class is really singleton \n";
    if ( &Railways::IndianRailways() != &Railways::IndianRailways() ){
        std::cout << "ERROR : Different instances of Railways returned at different intervals\n";
    }
    else {
        std::cout << "The class returns same instances even when called at different times\n";
        std::cout << "Address : " << &Railways::IndianRailways() << "\n\n";
    }
    // Railways a;         // Error, constructor private
    // Railways b = new Railways();      // Error, constructor private
}