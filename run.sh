# g++ -Wall Station.cpp Railways.cpp RailwaysTest.cpp -o RailwaysTest
# ./RailwaysTest
# rm RailwaysTest

# g++ -Wall Station.cpp Railways.cpp StationTest.cpp -o StationTest
# ./StationTest
# rm StationTest

# g++ -Wall BookingClass.cpp BookingClass_test.cpp -o BookingClass_test
# ./BookingClass_test
# rm BookingClass_test

# g++ -Wall Date.cpp Date_test.cpp -o Date_test
# ./Date_test
# rm Date_test

# g++ -Wall Date.cpp Station.cpp Railways.cpp BookingClass.cpp Booking.cpp Passenger.cpp _App.cpp -o _App
# ./_App
# rm _App

g++ -Wall Station.cpp BookingClass.cpp Booking.cpp Passenger.cpp Railways.cpp Date.cpp _App.cpp -o _App
./_App