//�������� ������� ���������� ������������� ���������.
//������� ������ ����� ��������� �����������:
//- ������� ������ ��������� � ����;
//- ���������� ��������� � ����;
//- �������� ������. ������ ������� ��������� � ������������ ���������.
//- ������������ ������� �� �������� � ����������:
//  - ����;
//  - ������;
//  - �����;
//- ������������ ��������� �� ������������ ������:
//  - ���-3 ������:
//    - ������;
//    - �����.
//  - ���-3 ���������:
//    - ������;
//    - �����.
//- ���������� ������� � ��������� � ����.

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

