#include "Wallet.h"

Wallet::Wallet()
{
	Name = "";
	SumIncrease = 0;
}

Wallet::Wallet(string S, double D)
{
	Name = S;
	SumIncrease = D;
}

void Wallet::setName(string N)
{
	Name = N;
}

string Wallet::getName()
{
	return Name;
}

void Wallet::setSumIncrease(double I)
{
	SumIncrease = I;
}

double Wallet::getSumIncrease()
{
	return SumIncrease;
}

void Wallet::Replenishment(double R)
{
	SumIncrease += R;
}

