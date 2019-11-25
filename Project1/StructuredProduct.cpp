#include "StructuredProduct.h"



StructuredProduct::StructuredProduct()
{
}

StructuredProduct::StructuredProduct(bool var)
{
	cout << "Podaj nazwe produktu:\n";
	cin >> name;
	cout << "Podaj nazwe jednostki zarzadzajacej produktem:\n";
	cin >> managerName;
	cout << "Podaj kapital:\n";
	cin >> contribution;
	cout << "Podaj przewidywany procentowy zysk (w ulamku dziesietnym):\n";
	cin >> profit;
	cout << "Dodales element!\n\n";
}

void StructuredProduct::info() {
	cout << "Nazwa: " << name
		<< "\n Nazwa jednostki zarzadzajacej: " << managerName
		<< "\n Kapital: " << contribution
		<< "\n Przewidywany procentowy roczny zysk: " << profit * 100 << "%\n\n";

}

void StructuredProduct::edit() {
	short int checker = 0;
	cout << "Podaj wartosc operacji, ktora chcesz wykonac:\n"
		<< "1. Zwieksz kapital.\n"
		<< "2. Zmniejsz kapital.\n";
	cin >> checker;
	while (checker < 1 || checker> 2) {
		cout << "Podaj wartosc 1 lub 2!\n\n";
		cin >> checker;
	}
	switch (checker) {
	case 1:
		double increase;
		cout << "Podaj wartosc, o ktora chcesz zwiekszyc kapital:\n\n";
		cin >> increase;
		*this += increase;
		break;
	default:
		double decrease;
		cout << "Podaj wartosc, o ktora chcesz zmniejszyc kapital:\n\n";
		cin >> decrease;
		*this -= increase;
		break;
	}
}

StructuredProduct::~StructuredProduct()
{
}
