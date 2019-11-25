#include "IkeIkze.h"



IkeIkze::IkeIkze() {


}

void IkeIkze::edit() {
	short int checker = 0;
	cout << "Podaj wartosc operacji, ktora chcesz wykonac:\n"
		<< "1. Zwieksz kapital.\n"
		<< "2. Zmniejsz kapital.\n";
	cin >> checker;
	while (checker < 1 || checker> 2) {
		cout << "Podaj wartosc 1 lub 2!\n";
		cin >> checker;
	}
	switch (checker) {
	case 1:
		double increase;
		cout << "Podaj wartosc, o ktora chcesz zwiekszyc kapital:\n";
		cin >> increase;
		*this += increase;
		break;
	default:
		double decrease;
		cout << "Podaj wartosc, o ktora chcesz zmniejszyc kapital:\n";
		cin >> decrease;
		*this -= increase;
		break;
	}
}

IkeIkze::IkeIkze(bool var) {
	cout << "Podaj nazwe IKE/IKZE:\n";
	cin >> name;
	cout << "Podaj, typ produktu, na ktorym zalozone jest IKE/IKZE\n";
	cin >> product;
	cout << "Podaj kapital na koncie:\n";
	cin >> contribution;
	cout << "Podaj przewidywany procentowy roczny zysk (w ulamku dziesietnym):\n";
	cin >> profit;
	cout << "Dodaleœ element!\n\n";

}

void IkeIkze::info() {
	cout << "Nazwa: " << name
		<< "\n Wklad: " << contribution
		<< "\n Przewidywany procentowy roczny zysk: " << profit * 100 << "%"
		<< "\n Produkt:" << product<<"\n\n";

}

IkeIkze::~IkeIkze()
{
}
