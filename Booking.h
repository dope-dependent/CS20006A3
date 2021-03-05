#ifndef _BOOKING_H
#define _BOOKING_H

#include "Station.h"
#include "BookingClass.h"
#include "Date.h"
#include "Railways.h"
#include "Passenger.h"

#include <vector>

using namespace std;

class Booking{
private:
    const Station fromStation_;                     // Booking HAS A fromStation_, which obviously can't be changed      
    const Station toStation_;                       // Booking HAS A toStation_, which obviously can't be changed
    Date bookingDate_;                              // Booking HAS A bookingDate_, Booking Date can be changed
                                                    // if we add necessary functionality for that
    const BookingClasses & class_;                  // Booking HAS A BookingClass object named class_
    bool bookingStatus_;                            // Booking HAS A bookingStatus_, kept non-constant because
                                                    // at a later stage, we may add functionality to invalidate a booking
    const string bookingMessage_;                   // Booking HAS A bookingMessage_
    const int pnr_;                                 // Booking HAS A pnr_, cannot be changed after the booking is done

    double fareComputed_;                           // Booking HAS A fareComputed_

    Passenger *passenger_;                    // Supports Passenger as a NULLable parameter
    
    // Static Members
    static const double sBaseFarePerKM;              // sBaseFarePerKM is the base fare per KM, modifiable by the user
    static int sBookingPNRSerial;                   // sBookingPNRSerial is the incremental next PNR
    static const double sACSurcharge;                // sACSurcharge is the modifiable sACSurcharge
    static const double sLuxuryTaxPercent;           // sLuxuryTaxPercent is the percentage of fare that is added
    
    // If sLuxuryTaxPercent = x, then fare = fare * (1 + x)
    Booking & operator=(const Booking &);           // Copy Assignment Operator blocked, makes no sense to assign one booking to another

public:
    virtual double ComputeFare() const;             // Virtual Method for various types of Bookings in the Future
    Booking(Station fromStation, Station toStation, Date d, const BookingClasses &c, Passenger *p = nullptr);  
    Booking(const Booking &);                       // Copy Constructor 
    inline virtual ~Booking() {};                   // Virtual Destructor For future extensions
    friend ostream & operator<<(ostream & os, const Booking & booking);       // Overloading the << operator for debugging and display
    static vector <Booking*> sBookings;             // sBookings keeps the list of all the processed booking pointers
                                                    // Kept public because sometimes we may need to print all the Bookings done!

    static void BookingUnitTest();                  // Unit Test for the bookingClass
};


#endif // _BOOKING_H