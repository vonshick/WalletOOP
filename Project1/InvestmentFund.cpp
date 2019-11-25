#include "InvestmentFund.h"



InvestmentFund::InvestmentFund()
{
}

InvestmentFund::InvestmentFund(bool var)
{
	cout << "Podaj nazwe funduszu:\n";
	cin >> name;
	cout << "Podaj liczbe zakupionych jednostek:\n";
	cin >> unitCount;
	cout << "Podaj wklad finansowy:\n";
	cin >> contribution;
	cout << "Podaj przewidywany procentowy roczny zysk (w ulamku dziesietnym):\n";
	cin >> profit;
	cout << "Dodales element!\n\n";
}

void InvestmentFund::info() {
	cout << "Nazwa funduszu: " << name
		<< "\n Wklad: " << contribution
		<< "\n Przewidywany procentowy roczny zysk: " << profit * 100 << "%"
		<< "\n Liczba zakupionych jednostek:" << unitCount << "\n\n";

}

void InvestmentFund::edit() {
	short int checker = 0;
	cout << "Podaj wartosc operacji, ktora chcesz wykonac:\n"
		<< "1. Zwieksz wklad finansowy.\n"
		<< "2. Zmniejsz wklad finansowy.\n\n";
	cin >> checker;
	while (checker < 1 || checker> 2) {
		cout << "Podaj wartosc 1 lub 2!\n\n";
		cin >> checker;
	}
	switch (checker) {
	case 1:
		double increase;
		cout << "Podaj wartosc, o ktora chcesz zwiekszyc wklad finansowy:\n\n";
		cin >> increase;
		*this += increase;
		break;
	default:
		double decrease;
		cout << "Podaj wartosc, o ktora chcesz zmniejszyc wklad finansowy:\n\n";
		cin >> decrease;
		*this -= increase;
		break;
	}
}

InvestmentFund::~InvestmentFund()
{
}
