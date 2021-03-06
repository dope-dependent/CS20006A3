/*
 * NAME - RAJAS BHATT
 * ROLL NO - 19CS30037
 * VERSION - 1.0
 */

// Beginning of Railways.h
#ifndef _RAILWAYS_H
#define _RAILWAYS_H

#include "Station.h"           // To implement the GetDistance method

#include <vector>   // For list implementation
#include <string>   // For all the C++ strings required
// Indian Railways is a singleton class
// It has a static object of the form Railways::IndianRailways()

class Railways{

private:
    static const std::vector<std::string> sStations;                // List of stations
    static const std::vector<std::vector<float>> sDistStations;     // Distances between stations
    Railways(){ /*Do nothing*/}                     // Private constructor to avoid construction from outside
    Railways(const Railways &);                     // Private copy constructor
    Railways & operator=(const Railways &);         // Private copy assignment
    ~Railways() {}                                  // Private destructor, we don't need that (Meyer's Singleton)

public: 
    static const Railways & IndianRailways();       // We access the member methods from here
    float GetDistance(const Station &a, const Station &b) const;  // Const to ensure smooth calling from constant singleton object IndianRailways
    
    // Static function for UnitTest
    static void RailwaysUnitTest();
};

#endif //_RAILWAYS_H