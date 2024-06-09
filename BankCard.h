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