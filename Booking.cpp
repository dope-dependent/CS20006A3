// Project Headers
#include "Booking.h"

#include <cmath>
#include <typeinfo>     // For type information in polymorphism

/*----------------------------------------------------------------------*/
/*                      MODIFIABLE CONSTANTS                            */    

const double Booking::sBaseFarePerKM = 0.5;                 // Base Fare per KM
const double Booking::sACSurcharge = 50;                    // AC Surcharge
const double Booking::sLuxuryTaxPercent = 0.25;             // Percentage of Luxury Tax as a percentage of final computed fare
                                                           // Final Fare = ( 1 + sLuxuryTaxPercent)*(Fare after AC Surcharge)

/*----------------------------------------------------------------------*/



// Code

// Construct a Booking
/* DESIGN CONSIDERATIONS
        fareComputed_ has been initialised to 0 (and then modified), 
        this is because the object needs to be initialised first. It also cannot be made 
        static because we need to initialise all static variables before an object is
        constructed.
*/
Booking::Booking(Station fromStation, Station toStation, Date d, const BookingClasses &c, Passenger *p)
        : fromStation_(fromStation), 
        toStation_(toStation), 
        bookingDate_(d),
        class_(c), 
        bookingStatus_(true), 
        bookingMessage_("BOOKING SUCEEDED:"),
        pnr_(sBookingPNRSerial++),
        fareComputed_(0.0),
        passenger_(p) {
                // Add the booking to the booking list
                fareComputed_ = ComputeFare();
                sBookings.push_back(this);         // Add a pointer to the current object to the sBookings vector
        }


// Copy constructor
// Copy assignment operator has been blocked
Booking::Booking(const Booking &b)
        : fromStation_(b.fromStation_),         
        toStation_(b.toStation_),                  // Role of the copy constructors in the Station and Date classes
        bookingDate_(b.bookingDate_),
        class_(b.class_),                             
        bookingStatus_(true), 
        bookingMessage_("BOOKING SUCEEDED:"),
        pnr_(b.pnr_),                 // Definitely a copy of an existing booking is not a new booking
        fareComputed_(b.fareComputed_),
        passenger_(b.passenger_) {}


// Computing the fare using the ComputeFare method by the algorithm specified
double Booking::ComputeFare() const {
        double dist = Railways::IndianRailways().GetDistance(fromStation_.GetName(), toStation_.GetName());     // Get the distance
        double fare = dist*sBaseFarePerKM;      // Multiply by base fare
        fare = fare * class_.GetLoadFactor();   // Multiply by the load factor
        if( class_.IsAc()) fare += sACSurcharge;        // Add ACSurcharge
        if( class_.IsLuxury()) fare = fare*(1+ sLuxuryTaxPercent);      // Add Luxury Tax
        return round(fare);     // Round to the nearest integer
}

// Overloaded << operator for efficient booking printing
ostream & operator<<(ostream &os, const Booking & booking){
        os << booking.bookingMessage_ << endl;
        os << "PNR Number = " << booking.pnr_ << endl;
        os << "From Station = " << booking.fromStation_.GetName() << endl;
        os << "To Station = " << booking.toStation_.GetName() << endl;
        os << "Travel Date = " << booking.bookingDate_.GetDate() << endl;
        os << booking.class_;
        os << "Fare = " << booking.fareComputed_ << endl;       
        cout<< endl;
        return os;
}

// Set all the static constants properly, these things need not be modified by the user
vector<Booking*> Booking::sBookings = {};
int Booking::sBookingPNRSerial = 1;


// Unit Test for the BookingClass
void Booking::BookingUnitTest(){        
        // ACFirstClass Booking from Delhi to Mumbai
        Booking b1 = Booking(Station("Delhi"), Station("Mumbai"), Date(23,4,2020), ACFirstClass::Type());

        // Empirical calculations estimate fare at (1447*0.5*3 + 50)*1.25 = 2776
        if (b1.ComputeFare() != 2776){
                std::cout << "ERROR: Fare not as expected, should be 2776, is = "<< b1.ComputeFare() << std::endl;
        }
        else{
                std::cout << "Fare as expected \n";
                std::cout << b1 << std::endl;
        }       

        Booking b2 = Booking(Station("Bangalore"), Station("Chennai"), Date(23,5,2021), ACChairCar::Type());

        // Empirical calculations estimate fare at (350*0.5*1.25 + 50) = 269
        if (b2.ComputeFare() != 269){
                std::cout << "ERROR: Fare not as expected, should be 269, is = "<< b2.ComputeFare() << std::endl;
        }
        else{
                std::cout << "Fare as expected \n";
                std::cout << b2 << std::endl;
        }     

        Booking b3 = Booking(Station("Kolkata"), Station("Mumbai"), Date(30, 7, 2021), AC2Tier::Type());
        // Empirical calculations estimate fare at (2014*0.5*2 + 50) = 2064
        if (b3.ComputeFare() != 2064){
                std::cout << "ERROR: Fare not as expected, should be 2064, is = "<< b3.ComputeFare() << std::endl;
        }
        else{
                std::cout << "Fare as expected \n";
                std::cout << b3 << std::endl;
        }

        Booking b4 = Booking(Station("Chennai"), Station("Delhi"), Date(2,2,2022), AC3Tier::Type());
        // Empirical calculations estimate fare at (2180*0.5*1.75 + 50) = 1958
        if (b4.ComputeFare() != 1958){
                std::cout << "ERROR: Fare not as expected, should be 1958, is = "<< b4.ComputeFare() << std::endl;
        }
        else{
                std::cout << "Fare as expected \n";
                std::cout << b4 << std::endl;
        }

        Booking b5 = Booking(Station("Delhi"), Station("Bangalore"), Date(5,6,2021), FirstClass::Type());
        // Empirical calculations estimate fare at (2150*0.5*2)*1.25 = 2688
        if (b5.ComputeFare() != 2688){
                std::cout << "ERROR: Fare not as expected, should be 2688, is = "<< b5.ComputeFare() << std::endl;
        }
        else{
                std::cout << "Fare as expected \n";
                std::cout << b5 << std::endl;
        }

        // Checking the list of bookings
        std::vector<Booking *>::iterator it = sBookings.begin();
        while( it != sBookings.end()){
                std::cout << *(*it) << std::endl;
                it++;
        }
        

        // Printing the class of each booking
        it = sBookings.begin();
        while(it != sBookings.end()){
                std::cout << "PNR = " << (*it)->pnr_ << " Class : " << (*it)->class_.GetName() << std::endl;
                it++;
        }


        
}