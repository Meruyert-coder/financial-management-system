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

#include <iostream>
#include"MoneyStorage.h"
#include"BankCard.h"
#include"Wallet.h"
#include "Date.h"
#include "Spending.h"
#include "Profit.h"
#include <set>
#include<map>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int n;
	string s;
	cout << "\nВыберите необходимое финансовое хранилище:\n"
		"1. Банковская карта;\n"
		"2. Электронный кошелек.\n";
	cin >> n;
	switch (n)
	{
	case 1: {
		int a = 1;
		set<BankCard>Cards;
		multimap<BankCard, Profit>mapProfit;
		multimap<BankCard, Spending>mapSpending;
		while (a)
		{
			cout << "\nВыберите необходимое действие с банковской картой:\n"
				"0. Завершение работы с банковскими картами;\n"
				"1. Добавление банковской карты;\n"
				"2. Удаление банковской карты;\n"
				"3. Список существующих карт;\n"
				"4. Проверка суммы денег на карте;\n"
				"5. Пополнение карты;\n"
				"6. Внесение затрат;\n";
			cin >> a;
			switch (a) {
			case 0: {break; }
			case 1: {
				int b;
				cout << "Введите добовляемое количество карт: ";
				cin >> b;
				for (int i = 0; i < b; i++) {
					cout << "\nВведите название " << i + 1 << " добовляемой карты:\n";
					cin >> s;
					BankCard bankCard(s);
					Cards.insert(bankCard);
				}
				break;
			}
			case 2: {
				int h = 1;
				while (h != 0) {
					cout << "\nВыберите режим удаления:\n"
						"0. Выход из режима удаления;\n"
						"1. Удаление одной конкретной карты;\n"
						"2. Удаление всех карт.\n";
					cin >> h;
					switch (h) {
					case 0: {break; }
					case 1: {
						cout << "\nВведите название  удаляемой карты:\n";
						cin >> s;
						for (auto bc = Cards.begin(); bc != Cards.end();) {
							if (bc->getName() == s) {
								cout << "\nУдаляемая карта: " << bc->getName() << endl;
								mapProfit.erase(bc->getName());
								mapSpending.erase(bc->getName());
								bc = Cards.erase(bc);
								cout << "Карта " << s << " успешно удалена.\n";
								break;
							}
							else {
								bc++;
							}
						}

						break;
					}
					case 2: {
						mapSpending.clear();
						mapProfit.clear();
						Cards.clear();
						cout << "\nВсе карты удалены.\n";
						break;
					}
					default: cout << "\nНеправильно сделаный выбор!\n";
						break;
					}
				}
				break;
			}
			case 3: {
				if (!Cards.empty()) {
					cout << "Количество существующих карт: " << Cards.size() << "\nВаши банковские карты:\n";
					for (auto bc = Cards.begin(); bc != Cards.end(); bc++) {
						cout << bc->getName() << endl;
					}
				}
				else {
					cout << "\nНет банковских карт.\n";
				}
				break;
			}
			case 4: {
				cout << "Выберите карту для проверки суммы на карте: ";
				cin >> s;
		
				for (auto bc = Cards.begin(); bc != Cards.end();) {
					if (bc->getName() == s) {
						if (mapProfit.size() == 0) {
							cout << "На карте " << bc->getName() << " нет данных о пополнениях.\n";
							break;
						}
						else {
							double totalIncrease = 0;
							for (auto it = mapProfit.begin(); it != mapProfit.end(); ++it) {
								totalIncrease += it->second.Increase;
							}
							cout << "Общая сумма на карте " << bc->getName() << " равна " << totalIncrease << " грн.\n";
							auto Pr = mapProfit.find(bc->getName());
							if (Pr != mapProfit.end()) {
								for (auto mp = Pr; mp != mapProfit.upper_bound(bc->getName()); mp++) {
									cout << "Дата пополнения: " << mp->second.date->getDay() << "." << mp->second.date->getMonth() <<
										"." << mp->second.date->getYear() << "\nСумма поповнення: " << mp->second.Increase << endl;
								}
							}
							else {
								cout << "На карте " << bc->getName() << " нет данных о пополнениях.\n";
							}
						}
						bc++;
					}
					else {
						bc++;
					}
				}
				break;
			}
			case 5: {
				double Sum;
				int	day, month, year;
				cout << "Выберите карту, которую необходимо пополнить: ";
				cin >> s;
				cout << "Введите сумму пополнения карты: ";
				cin >> Sum;
				cout << "Введите дату пополнения:\n"
					"день: ";
				cin >> day;
				cout << "месяц: ";
				cin >> month;
				cout << "год: ";
				cin >> year;
				for (auto bc = Cards.begin(); bc != Cards.end();) {
					if (bc->getName() == s) {
						Profit profit(Sum);
						profit.date->setDay(day);
						profit.date->setMonth(month);
						profit.date->setYear(year);
						mapProfit.insert({ bc->getName(), profit });
						cout << "Сумма пополнения: " << profit.Increase << "\nДата пополнения: " << profit.date->getDay() <<
							"." << profit.date->getMonth() << "." << profit.date->getYear() << "\n\n";
						break;
					}
					else {
						bc++;
					}
				}
				break;
			}
			case 6: {
				string c;
				double sum;
				int day, month, year;
				cout << "Выберите карту с которой были сделаны затраты: ";
				cin >> s;
				cout << "\nВ какой категории были сделаны затраты: ";
				cin >> c;
				cout << "\nКакая сумма была затрачена: ";
				cin >> sum;
				cout << "\nВведите дату затраты:\n"
					"День: ";
				cin >> day;
				cout << "\nМесяц: ";
				cin >> month;
				cout << "\nГод: ";
				cin >> year;
				cout << endl;
				for (auto bc = Cards.begin(); bc != Cards.end();) {
					if (bc->getName() == s) {
						Spending spending;
						spending.Sums(sum);
						spending.Categorys(c);
						spending.date->setDay(day);
						spending.date->setMonth(month);
						spending.date->setYear(year);
						mapSpending.insert({ bc->getName(), spending});
						cout << "Сумма затрати: " << spending.SumSpend << "\nВ категории: " << spending.Category << "\nДата пополнения: " << spending.date->getDay() <<
							"." << spending.date->getMonth() << "." << spending.date->getYear() << "\n\n";
						break;
					}
					else {
						bc++;
					}
				}
				break;
			}
			}
		}
		break;
	}
		  /*case 2: {
			  set<string>Wallets;
			  while (a)
			  {
				  cout << "\nВыберите необходимое действие с электронным кошельком:\n"
					  "0. Завершение работы с электронными кошельками;\n"
					  "1. Добавление электронного кошелька;\n"
					  "2. Удаление электронного кошелька;\n"
					  "3. Список существующих кошельков;\n";
				  cin >> a;
				  switch (a) {
				  case 0: {break; }
				  case 1: {
					  cout << "Введите добовляемое количество кошельков: ";
					  cin >> b;
					  for (int i = 0; i < b; i++) {
						  cout << "\nВведите название " << i + 1 << " добовляемого кошелька:\n";
						  cin >> s;
						  Wallets.insert(s);
					  }
					  break;
				  }
				  case 2: {
					  cout << "Введите удаляемое количество кошельков: ";
					  cin >> b;
					  for (int i = 0; i < b; i++) {
						  cout << "\nВведите название " << i + 1 << " удаляемого кошелька:\n";
						  cin >> s;
						  Wallets.erase(s);
					  }
					  break;
				  }
				  case 3: {
					  if (!Wallets.empty()) {
						  cout << "Количество существующих кошельков: " << Wallets.size() << "\nВаши электронные кошельки:\n";
						  for (string h : Wallets) {
							  cout << h << endl;
						  }
					  }
					  else {
						  cout << "Нет электронных кошельков.\n";
					  }
				  }
				  }
			  }
			  break;
		  }*/
	default: cout << "Неправильно сделаный выбор!\n";
		break;
	}
}