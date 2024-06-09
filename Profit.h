#pragma once
#include"Date.h"
class Profit
{
public:
	double Increase;
	double SumIncrease;
	Date* date;
	Profit();
	Profit(double P);
	Profit(const Profit& other);
	//Profit(const BankCard& card);
	Profit(Profit&&) = default;
	~Profit();
	//void Replenishment(double R);
};

