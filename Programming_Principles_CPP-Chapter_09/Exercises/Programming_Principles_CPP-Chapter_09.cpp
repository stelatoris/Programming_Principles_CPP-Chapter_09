// Programming_Principles_CPP-Chapter_09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"





Month operator++(Month& m)
{
    m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
}

enum class Day {
    monday, tuesday, wedensday, thursday, friday, saturday, sunday
};

/*class Year {                            // year in [min:max) range
    static const int min = 1800;
    static const int max = 2200;
public:
    class Invalid {};
    Year(int x) :y{ x } { if (x < min || max <= x)throw Invalid{}; }    
    int year() { return y; }
private:
    int y;
};*/



Date::Date()
    :y{ default_date().year() },
    m{ default_date().month() },
    d{ default_date().day() }
{
    if (!is_valid()) throw Invalid{};
}

const Date& default_date()
{
    static Date dd{ 2001,Month::jan,1 };
    return dd;
}

bool Date::is_valid()
{
    if (m  < 1 || m > 12) return false;
    //...
}

void Date::add_day(int n)
{
    //...
}

Month int_to_month(int x)
{
    if (x<int(Month::jan) || int(Month::dec) < x) error("bad month");
    return Month(x);
}

void f(int x, int y)
try {



}
catch (Date::Invalid) {
    error("invalid date");
}







int main()
{
    Date holiday{ 1978, Month::jul, 4 };

    holiday = Date{ 1978, Month::dec, 24 };

    cout << Date{ 1978, Month::dec, 24 };
}
