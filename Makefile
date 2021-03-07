all:
		g++ -Wall Date.cpp Station.cpp Railways.cpp BookingClass.cpp Booking.cpp Passenger.cpp App.cpp -o App
	
test:
		g++ -Wall Date.cpp Station.cpp Railways.cpp BookingClass.cpp Booking.cpp Passenger.cpp AppTest.cpp -o AppTest

unit-test:
		g++ -Wall Date.cpp Station.cpp Railways.cpp BookingClass.cpp Booking.cpp Passenger.cpp UnitTest.cpp -o UnitTest





