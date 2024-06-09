#include "Profit.h"

Profit::Profit()
{
	Increase = 0;
	date = new Date();
}

Profit::Profit(double P):Profit()
{
	Increase = P;
}

Profit::Profit(const Profit& other)
{
	Increase = other.Increase;
	SumIncrease = other.SumIncrease;
	date = new Date(*(other.date));
}

//Profit::Profit(const BankCard& card) {
//	
//	SumIncrease = card.SumIncrease;
//	date = new Date(*(card.date));
//}

Profit::~Profit()
{
	if (date != nullptr) {
		date = nullptr;
	}
	delete date;
}
