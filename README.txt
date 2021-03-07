NAME    - RAJAS BHATT
ROLL NO - 19CS30037
VERSION - 1.0.0
BUGS    - None Detected yet


COMPILER VERSION
Tested using GNU G++ 9.3.0 and G++ 8.4.0 using both the C++ 98 and C++ 11 standard.
Operating System    -   Ubuntu 20.04 LTS
                        Windows 10

RUNNING THE APPLICATION
Please note, you cannot build the App.cpp AppTest.cpp and UnitTest.cpp files together because each one
of them contains a main() functions. More than one main() function in a given build are not recommended.

***** LINUX *****
*   Linux implementation is made using makefile
*   To run the App.cpp file, enter the following commands 
        make

*   TO run the AppTest.cpp file, enter the following commands
        make test
    
*   To run the UnitTest.cpp file, enter the following commands
        make unit-test

*   To run the App.cpp file and output contents in a txt file (AppOutput.txt)
        make all-text

*   To run the AppTest.cpp file and output contents in a text file (AppTestOutput.txt)
        make test-text 

*   To run the UnitTest.cpp file and output contents in a text file (UnitTestOutput.txt)
        make unit-test-text 

APPLICATION AND TESTING FILES
*   App.cpp
    This contains all the modifiable static constants, and is used to run the app. Please change 
    all changeable constants on the top of this file when required. Do NOT delete anything, you 
    should only change their values. All the modifiable attributes have been mentioned at the top

*   AppTest.cpp
    This contains the application test file which has been given in the assignment. Similar arguments follow 
    as above.

*   UnitTest.cpp
    This contains and calls all the Unit Tests (please check the Testplan.txt file). Depending on the class whose
    unit test you need to call, you can comment out the remaining portion.
    Please note that implementation of these tests is done in the respective .cpp files of the respective classes.


IMPLEMENTATION FILES 
*   Booking.h
    Contains the interface of the 'Booking' class used to create a booking object which simulates a booking

*   Booking.cpp
    Contains the implementation of the 'Booking' class (alongwith hidden static constants which are not
    user-modifiable) used to create a booking object which simulates a Booking. The user modifiable constants
    like the base fare rate, luxury tax, AC surchage have been kept in the respective Application files.

*   BookingClass.h
    Contains the interface of various objects .'BookingClasses' is the abstract base class of the 
    polymorphic hierarchy which contains the required classes like 'ACFirstClass' as leaves. This
    polymorphic hierarchy has many stages, namely the 'SeatClass' and 'BerthClass' stage and the 
    'TwoBerthClass' and 'ThreeBerthClass' stage. Please check the Design.txt file for more details. 

*   BookingClass.cpp
    Contains the implementation of the entire polymorphic hierarchy described above. The user-modifiable
    constants like the FareLoadFactor and the changeable luxury status have been kept in the respective
    Application files.

*   Date.h
    Contains the interface of the Date class used to model a date and required to book a ticket.

*   Date.cpp
    Contains the implementation of the Date class used to model a date in the form of an object. This is
    used as a Booking Date while Booking Tickets.

*   Railways.h
    Contains the interface of the Railways class, which returns the singleton object IndianRailways() which is 
    used for various tasks like calculating distances between stations.

*   Railways.cpp
    Contains the implementation of the Meyer's singleton of the Railways class, which is used to get distances
    between two stations in the GetDistance() method.

*   Station.h
    Contains the interface of a Station in the IndianRailways.

*   Station.cpp
    Contains the implementation of a Station. It also includes the GetDistance() method which fetches the distance 
    from a station to the selected station.

*   Passenger.h
    Contains the modelling of a Passenger which may be extended in the future, this includes attributes like the name,
    date of berth, aadhar no, gender and category

*   Passenger.cpp
    Contains the implementation of the Passenger class. It also contains a nullPassenger attribute, which gives 
    a null passenger when the passenger details are not specified. 

