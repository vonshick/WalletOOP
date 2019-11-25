#include "Estate.h"
#include<iostream>


Estate::Estate()
{
}

Estate::Estate(bool var)
{
	cout << "Podaj typ zabudowy:\n";
	cin>>name;
	cout << "Podaj koszt zakupu nieruchomosci:\n";
	cin >> contribution;
	cout << "Podaj powierzchnie:\n";
	cin >> surface;
	cout << "Podaj miasto:\n";
	cin >> city;
	cout << "Podaj ulice:\n";
	cin>>street;
	cout << "Podaj numer domu:\n";
	cin >> houseNumber;
	cout << "Podaj numer mieszkania:\n";
	cin >> flatNumber;
	cout << "Podaj przewidywany procentowy wzrost cen nieruchomosci w tej okolicy (w ulamku dziesietnym):\n";
	cin >> profit;
	cout << "Dodano element!\n\n";
}

void Estate::info() {
	cout << "Typ zabudowy: " << name
		<< "\n Koszt zakupu: " << contribution
		<< "\n Przewidywany wzrost cen nieruchomoœci: " << profit *100 <<"%"
		<< "\n Powierzchnia:" << surface
		<< "\n Miasto: " << city
		<< "\n Ulica: " << street
		<< "\n Numer domu/mieszkania: " << houseNumber << "/" << flatNumber<<"\n\n";
}

Estate::~Estate()
{
}

void Estate::edit() {
	short int checker = 0;
	cout << "Podaj wartosc operacji, ktora chcesz wykonac:\n"
		<< "1. Zwieksz koszty zakupu.\n"
		<< "2. Zmniejsz koszty zakupu.\n\n";
	cin >> checker;
	while (checker < 1 || checker> 2) {
		cout << "Podaj wartosc 1 lub 2!\n\n";
		cin >> checker;
	}
	switch (checker) {
	case 1:
		double increase;
		cout << "Podaj wartosc, o ktora chcesz zwiekszyc koszty zakupu:\n\n";
		cin >> increase;
		*this += increase;
		break;
	default:
		double decrease;
		cout << "Podaj wartosc, o ktora chcesz zmniejszyc koszty zakupu:\n\n";
		cin >> decrease;
		*this -= increase;
		break;
	}
}