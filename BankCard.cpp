#include "BankCard.h"

BankCard::BankCard()
{
	Name = "";
	SumIncrease = 0;
}

BankCard::BankCard(string S):BankCard()
{
	Name = S;
}

BankCard::BankCard(string S, double D):BankCard(S)
{
	SumIncrease += D;
}

BankCard::BankCard(const BankCard& other)
{
	Name = other.Name;
	SumIncrease = other.SumIncrease;
}
void BankCard::setName(string N)
{
	Name = N;
}

string BankCard::getName()const
{
	return Name;
}

void BankCard::setSumIncrease(double I)
{
	SumIncrease += I;
}

double BankCard::getSumIncrease()
{
	return SumIncrease;
}

//void BankCard::Replenishment(double R, int D, int M, int Y) const
//{
//	SumIncrease += R;
//	date->setDay(D);
//	date->setMonth(M);
//	date->setYear(Y);
//}

bool BankCard::operator<(const BankCard& other) const
{
	return Name < other.Name;
}

bool BankCard::operator==(const BankCard& other) const
{
	return Name == other.Name;
}
//BankCard& BankCard::operator=(const BankCard& other)
//{
//	if (this != &other) {
//		Name = other.Name;
//		SumIncrease = other.SumIncrease;
//		delete Spend;
//		Spend = new Spending(*other.Spend);
//	}
//	return *this;
//}
ostream& operator<<(ostream& out, const BankCard& Card)
{
	out << Card.Name;
	return out;
}
