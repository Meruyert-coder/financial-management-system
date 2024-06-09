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
#include "MoneyStorage.h"

using namespace std;
class Wallet :public MoneyStorage
{
	string Name;
	double SumIncrease;
public:
	Wallet();
	Wallet(string S, double D);
	void setName(string N);
	string getName();
	void setSumIncrease(double I);
	double getSumIncrease();
	void Replenishment(double R);
};

