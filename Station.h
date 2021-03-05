/*
 * NAME - RAJAS BHATT
 * ROLL NO - 19CS30037
 * VERSION - 1.0
 */

#ifndef _STATION_H
#define _STATION_H

#include <string>

class Station{
    // Any name is allowed for a station, this is to promote expansions.
    std::string name_;              // Station HAS-A name, accumulation
public:  
    
    Station(std::string name = ""); // Default constructor, user should be able to construct a station
    Station(const char*);
    Station(const Station &);       // Copy Constructor    
    Station & operator=(const Station &);   // Copy Assignment operator

    // GetName() function as required by the customer, done inline because the code is very small
    inline std::string GetName() const { return name_; }   
    float GetDistance(const Station &s) const;        // Get the distance to another station
                                                      // const because no member attribute changed 
    // Overloading the << operator to print the name of the station
    friend std::ostream & operator<<(std::ostream &os, const Station &s);  

    static void StationUnitTest();
};

#endif // _STATION_H