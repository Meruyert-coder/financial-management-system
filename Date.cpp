#include "Date.h"

Date::Date()
{
	Day = 0;
	Month = 0;
	Year = 0;
}

Date::Date(int D):Date()
{
	Day = D;
}

Date::Date(int D, int M, int Y):Date(D)
{
	Month = M;
	Year = Y;
}

void Date::setDay(int D)
{
	Day = D;
}

void Date::setMonth(int M)
{
	Month = M;
}

void Date::setYear(int Y)
{
	Year = Y;
}

int Date::getDay()
{
	return Day;
}

int Date::getMonth()
{
	return Month;
}

int Date::getYear()
{
	return Year;
}
