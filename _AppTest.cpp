/*
 * NAME - RAJAS BHATT
 * ROLL NO - 19CS30037
 * VERSION - 1.0
 */
#include "Booking.h"
#include "Passenger.h"
#include "BookingClass.h"
#include "Date.h"
#include "Station.h"
#include "Railways.h"

using namespace std;


/*----------------------------------------------------------------------*/
/*                      MODIFIABLE CONSTANTS                            */    

const double Booking::sBaseFarePerKM = 0.5;                 // Base Fare per KM
const double Booking::sACSurcharge = 50;                    // AC Surcharge
const double Booking::sLuxuryTaxPercent = 0.25;             // Percentage of Luxury Tax as a percentage of final computed fare
                                                            // Final Fare = ( 1 + sLuxuryTaxPercent)*(Fare after AC Surcharge)

/*----------------------------------------------------------------------*/

/* EDIT WHEN REQUIRED HERE */
/* -------------------------------------------------------------------- */
/*                      MODIFIABLE CONSTANTS                            */   
// LUXURY STATUS OF VARIOUS CLASSES
bool ACChairCar::sLuxury = false;
bool SecondSitting::sLuxury = false;
bool ACFirstClass::sLuxury = true;
bool AC2Tier::sLuxury = false;
bool AC3Tier::sLuxury = false;
bool FirstClass::sLuxury = true;
bool Sleeper::sLuxury = false;

// FARE STATUS OF VARIOUS CLASSES
float ACChairCar::sFareLoadFactor = 1.25;
float SecondSitting::sFareLoadFactor = 0.5;
float ACFirstClass::sFareLoadFactor = 3;
float AC2Tier::sFareLoadFactor = 2;
float FirstClass::sFareLoadFactor = 2;
float AC3Tier::sFareLoadFactor = 1.75;
float Sleeper::sFareLoadFactor = 1;

/* DO NOT EDIT ANYTHING UNDER THIS LINE */
/* ---------------------------------------------------------------------*/

void BookingApplication(){
    // Bookings by different booking classes
    // <BookingClasses>::Type() returns the constant object of the respective type
    Booking b1(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021), ACFirstClass::Type());
    Booking b2(Station("Kolkata"), Station("Delhi"), Date(5, 3, 2021), AC2Tier::Type());
    Booking b3(Station("Mumbai"), Station("Kolkata"), Date(17, 3, 2021), FirstClass::Type());
    Booking b4(Station("Mumbai"), Station("Delhi"), Date(23, 3, 2021), AC3Tier::Type());
    Booking b5(Station("Chennai"), Station("Delhi"), Date(25, 4, 2021), ACChairCar::Type());
    Booking b6(Station("Chennai"), Station("Kolkata"), Date(7, 5, 2021), Sleeper::Type());
    Booking b7(Station("Mumbai"), Station("Delhi"), Date(19, 5, 2021), SecondSitting::Type());
    Booking b8(Station("Delhi"), Station("Mumbai"), Date(22, 5, 2021), SecondSitting::Type());
    // Output the bookings done where sBookings is the collection of bookings done
    vector<Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
        cout << *(*it);
    }
    return;
}

int main(){
    BookingApplication();
    return 0;
}