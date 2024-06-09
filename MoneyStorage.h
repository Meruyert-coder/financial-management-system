//Создайте систему управления персональными финансами.
//Система должна иметь следующие возможности:
//- Наличие разных кошельков и карт;
//- Пополнение кошельков и карт;
//- Внесение затрат. Каждая затрата относится к определенной категории.
//- Формирование отчетов по затратам и категориям:
//  - день;
//  - неделя;
//  - месяц;
//- Формирование рейтингов по максимальным суммам:
//  - Топ-3 затрат:
//    - неделя;
//    - месяц.
//  - Топ-3 категорий:
//    - неделя;
//    - месяц.
//- Сохранение отчетов и рейтингов в файл.

#pragma once
#include <iostream>
#include "Spending.h"
#include "Profit.h"
#include "Date.h"

using namespace std;

class MoneyStorage abstract
{
public:
	string Name;
	mutable double SumIncrease;
	Date* date;
	Profit* profit;
	Spending* Spend;
public:
	MoneyStorage();
	MoneyStorage(MoneyStorage& other);
	~MoneyStorage();
	virtual void setName(string N)abstract;
	virtual string getName()const abstract;
	virtual void setSumIncrease(double I)abstract;
	virtual double getSumIncrease()abstract;
	//virtual void Replenishment(double R, int D, int M, int Y)const abstract;
	friend ostream& operator<< (ostream& out, const MoneyStorage& Money);
};
