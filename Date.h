#pragma once

class Date
{
public:
	mutable int Day;
	mutable int Month;
	mutable int Year;
public:
	Date();
	Date(int D);
	Date(int D, int M, int Y);
	void setDay(int D);
	void setMonth(int M);
	void setYear(int Y);
	int getDay();
	int getMonth();
	int getYear();
};

