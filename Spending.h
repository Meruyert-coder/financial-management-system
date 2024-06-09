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
#include"Date.h"

using namespace std;

class Spending
{
public:
	double SumSpend;
	string Category;
	Date* date;
public:
	Spending();
	Spending(const Spending& other);
	~Spending();
	void Sums(double S);
	void Categorys(std::string C);
	double Sums();
	string Categorys();
};

