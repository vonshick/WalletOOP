#include "Investment.h"



Investment::Investment()
{
}

Investment::Investment(bool var)
{
	cout << "Podaj nazwe lokaty:\n";
	cin >> name;
	cout << "Podaj nazwe banku:\n";
	cin >> bankName;
	cout << "Podaj roczna stope procentowa (w ulamku dziesietnym):\n";
	cin >> profit;
	cout << "Podaj kapital:\n";
	cin >> contribution;
	cout << "Doda³eœ element!\n\n";
}

void Investment::info() {
	cout << "Nazwa: " << name
		<< "\n Nazwa banku:" << bankName
		<< "\n Wklad: " << contribution
		<< "\n Przewidywany procentowy roczny zysk: " << profit * 100 << "%\n";
}

void Investment::edit() {
	short int checker = 0;
	cout << "Podaj wartosc operacji, ktora chcesz wykonac:\n"
		<< "1. Zwieksz kapital.\n"
		<< "2. Zmniejsz kapital.\n\n";
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

Investment::~Investment()
{
}
