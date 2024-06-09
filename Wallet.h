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

