#include "Contract.h"
#include <iostream>
using namespace std;

Contract::Contract() {}

Contract::Contract(bool var)
{
	cout << "Podaj przedmiot kontraktu:\n";
	cin >> name;
	cout << "Podaj wklad wlasny:\n";
	cin >> contribution;
	cout << "Podaj przewidywany procentowy zysk (w ulamku dziesietnym):\n";
	cin >> profit;
	cout << "Dodales element!\n\n";

}

void Contract::info() {
	cout << "Przedmiot kontraktu: "<<name 
		<< "\n Wklad: " << contribution 
		<< "\n Przewidywany procent zysku: " << profit*100 << "%\n\n";
}

void Contract::edit() {
	short int checker =0;
	cout << "Podaj wartosc operacji, ktora chcesz wykonac:\n"
		<< "1. Zwieksz wklad wlasny.\n"
		<< "2. Zmniejsz wklad wlasny.\n\n";
	cin >> checker;
	while (checker < 1 || checker> 2) {
		cout << "Podaj wartosc 1 lub 2!\n\n";
		cin >> checker;
	}
	switch (checker) {
	case 1:
		double increase;
		cout << "Podaj wartosc, o ktora chcesz zwiekszyc wklad wlasny:\n\n";
		cin >> increase;
		*this += increase;
		break;
	default: 
		double decrease;
		cout << "Podaj wartosc, o ktora chcesz zmniejszyc wklad wlasny:\n\n";
		cin >> decrease;
		*this -= increase;
		break;
	}
}

Contract::~Contract()
{
}
