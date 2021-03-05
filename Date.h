/*
 * NAME - RAJAS BHATT
 * ROLL NO - 19CS30037
 * VERSION - 1.0
 */

// Begin Date.h
#ifndef _DATE_H
#define _DATE_H

#include <iostream>
#include <string>
#include <map>

class Date{
    private:
        int day_;
        int month_;
        int year_;
        static std::map<int,std::string> sMonthIndex;     // The Month indexes remain static as requested
        static std::map<int,std::string> sDayIndex;       // The Month indexes remain static as requested
        static std::map<std::string, int> sMonthDays;     // Keeps track of the number of days in the month

    public:
        Date(int,int,int);              // Construct the dates from three integers
        Date(const Date &);             // Copy constructor
        Date &operator=(const Date &);  // Copy assignment
        ~Date();                        // Destructor
        void PrintDate() const;         // Print the date in the format mentioned above
        std::string GetDate() const;    // Get the date in the format mentioned as a string
        // To print the date in the requested format
        // << operators have to be overloaded to use them in their natural syntax
        friend std::ostream & operator<<(std::ostream &os, const Date &d);      

        // Unit Test Static Function for the Date class
        static void DateUnitTest();
};

#endif // _DATE_H
