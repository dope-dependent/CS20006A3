/*
 * NAME - RAJAS BHATT
 * ROLL NO - 19CS30037
 * VERSION - 1.0
 */
#ifndef _BOOKINGCLASS_H
#define _BOOKINGCLASS_H

#include <string>       // std::string


class BookingClasses{
    protected:
        const std::string name_;                     // The name of the class
        const std::string seatOrBerth_;        // Seat or berth specification, kept string because we can have new configurations as well
        const bool acStatus_;                  // AC or Non-AC
        const int tiers_;                      // Tiers
        BookingClasses(std::string, std::string, bool, int);  // Constructor, made protected because we don't need to construct a BookingClass
                                                                   // object from outside
        BookingClasses(const BookingClasses &);                // Protected Copy constructor
        BookingClasses & operator=(const BookingClasses & );   // Protected Copy assignment

    public:
        virtual inline ~BookingClasses() {}                 // Destrucctor which does nothing, made virtual for polymorphism
        virtual inline float GetLoadFactor() const = 0;     // Make sure that this is not called, pure virtual function
        // Getter methods for subclasses
        inline std::string GetName() const { return name_; };
        std::string IsSitting() const;
        inline bool IsAc() const { return acStatus_; };     // Returns whether AC or not (true or false)

        /* Note regarding the LUXURY Functions
            Since it has been mentioned that the luxury status can be changed
            form time to time, it has been decided to make it a STATIC VARIABLE
            which can be easily modified from the application code, therefore
            GetLuxury() and IsLuxury have been made pure virtual functions
            so that they can be implemented in the Derived Classes
        */

        virtual inline bool IsLuxury() const = 0;      // Pure Virtual Function
        inline int GetNumberOfTiers() const { return tiers_;};  // Get the number of tiers, simple function, inlined
        friend std::ostream & operator<<(std::ostream &os, const BookingClasses & obj);     // Overloading the << operator

        // Unit test function for the booking class?
        static void BookingClassUnitTest();
};

// Defining the SeatClass and the BerthClass, intermediate in the hierarchy
class SeatClass : public BookingClasses{
    protected:
        SeatClass(std::string, bool, int);             // Assigning a seat class, 'seatOrBerth_' is set to "Seat" be default
    public:
        inline ~SeatClass(){}
};

class BerthClass : public BookingClasses{
    protected:
        BerthClass(std::string, bool, int);             // Assigning a berth class, 'seatOrBerth_' is set to "Birth" be default
    public:
        inline ~BerthClass(){}
};
// Splitting the BerthClass into ThreeBerthClass and TwoBerthClass

class TwoBerthClass : public BerthClass{
    protected:
        TwoBerthClass(std::string, bool);
    public:
        inline ~TwoBerthClass() {}
};

class ThreeBerthClass : public BerthClass{
    protected:
        ThreeBerthClass(std::string, bool);
    public:
        inline ~ThreeBerthClass() {}
};

// Implementation of all the Seat Classes
class ACChairCar : public SeatClass {
    private:
        ACChairCar();           // Private Constructor to avoid construction of any object from outside
        ~ACChairCar() {}        
        static bool sLuxury;
        static float sFareLoadFactor;
    public: 
        inline float GetLoadFactor() const { return sFareLoadFactor; }   // GetLoadFactor method
        static const ACChairCar & Type();               // In order to use <BookingClass>::Type() functionality, we need a static method
                                                        // otherwise we can't use something without instantiation
        static void UnitTestACChairCar();               // Unit Test function
        inline bool IsLuxury() const { return sLuxury; }
}; 


class SecondSitting : public SeatClass {
    private:
        static float sFareLoadFactor;
        SecondSitting();    // Private Constructor to avoid construction of any object from outside
        ~SecondSitting() {} // Private Destructor
        static bool sLuxury;

    public:                          
        inline float GetLoadFactor() const { return sFareLoadFactor; }   // GetLoadFactor method
        static const SecondSitting & Type();               // In order to use <BookingClass>::Type() functionality, we need a static method
        static void UnitTestSecondSitting();                  // Unit Test function
        inline bool IsLuxury() const { return sLuxury; }
}; 


// Implementation of all the Berth Classes
// ACFirstClass IS-A TwoBerthClass
class ACFirstClass : public TwoBerthClass {
    private:
        static float sFareLoadFactor;
        ACFirstClass();    // Private Constructor to avoid construction of any object from outside
        ~ACFirstClass() {}  // Private Destructor
        static bool sLuxury;

    public:
        inline float GetLoadFactor() const { return sFareLoadFactor; }   // GetLoadFactor method
        static const ACFirstClass & Type();   // In order to use <BookingClass>::Type() functionality, we need a static method
        static void UnitTestACFirstClass();   // Unit Test function
        inline bool IsLuxury() const { return sLuxury; }
};

// AC2Tier IS-A TwoBerthClass
class AC2Tier : public TwoBerthClass {
    private:
        static float sFareLoadFactor;
        AC2Tier();    // Private Constructor to avoid construction of any object from outside
        ~AC2Tier() {}
        static bool sLuxury;


    public:
        inline float GetLoadFactor() const { return sFareLoadFactor; }   // GetLoadFactor method
        static const AC2Tier & Type();        // In order to use <BookingClass>::Type() functionality, we need a static method
        static void UnitTestAC2Tier();        // Unit Test function
        inline bool IsLuxury() const { return sLuxury; }
};

// FirstClass IS-A TwoBerthClass
class FirstClass : public TwoBerthClass {
    private:
        static float sFareLoadFactor;
        FirstClass();    // Private Constructor to avoid construction of any object from outside
        ~FirstClass() {} // Private Destructor
        static bool sLuxury;

    public:
        inline float GetLoadFactor() const { return sFareLoadFactor; }   // GetLoadFactor method
        static const FirstClass & Type();     // In order to use <BookingClass>::Type() functionality, we need a static method
        static void UnitTestFirstClass();     // Unit Test function
        inline bool IsLuxury() const { return sLuxury; }
};

// AC3Tier IS-A ThreeBerthClass
class AC3Tier : public ThreeBerthClass {
    private:
        static float sFareLoadFactor;
        AC3Tier();    // Private Constructor to avoid construction of any object from outside
        ~AC3Tier() {}   // Private Destructor
        static bool sLuxury;

    public:
        inline float GetLoadFactor() const { return sFareLoadFactor; }   // GetLoadFactor method
        static const AC3Tier & Type();    // In order to use <BookingClass>::Type() functionality, we need a static method
        static void UnitTestAC3Tier();    // Unit Test function
        inline bool IsLuxury() const { return sLuxury; }
};

// Sleeper IS-A ThreeBerthClass
class Sleeper : public ThreeBerthClass {
    private:
        static float sFareLoadFactor;
        Sleeper();    // Private Constructor to avoid construction of any object from outside
        ~Sleeper() {}   // Private Destructor
        static bool sLuxury;

    public:
        inline float GetLoadFactor() const { return sFareLoadFactor; }   // GetLoadFactor method
        static const Sleeper & Type();    // In order to use <BookingClass>::Type() functionality, we need a static method
        static void UnitTestSleeper();    // Unit Test function
        inline bool IsLuxury() const { return sLuxury; }
};

#endif // _BOOKINGCLASS_H
