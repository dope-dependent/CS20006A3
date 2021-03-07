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

void UnitTests(){
    Station::StationUnitTest();
    Date::DateUnitTest();
    Railways::RailwaysUnitTest();
    Booking::BookingUnitTest();
    BookingClasses::BookingClassUnitTest();
    AC2Tier::UnitTestAC2Tier();
    // ACChairCar::UnitTestACChairCar();
    // ACFirstClass::UnitTestACFirstClass();
    // AC3Tier::UnitTestAC3Tier();
    // Sleeper::UnitTestSleeper();
    // FirstClass::UnitTestFirstClass();
    // SecondSitting::UnitTestSecondSitting();
    return;
}

int main(){
    UnitTests();
    return 0;
}