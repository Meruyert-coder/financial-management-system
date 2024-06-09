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
#include<iostream>
#include "MoneyStorage.h"
using namespace std;
class BankCard:public MoneyStorage
{	
public:
	string Name;
	double SumIncrease;
public:
	BankCard();
	BankCard(string S);
	BankCard(string S, double D);
	BankCard(const BankCard& other);
	void setName(string N)override;
	string getName()const override;
	void setSumIncrease(double I)override;
	double getSumIncrease()override;
	//void Replenishment(double R, int D, int M, int Y)const override;
	bool operator<(const BankCard& other) const;
	bool operator==(const BankCard& other) const;
	//BankCard& operator=(const BankCard& other);
	friend ostream& operator<< (ostream& out, const BankCard& Card);
};