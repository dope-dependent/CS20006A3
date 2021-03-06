/*
 * NAME - RAJAS BHATT
 * ROLL NO - 19CS30037
 * VERSION - 1.0
 */

#include "Date.h"   // Inclusion of the date header

// Basic constructor uing three integers
/*--------------------------------------------------------------------------*
    Note that basic date error handling has been implemented here, since we
    are entering date in the form of DD/MM/YYYY, we have checked whether the 
    number of days in the selected month is valid and that the month is valid as well
*--------------------------------------------------------------------------*/

Date::Date(int day, int month, int year)
    : day_(day), month_(month), year_(year) {
        if (month >= 12 || month <= 0){
            std::cout << "ERROR: Wrong Month ("<< month << ") entered. Abort Called \n";
            exit(-1);
        }
        // Check for leap year condition
        else if( month == 2){
            if (day <=0 && day > 29) {
                std::cout << "ERROR: Wrong Day ("<< day << "/"<<month<<") entered. Abort Called \n";
                exit(-1);
            }
            else if (day == 29){
                if(year%4 !=0 || (year%4==0 && year%100 ==0 && year%400 !=0 )){
                    std::cout << "ERROR: Wrong Day ("<< day << "/"<<month<<"/"<<year<<") entered. Abort Called \n";
                    exit(-1);
                }
            }
        }
        else {
            if( day <= 0 || day > sMonthDays[sMonthIndex[month]]){
                std::cout << "ERROR: Wrong Day ("<< day << "/"<<month<<"/"<<year<<") entered. Abort Called \n";
                exit(-1);
            }
        }
    }


// Copy constructor, implemented because this is a generic class
Date::Date(const Date &d)
    : day_(d.day_), month_(d.month_), year_(d.year_) {
        // Bit copy is sufficient
    }

// Copy assignment, implemented because this is a generic class
Date & Date::operator=(const Date &d){
    day_ = d.day_;
    month_ = d.month_;
    year_ = d.year_;
    return *this;
}

// Destructor, which basically does nothing as no memory deletion is needed here.
Date::~Date() {}


//Getting the date as a string
std::string Date::GetDate() const{
    std::string final = "";
    if (day_ >= 1 && day_ <= 9) final += "0";
    final += std::to_string(day_);
    final += std::string("/");
    final += sMonthIndex[month_];
    final += std::string("/"); 
    final += std::to_string(year_);

    return final;
}

//Printing the date
void Date::PrintDate() const{
    std::cout<< Date::GetDate() << std::endl;
}


// The << operator overloaded through the GetDate function which returns a date in DD/MM/YYYY format
std::ostream & operator<<(std::ostream &os, const Date &d){
    os << d.GetDate();      // Prints the string
    return os;
}

/* Initialization of the month list
    The month index vs String value has been assigned in a map.
    This is to ensure easy access, could have also been implemented as
    a vector.
*/
std::map<int,std::string> Date::sMonthIndex = {
    {1,std::string("Jan")},
    {2,std::string("Feb")},
    {3,std::string("Mar")},
    {4,std::string("Apr")},
    {5,std::string("May")},
    {6,std::string("Jun")},
    {7,std::string("Jul")},
    {8,std::string("Aug")},
    {9,std::string("Sep")},
    {10,std::string("Oct")},
    {11,std::string("Nov")},
    {12,std::string("Dec")}
};

// Initialisation of the day list
std::map<int, std::string> Date::sDayIndex = {
    {1,std::string("Mon")},
    {2,std::string("Tue")},
    {3,std::string("Wed")},
    {4,std::string("Thu")},
    {5,std::string("Fri")},
    {6,std::string("Sat")},
    {7,std::string("Sun")},
};

// Number of days in the month
std::map<std::string, int> Date::sMonthDays = {
    {std::string("Jan"), 31},
    {std::string("Feb"), 28},
    {std::string("Mar"), 31},
    {std::string("Apr"), 30},
    {std::string("May"), 31},
    {std::string("Jun"), 30},
    {std::string("Jul"), 31},
    {std::string("Aug"), 31},
    {std::string("Sep"), 30},
    {std::string("Oct"), 31},
    {std::string("Nov"), 30},
    {std::string("Dec"), 31}
};


// Unit Test for the Date Class
void Date::DateUnitTest(){
    // Create a new Date
    std::cout << " +++ Construction \n";
    Date d(5, 3, 2021);

    // Print the date
    std::cout << " +++ Overloaded << operator \n";
    std::cout << " " << d << std::endl;
    
    // Get the date in requested format
    std::cout << " " << d.GetDate() << std:: endl;
    if(d.GetDate() != std::string("05/Mar/2021")){
        std::cout << " ERROR : The date is invalid\n";
    }
    else{
        std::cout << " The date is valid\n";
    }

    // Check if the date has 11 characters in the string form
    std::cout << " +++ Check Date length \n";
    if(d.GetDate().length() != 11 ) std::cout << " Error in length, Date length is not 11 characters \n";
    else std::cout << " Date length is 11 characters \n";

    // Use the PrintDate function to print the date
    std::cout << "\t";
    d.PrintDate();

    // Printing the months using iterators
    std::cout << " +++ Month testing using iterators\n";
    for (std::pair<int, std::string> c : sMonthIndex){
        std::cout << " " << c.first << " : " << c.second << std::endl;
    }

    // Some error analysis
    if (sMonthIndex[2] != std::string("Feb")){
        std::cout << " ERROR : Month with index 2 is not February \n";
    }
    else{
        std::cout << " sMonthIndex[2] = Feb\n"; 
    }

    if (sMonthIndex[7] != std::string("Jul")){
        std::cout << " ERROR : Month with index 7 is not July \n";
    }
    else{
        std::cout << " sMonthIndex[7] = Jul\n"; 
    }

    if ( sMonthIndex[d.month_] != std::string("Mar")){
        std::cout << " ERROR : Month with index "<< d.month_<< "is not Mar \n";
    }
    else{
        std::cout << " Fine, the month for " << d << " is Mar\n"; 
    }
    // Now checking the copy constructors and the assignment operators
    std::cout << " +++ Copy Assignment \n";
    Date c(3, 4, 2020);
    std::cout << " c = " << c << "\t&c = " << &c << std::endl;
    std::cout << " d = " << d << "\t&d = " << &d << std::endl;

    std::cout << " --- Executing c = d \n";
    c  = d;
    std::cout << " c = " << c << "\t&c = " << &c << std::endl;
    std::cout << " d = " << d << "\t&d = " << &d << std::endl;

    std::cout << " +++ Copy Construction \n";
    std::cout << " --- Executing c(d) \n";
    Date e(d);
    std::cout << " e = " << e << "\t&e = " << &c << std::endl;
    std::cout << " d = " << d << "\t&d = " << &d << std::endl;


    // std::cout << "Entering a date with errors, abort guaranteed \n";
    // Date f(32, 7, 2002);     
    // Date g(23, 24, 2002);
    Date h(29, 2, 2000);    // Normal Construction
    std::cout << " +++ Constructing (29/2/2020) \n";
    Date i(29, 2, 2020);
    std::cout << " " << i << std::endl;

    // std::cout << " +++ Constructing (29/2/2019) \n";         // Throws error
    // Date j(29, 2, 2019);

    std::cout << " +++ Checking the Month vs Number of Days for a date 13/03/2021\n";
    Date k(13, 3, 2021);

    if(sMonthDays[sMonthIndex[k.month_]] != 31){
        std::cout << " March does not have 31 days!\n";
    }
    else{
        std::cout << " March has 31 days!\n";
    }
    
    std::cout << " +++ Checking the names of days of the week \n";

    for(std::pair<int, std::string> x : sDayIndex){
        std::cout << " " << x.first << " : " << x.second << std::endl;
    }

    std::cout << " +++ Checking if all the attributes are properly assigned \n";
    if(k.day_ != 13) std::cout << " Error in day \n";
    else if(k.month_ != 3) std::cout << " Error in month \n";
    else if(k.year_ != 2021) std::cout << " Error in year \n";
    else std::cout << " All attributes for Date 13/03/2021 are correct!\n";


}   