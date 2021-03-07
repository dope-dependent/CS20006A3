/*
 * NAME - RAJAS BHATT
 * ROLL NO - 19CS30037
 * VERSION - 1.0
 */

#include "Booking.h"
#include "BookingClass.h"
#include "Passenger.h"
#include "Date.h"
#include "Station.h"
#include "Railways.h"

#include <vector>

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
    // Application for Booking
    const Station mum("Mumbai");
    const Date d(12, 6, 2021);
    const BookingClasses & obj = AC3Tier::Type();
    vector <Booking> allBookings{};
    allBookings.push_back(Booking(Station("Delhi"), mum, Date(17,5,2021), obj));
    allBookings.push_back(Booking(mum, Station("Kolkata"), d, Sleeper::Type()));
    allBookings.push_back(Booking(Station("Kolkata"), Station("Bangalore"), Date(15,5,2021), ACFirstClass::Type()));
    allBookings.push_back(Booking(Station("Bangalore"),
                            Station("Chennai"),Date(15,6,2020), 
                            AC2Tier::Type(), 
                            Passenger("Sachin","1233 3444 4567",Date(19,7,1987),"M", "+919872567333", "General")));

    allBookings.push_back(Booking(Station("Chennai"), Station("Delhi"), Date(19,8,2021), FirstClass::Type()));
    allBookings.push_back(Booking(mum, Station("Bangalore"), d, obj));
    allBookings.push_back(Booking(mum, Station("Chennai"), d, AC2Tier::Type()));

    const Booking b1(mum, Station("Kolkata"), Date(5, 6, 2021), AC2Tier::Type());

    vector<Booking>::iterator it;
    for(it = allBookings.begin(); it != allBookings.end() ; it++ ){
        cout << *it << endl;
    }
    cout << b1 << endl;
    return;
}

int main(){

    BookingApplication();

    return 0;
}