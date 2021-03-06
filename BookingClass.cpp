
#include "BookingClass.h"

#include <iostream>
#include <vector>       // For Polymorphic Hierarchy Unit Test
#include <typeinfo>     // For Polymorphic Hierarchy Unit Test
/* EDIT WHEN REQUIRED HERE */
/* ---------------------------------------------------------------------------------------------- */

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
/* ---------------------------------------------------------------------------------------------- */

// IMPLEMENTATION OF THE VARIOUS CLASSES

// For the Base Class
BookingClasses::BookingClasses(std::string name, std::string seat, bool acStatus, int tiers)
    : name_(name), seatOrBerth_(seat), acStatus_(acStatus), tiers_(tiers) {}


// Slightly different from the mainstream functions, cannot be inlined.
std::string BookingClasses::IsSitting() const {
    if(seatOrBerth_ == "Seat") return std::string("Sitting");
    else return std::string("Sleeping"); 
}

// Overloaded << operator for debugging and using to print the booking class
std::ostream & operator<<(std::ostream &os,const BookingClasses & obj) {
    os << "Travel Class: " << obj.GetName() << std::endl;
    os << " : Mode        : " << obj.IsSitting() << std::endl; 
    if (obj.IsAc()) os << " : Comfort     : AC\n";
    else os << " : Comfort     : Non-AC\n";
    os << " : Bunks       : " << obj.GetNumberOfTiers() << std::endl;
    if( obj.IsLuxury() ) os << " : Luxury      : Yes\n";
    else os << " : Luxury      : No\n";
    return os;
}

// Implementation of the Derived 'SeatClass' and 'BerthClass'

SeatClass::SeatClass(std::string name, bool acStatus, int tiers)
    : BookingClasses(name, std::string("Seat"), acStatus, tiers) {}

BerthClass::BerthClass(std::string name, bool acStatus, int tiers)
    : BookingClasses(name, std::string("Berth"), acStatus, tiers) {}

// Since, we have 5 birth classes, it makes sense to split them into two and three berth classes
// Defining the Two Berth Class
TwoBerthClass::TwoBerthClass(std::string name, bool acStatus)
    : BerthClass(name, acStatus, 2) {}

// Defining the Three Berth Class (contains Three tiers)
ThreeBerthClass::ThreeBerthClass(std::string name, bool acStatus)
    : BerthClass(name, acStatus, 3) {}


// Implementation of ACChairCar Class and all remaining classes
ACChairCar::ACChairCar()
    : SeatClass(std::string("AC Chair Car"), true, 0) { }

const ACChairCar & ACChairCar::Type(){
    // Meyer's Singleton, construct a static constant Object and return it.
    static const ACChairCar obj;
    return obj;
}

// Implementation of the SecondSitting Class
SecondSitting::SecondSitting()
    : SeatClass(std::string("Second Sitting"), false, 0) { }

const SecondSitting & SecondSitting::Type(){
    // Meyer's Singleton
    static const SecondSitting obj;
    return obj;
}

// Implementation of the ACFirstClass Class
ACFirstClass::ACFirstClass()
    : TwoBerthClass(std::string("AC First Class"), true) { }
const ACFirstClass & ACFirstClass::Type(){
    // Meyer's Singleton
    static const ACFirstClass obj;   
    return obj;
}

// Implementation of the AC2TierClass 
AC2Tier::AC2Tier()
    : TwoBerthClass(std::string("AC 2 Tier"), true) { }
const AC2Tier & AC2Tier::Type(){
    static const AC2Tier obj;  
    return obj;
}

// FirstClass
FirstClass::FirstClass()
    : TwoBerthClass(std::string("First Class"), false) { }
const FirstClass & FirstClass::Type(){
    static const FirstClass obj;
    return obj;
}

// AC3Tier
AC3Tier::AC3Tier()
    : ThreeBerthClass(std::string("AC 3 Tier"), true) { }
const AC3Tier & AC3Tier::Type(){
    static const AC3Tier obj;  
    return obj;
}

// Sleeper
Sleeper::Sleeper()
    : ThreeBerthClass(std::string("Sleeper"), false) { }
const Sleeper & Sleeper::Type(){
    static const Sleeper obj;   
    return obj;
}


// UNIT TEST FUNCTIONS FOR ALL THE LEAF CLASSES
// AC FIRST CLASS
void ACFirstClass::UnitTestACFirstClass(){
    // Declare an AC First Class Object

    std::cout << "\n +++ Attribute Testing  \n";
    if (ACFirstClass::Type().GetName() != std::string("AC First Class")){
        std::cout << " Name = " << ACFirstClass::Type().GetName() << " is not correct \n";
    }
    else{
        std::cout << " Name = " << ACFirstClass::Type().GetName() << " is correct \n";
    }
    
    if (ACFirstClass::Type().IsAc()==0){
        std::cout << " AC Status = ("<< ACFirstClass::Type().IsAc() << ") is not correct \n";
    }
    else{
        std::cout << " AC Status = (" << ACFirstClass::Type().IsAc() << ") is correct \n";
    }

    if (ACFirstClass::Type().GetNumberOfTiers() != 2){
        std::cout << " Number of Tiers = " << ACFirstClass::Type().GetNumberOfTiers() << " is not correct \n";
    }
    else{
        std::cout << " Number of Tiers = " << ACFirstClass::Type().GetNumberOfTiers() << " is correct \n";
    }

    if (ACFirstClass::Type().IsSitting() != std::string("Sleeping")){
        std::cout << " Sitting/Sleeping = " << ACFirstClass::Type().IsSitting() << " is not correct \n";
    }
    else{
        std::cout << " Sitting/Sleeping = " << ACFirstClass::Type().IsSitting() << " is correct \n";
    }

    std::cout << " +++ Static Method Testing \n";
    if (ACFirstClass::Type().GetLoadFactor() != ACFirstClass::sFareLoadFactor){
        std::cout << " Load factor is incorrect \n";
    }
    else std::cout << " Load factor is correct \n";

    if (ACFirstClass::Type().IsLuxury() != ACFirstClass::sLuxury ){
        std::cout << " Luxury status is not correct  \n";
    }
    else std::cout << " Luxury status is correct \n";

    std::cout << " +++ Singleton Testing \n";
    if( &ACFirstClass::Type() != &ACFirstClass::Type()){
        std::cout << " The objects are different, not a singleton class!\n";
    }
    else{
        std::cout << " The objects are the same, a singleton class!\n";
    }

    std::cout << " +++ Checking the << operator \n";
    std::cout << ACFirstClass::Type() << std::endl;

}

// AC 2 TIER
void AC2Tier::UnitTestAC2Tier(){
    // Declare an AC First Class Object
    std::cout << "\n +++ Attribute Testing  \n";
    if (AC2Tier::Type().GetName() != std::string("AC 2 Tier")){
        std::cout << " Name = " << AC2Tier::Type().GetName() << " is not correct \n";
    }
    else{
        std::cout << " Name = " << AC2Tier::Type().GetName() << " is correct \n";
    }
    
    if (AC2Tier::Type().IsAc()==0){
        std::cout << " AC Status = ("<< AC2Tier::Type().IsAc() << ") is not correct \n";
    }
    else{
        std::cout << " AC Status = (" << AC2Tier::Type().IsAc() << ") is correct \n";
    }

    if (AC2Tier::Type().GetNumberOfTiers() != 2){
        std::cout << " Number of Tiers = " << AC2Tier::Type().GetNumberOfTiers() << " is not correct \n";
    }
    else{
        std::cout << " Number of Tiers = " << AC2Tier::Type().GetNumberOfTiers() << " is correct \n";
    }

    if (AC2Tier::Type().IsSitting() != std::string("Sleeping")){
        std::cout << " Sitting/Sleeping = " << AC2Tier::Type().IsSitting() << " is not correct \n";
    }
    else{
        std::cout << " Sitting/Sleeping = " << AC2Tier::Type().IsSitting() << " is correct \n";
    }

    std::cout << " +++ Static Method Testing \n";
    if (AC2Tier::Type().GetLoadFactor() != AC2Tier::sFareLoadFactor){
        std::cout << " Load factor is incorrect \n";
    }
    else std::cout << " Load factor is correct \n";

    if (AC2Tier::Type().IsLuxury() != AC2Tier::sLuxury ){
        std::cout << " Luxury status is not correct  \n";
    }
    else std::cout << " Luxury status is correct \n";

    std::cout << " +++ Singleton Testing \n";
    if( &AC2Tier::Type() != &AC2Tier::Type()){
        std::cout << " The objects are different, not a singleton class!\n";
    }
    else{
        std::cout << " The objects are the same, a singleton class!\n";
    }

    std::cout << " +++ Checking the << operator \n";
    std::cout << AC2Tier::Type() << std::endl;
}

// FIRST CLASS
void FirstClass::UnitTestFirstClass(){
    // Declare an AC First Class Object
    std::cout << "\n +++ Attribute Testing  \n";
    if (FirstClass::Type().GetName() != std::string("First Class")){
        std::cout << " Name = " << FirstClass::Type().GetName() << " is not correct \n";
    }
    else{
        std::cout << " Name = " << FirstClass::Type().GetName() << " is correct \n";
    }
    
    if (FirstClass::Type().IsAc()==1){
        std::cout << " AC Status = ("<< FirstClass::Type().IsAc() << ") is not correct \n";
    }
    else{
        std::cout << " AC Status = (" << FirstClass::Type().IsAc() << ") is correct \n";
    }

    if (FirstClass::Type().GetNumberOfTiers() != 2){
        std::cout << " Number of Tiers = " << FirstClass::Type().GetNumberOfTiers() << " is not correct \n";
    }
    else{
        std::cout << " Number of Tiers = " << FirstClass::Type().GetNumberOfTiers() << " is correct \n";
    }

    if (FirstClass::Type().IsSitting() != std::string("Sleeping")){
        std::cout << " Sitting/Sleeping = " << FirstClass::Type().IsSitting() << " is not correct \n";
    }
    else{
        std::cout << " Sitting/Sleeping = " << FirstClass::Type().IsSitting() << " is correct \n";
    }
    
    std::cout << " +++ Static Method Testing \n";
    if (FirstClass::Type().GetLoadFactor() != FirstClass::sFareLoadFactor){
        std::cout << " Load factor is incorrect \n";
    }
    else std::cout << " Load factor is correct \n";

    if (FirstClass::Type().IsLuxury() != FirstClass::sLuxury ){
        std::cout << " Luxury status is not correct  \n";
    }
    else std::cout << " Luxury status is correct \n";

    std::cout << " +++ Singleton Testing \n";
    if( &FirstClass::Type() != &FirstClass::Type()){
        std::cout << " The objects are different, not a singleton class!\n";
    }
    else{
        std::cout << " The objects are the same, a singleton class!\n";
    }

    std::cout << " +++ Checking the << operator \n";
    std::cout << FirstClass::Type() << std::endl;
}

// AC 3 TIER
void AC3Tier::UnitTestAC3Tier(){
    // Declare an AC First Class Object
    std::cout << "\n +++ Attribute Testing  \n";
    if (AC3Tier::Type().GetName() != std::string("AC 3 Tier")){
        std::cout << " Name = " << AC3Tier::Type().GetName() << " is not correct \n";
    }
    else{
        std::cout << " Name = " << AC3Tier::Type().GetName() << " is correct \n";
    }
    
    if (AC3Tier::Type().IsAc()==0){
        std::cout << " AC Status = ("<< AC3Tier::Type().IsAc() << ") is not correct \n";
    }
    else{
        std::cout << " AC Status = (" << AC3Tier::Type().IsAc() << ") is correct \n";
    }

    if (AC3Tier::Type().GetNumberOfTiers() != 3){
        std::cout << " Number of Tiers = " << AC3Tier::Type().GetNumberOfTiers() << " is not correct \n";
    }
    else{
        std::cout << " Number of Tiers = " << AC3Tier::Type().GetNumberOfTiers() << " is correct \n";
    }

    if (AC3Tier::Type().IsSitting() != std::string("Sleeping")){
        std::cout << " Sitting/Sleeping = " << AC3Tier::Type().IsSitting() << " is not correct \n";
    }
    else{
        std::cout << " Sitting/Sleeping =" << AC3Tier::Type().IsSitting() << " is correct \n";
    }

    std::cout << " +++ Static Method Testing \n";
    if (AC3Tier::Type().GetLoadFactor() != AC3Tier::sFareLoadFactor){
        std::cout << " Load factor is incorrect \n";
    }
    else std::cout << " Load factor is correct \n";

    if (AC3Tier::Type().IsLuxury() != AC3Tier::sLuxury ){
        std::cout << " Luxury status is not correct  \n";
    }
    else std::cout << " Luxury status is correct \n";

    std::cout << " +++ Singleton Testing \n";
    if( &AC3Tier::Type() != &AC3Tier::Type()){
        std::cout << " The objects are different, not a singleton class!\n";
    }
    else{
        std::cout << " The objects are the same, a singleton class!\n";
    }

    std::cout << " +++ Checking the << operator \n";
    std::cout << AC3Tier::Type() << std::endl;
}

// SLEEPER
void Sleeper::UnitTestSleeper(){
    // Declare an AC First Class Object
    std::cout << "\n +++ Attribute Testing  \n";
    if (Sleeper::Type().GetName() != std::string("Sleeper")){
        std::cout << " Name = " << Sleeper::Type().GetName() << " is not correct \n";
    }
    else{
        std::cout << " Name = " << Sleeper::Type().GetName() << " is correct \n";
    }
    
    if (Sleeper::Type().IsAc()==1){
        std::cout << " AC Status = ("<< Sleeper::Type().IsAc() << ") is not correct \n";
    }
    else{
        std::cout << " AC Status = (" << Sleeper::Type().IsAc() << ") is correct \n";
    }

    if (Sleeper::Type().GetNumberOfTiers() != 3){
        std::cout << " Number of Tiers = " << Sleeper::Type().GetNumberOfTiers() << " is not correct \n";
    }
    else{
        std::cout << " Number of Tiers = " << Sleeper::Type().GetNumberOfTiers() << " is correct \n";
    }

    if (Sleeper::Type().IsSitting() != std::string("Sleeping")){
        std::cout << " Sitting/Sleeping = " << Sleeper::Type().IsSitting() << " is not correct \n";
    }
    else{
        std::cout << " Sitting/Sleeping = " << Sleeper::Type().IsSitting() << " is correct \n";
    }
    
    std::cout << " +++ Static Method Testing \n";
    if (Sleeper::Type().GetLoadFactor() != Sleeper::sFareLoadFactor){
        std::cout << " Load factor is incorrect \n";
    }
    else std::cout << " Load factor is correct \n";

    if (Sleeper::Type().IsLuxury() != Sleeper::sLuxury ){
        std::cout << " Luxury status is not correct  \n";
    }
    else std::cout << " Luxury status is correct \n";

    std::cout << " +++ Singleton Testing \n";
    if( &Sleeper::Type() != &Sleeper::Type()){
        std::cout << " The objects are different, not a singleton class!\n";
    }
    else{
        std::cout << " The objects are the same, a singleton class!\n";
    }

    std::cout << " +++ Checking the << operator \n";
    std::cout << Sleeper::Type() << std::endl;
}

// AC CHAIR CAR
void ACChairCar::UnitTestACChairCar(){
    // Declare an AC First Class Object
    std::cout << "\n +++ Attribute Testing  \n";
    if (ACChairCar::Type().GetName() != std::string("AC Chair Car")){
        std::cout << " Name = " << ACChairCar::Type().GetName() << " is not correct \n";
    }
    else{
        std::cout << " Name = " << ACChairCar::Type().GetName() << " is correct \n";
    }
    
    if (ACChairCar::Type().IsAc()==0){
        std::cout << " AC Status = ("<< ACChairCar::Type().IsAc() << ") is not correct \n";
    }
    else{
        std::cout << " AC Status = (" << ACChairCar::Type().IsAc() << ") is correct \n";
    }

    if (ACChairCar::Type().IsSitting() != std::string("Sitting")){
        std::cout << " Sitting/Sleeping = " << ACChairCar::Type().IsSitting() << " is not correct \n";
    }
    else{
        std::cout << " Sitting/Sleeping = " << ACChairCar::Type().IsSitting() << " is correct \n";
    }

    std::cout << " +++ Static Method Testing \n";
    if (ACChairCar::Type().GetLoadFactor() != ACChairCar::sFareLoadFactor){
        std::cout << " Load factor is incorrect \n";
    }
    else std::cout << " Load factor is correct \n";
    if (ACChairCar::Type().IsLuxury() != ACChairCar::sLuxury ){
        std::cout << " Luxury status is not correct  \n";
    }
    else std::cout << " Luxury status is correct \n";

    std::cout << " +++ Singleton Testing \n";
    if( &ACChairCar::Type() != &ACChairCar::Type()){
        std::cout << " The objects are different, not a singleton class!\n";
    }
    else{
        std::cout << " The objects are the same, a singleton class!\n";
    }

    std::cout << " +++ Checking the << operator \n";
    std::cout << ACChairCar::Type() << std::endl;
}

// SECOND SITTING
void SecondSitting::UnitTestSecondSitting(){
    std::cout << "\n +++ Attribute Testing  \n";
    if (SecondSitting::Type().GetName() != std::string("Second Sitting")){
        std::cout << " Name = " << SecondSitting::Type().GetName() << " is not correct \n";
    }
    else{
        std::cout << " Name = " << SecondSitting::Type().GetName() << " is correct \n";
    }
    
    if (SecondSitting::Type().IsAc()==1){
        std::cout << " AC Status = ("<< SecondSitting::Type().IsAc() << ") is not correct \n";
    }
    else{
        std::cout << " AC Status = (" << SecondSitting::Type().IsAc() << ") is correct \n";
    }

    if (SecondSitting::Type().IsSitting() != std::string("Sitting")){
        std::cout << " Sitting/Sleeping = " << SecondSitting::Type().IsSitting() << " is not correct \n";
    }
    else{
        std::cout << " Sitting/Sleeping = " << SecondSitting::Type().IsSitting() << " is correct \n";
    }

    std::cout << " +++ Static Method Testing \n";
    if (SecondSitting::Type().GetLoadFactor() != SecondSitting::sFareLoadFactor){
        std::cout << " Load factor is incorrect \n";
    }
    else std::cout << " Load factor is correct \n";
    if (SecondSitting::Type().IsLuxury() != SecondSitting::sLuxury ){
        std::cout << " Luxury status is not correct  \n";
    }
    else std::cout << " Luxury status is correct \n";

    std::cout << " +++ Singleton Testing \n";
    if( &SecondSitting::Type() != &SecondSitting::Type()){
        std::cout << " The objects are different, not a singleton class!\n";
    }
    else{
        std::cout << " The objects are the same, a singleton class!\n";
    }

    std::cout << " +++ Checking the << operator \n";
    std::cout << SecondSitting::Type() << std::endl;
}


// UNIT TEST FOR THE POLYMORPHIC HIERARCHY USING THE BASE CLASS
void BookingClasses::BookingClassUnitTest(){

    std::cout << "----- POLYMORPHIC FUNCTIONALITY TESTING ----- \n";
    const BookingClasses *c = &SecondSitting::Type();
    std::cout << c->GetName() << " :" << c->GetLoadFactor() << std::endl;
    c = &ACFirstClass::Type();
    std::cout << c->GetName() << " :" << c->GetLoadFactor() << std::endl;

    c = &ACChairCar::Type();
    std::cout << c->GetName() << " :" << c->GetLoadFactor() << std::endl;
    
    c = &AC2Tier::Type();
    std::cout << c->GetName() << " :" << c->GetLoadFactor() << std::endl;

    c = &AC3Tier::Type();
    std::cout << c->GetName() << " :" << c->GetLoadFactor() << std::endl;

    c = &Sleeper::Type();
    std::cout << c->GetName() << " :" << c->GetLoadFactor() << std::endl;

    c = &FirstClass::Type();
    std::cout << c->GetName() << " :" << c->GetLoadFactor() << std::endl;

    std::cout << "----- ATTRIBUTE CHECKING -----\n";
    if(c->name_ != std::string("First Class")) std::cout << "Error in name\n";
    else if(c->acStatus_ == true) std::cout << "Error in the AC Status \n";
    else if(c->seatOrBerth_ == std::string("Seating")) std::cout << "Error in the Seating Status \n";
    else if(c->tiers_ != 2) std::cout << "Error in the number of tiers \n";
    else std::cout << "All attributes are correct. Attribute Checking Successful \n";

    std::cout << "----- GETTER METHOD CHECKING ----- \n";
    if(c->GetName() != std::string("First Class")) std::cout << "Error in name\n";
    else if(c->IsAc() == true) std::cout << "Error in the AC Status \n";
    else if(c->IsSitting() == std::string("Seating")) std::cout << "Error in the Seating Status \n";
    else if(c->GetNumberOfTiers() != 2) std::cout << "Error in the number of tiers \n";
    else std::cout << "All getter methods are correct. Attribute Checking Successful \n";

    std::cout << "----- CHECKING THAT WE REALLY HAVE SINGLETON CLASSES ----- \n";
    std::cout << &ACChairCar::Type() << " " << &ACChairCar::Type() << std::endl;
    std::cout << &ACFirstClass::Type() << " " << &ACFirstClass::Type() << std::endl;
    std::cout << &AC2Tier::Type() << " " << &AC2Tier::Type() << std::endl;
    std::cout << &AC3Tier::Type() << " " << &AC3Tier::Type() << std::endl;
    std::cout << &FirstClass::Type() << " " << &FirstClass::Type() << std::endl;
    std::cout << &Sleeper::Type() << " " << &Sleeper::Type() << std::endl;
    std::cout << &SecondSitting::Type() << " " << &SecondSitting::Type() << std::endl;

    std::vector <const BookingClasses *> cx =  {&ACFirstClass::Type(), 
                                        &ACChairCar::Type(), 
                                        &AC2Tier::Type(),
                                        &AC3Tier::Type(),
                                        &Sleeper::Type(),
                                        &FirstClass::Type(),
                                        &SecondSitting::Type()};

    std::cout << "\n----- CHECKING TYPE IDs IN A VECTOR ----- \n";
    for(std::vector <const BookingClasses *>::iterator it = cx.begin(); it != cx.end() ; it++){
        std::cout << typeid(*it).name() << " : " << typeid(*(*it)).name() << std::endl; 
        std::cout << ** it << std::endl;
    }

    const BookingClasses *cs [7] = {&ACFirstClass::Type(), 
                                        &ACChairCar::Type(), 
                                        &AC2Tier::Type(),
                                        &AC3Tier::Type(),
                                        &Sleeper::Type(),
                                        &FirstClass::Type(),
                                        &SecondSitting::Type()};

    std::cout << "\n----- CHECKING TYPE IDs IN AN ARRAY ----- \n";

    for (int i = 0; i < 7 ; i++){
        std::cout << typeid(cs + i).name() << " : " << typeid(**(cs + i)).name() << std::endl; 
    }


    // std::cout << "\n----- INDIVIDUAL CLASS TESTING ----\n";
    // ACFirstClass::UnitTestACFirstClass();
    // AC2Tier::UnitTestAC2Tier();
    // AC3Tier::UnitTestAC3Tier();
    // FirstClass::UnitTestFirstClass();
    // Sleeper::UnitTestSleeper();
    // ACChairCar::UnitTestACChairCar();
    // SecondSitting::UnitTestSecondSitting();
}