#include <string>
#include "Spending.h"

Spending::Spending()
{
	SumSpend = 0;
	Category = "";
	date = new Date();
}

Spending::Spending(const Spending& other)
{
	SumSpend = other.SumSpend;
	Category = other.Category;
	date = new Date(*(other.date));
}

Spending::~Spending()
{
	if (date != nullptr) {
		date = nullptr;
	}
	delete date;
}

void Spending::Sums(double S)
{
	SumSpend = S;
}

void Spending::Categorys(string C)
{
	Category = C;
}

double Spending::Sums()
{
	return SumSpend;
}

string Spending::Categorys()
{
	return Category;
}
