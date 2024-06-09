#include "MoneyStorage.h"

MoneyStorage::MoneyStorage()
{
	date = new Date();
	Spend = new Spending();
	profit = new Profit();
}

MoneyStorage::MoneyStorage(MoneyStorage& other)
{
	date = new Date(*(other.date));
	Spend = new Spending(*(other.Spend));
	profit = new Profit(*(other.profit));
}

MoneyStorage::~MoneyStorage()
{
	if (date != nullptr) {
		date = nullptr;
	}
	delete date;
	
	if (Spend != nullptr) {
		Spend = nullptr;
	}
	delete Spend;
}

ostream& operator<<(std::ostream& out, const MoneyStorage& Money)
{
	out << Money.Name;
	return out;
}
