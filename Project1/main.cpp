#include<iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include"Contract.h"
#include"WalletDivider.h"
#include"Estate.h"
#include"IkeIkze.h"
#include"Investment.h"
#include"InvestmentFund.h"
#include"StructuredProduct.h"

using namespace std;

WalletDivider<Estate> estates;
WalletDivider<IkeIkze> ikeIkze;
WalletDivider<Investment> investments;
WalletDivider<Contract> contracts;
WalletDivider<InvestmentFund> investmentFunds;
WalletDivider<StructuredProduct> structuredProducts;

void addAssets() {
	short int checker = 0;
	cout << "\nPodaj numer aktywa, ktore chcesz dodac:\n"
		<<"1. Lokata\n"
		<<"2. Jednostki uczestnictwa w funduszu inwestycyjnym\n"
		<<"3. Kontrakt\n"
		<<"4. Produkt strukturyzowany\n"
		<<"5. Nieruchomosc\n"
		<<"6. IKE / IKZE\n\n";
		cin >> checker;
	while (checker < 1 || checker > 6) {
		cout << "\nPodaj poprawna wartosc z zakresu 1-6. \n\n ";
		cin>>checker;
	}
	switch (checker) {
	case 1:
		investments.addElem();
		break;
	case 2:
		investmentFunds.addElem();
		break;
	case 3:
		contracts.addElem();
		break;
	case 4:
		structuredProducts.addElem();
		break;
	case 5:
		estates.addElem();
		break;
	default:
		ikeIkze.addElem();
		break;
	}

}

void removeAssets() {
	short int checker = 0;
	cout << "\nPodaj numer aktywa, ktore chcesz usunac:\n"
		<< "1. Lokata\n"
		<< "2. Jednostki uczestnictwa w funduszu inwestycyjnym\n"
		<< "3. Kontrakt\n"
		<< "4. Produkt strukturyzowany\n"
		<< "5. Nieruchomosc\n"
		<< "6. IKE / IKZE\n\n";
	cin >> checker;
	while (checker < 1 || checker > 6) {
		cout << "Podaj poprawna wartosc z zakresu 1-6. \n\n ";
		cin >> checker;
	}
	switch (checker) {
	case 1:
		investments.deleteElem();
		break;
	case 2:
		investmentFunds.deleteElem();
		break;
	case 3:
		contracts.deleteElem();
		break;
	case 4:
		structuredProducts.deleteElem();
		break;
	case 5:
		estates.deleteElem();
		break;
	default:
		ikeIkze.deleteElem();
		break;
	}
}

void showAssets() {
	cout << "\nI. Lokaty:\n";
	investments.showElems();
	cout << "\nII. Jednostki uczestnictwa w funduszu inwestycyjnym:\n";
	investmentFunds.showElems();
	cout << "\nIII. Kontrakty:\n";
	contracts.showElems();
	cout << "\nIV. Produkty strukturyzowane:\n";
	structuredProducts.showElems();
	cout << "\nV. Nieruchomosci:\n";
	estates.showElems();
	cout<< "\nVI. IKE / IKZE:\n";
	ikeIkze.showElems();

}

void editAssets() {
	short int checker = 0;
	cout << "\nPodaj numer aktywa, ktore chcesz edytowac:\n"
		<< "1. Lokata\n"
		<< "2. Jednostki uczestnictwa w funduszu inwestycyjnym\n"
		<< "3. Kontrakt\n"
		<< "4. Produkt strukturyzowany\n"
		<< "5. Nieruchomosc\n"
		<< "6. IKE / IKZE\n\n";
	cin >> checker;
	while (checker < 1 || checker > 6) {
		cout << "Podaj poprawna wartosc z zakresu 1-6. \n\n ";
		cin >> checker;
	}
	switch (checker) {
	case 1:
		investments.editElems();
		break;
	case 2:
		investmentFunds.editElems();
		break;
	case 3:
		contracts.editElems();
		break;
	case 4:
		structuredProducts.editElems();
		break;
	case 5:
		estates.editElems();
		break;
	default:
		ikeIkze.editElems();
		break;
	}
}

void simulation() {
	double years, sum = 0;
	cout << "\nPodaj liczbe lat, po ktorych interesuje Cie stan Twoich oszczednosci:\n\n";
	cin >> years;
	sum += estates.sumProfits(years) + 
		ikeIkze.sumProfits(years) +
		investments.sumProfits(years) +
		contracts.sumProfits(years) +
		investmentFunds.sumProfits(years) +
		structuredProducts.sumProfits(years);
	cout << "\nPo tym czasie Twoje oszczednosci beda wynosic " << sum << " zl. \n\n";
}



int main() {
	//ifstream ifs("save.ros", ios::binary);
	//ifs.read((char *)&estates, sizeof(estates));

	ofstream ofs("save.ros", ios::binary);

	cout << "Witaj w Twoim Portfelu Oszczednosciowym!\n\n";

	while (1) {
		short int checker =0;
		cout << "\nPodaj numer operacji, ktora chcesz wykonac:\n"
			<<"1. Dodaj oszczednosci.\n"
			<< "2. Usun oszczednosci.\n"
			<< "3. Edytuj dane posiadanych aktywow.\n"
			<< "4. Wyswietl stan portfela.\n"
			<< "5. Symuluj stan oszczednosci.\n"
			<< "6. Wyjdz z aplikacji.\n\n "; 
			cin >> checker;
			while (checker < 1 || checker>6) {
				cout << "\nPodaj wlasciwa wartosc z zakresu 1-6! \n\n";
				cin >> checker;
			}

		switch (checker) {
		case 1:
			addAssets();
			break;
		case 2:
			removeAssets();
			break;
		case 3:
			editAssets();
			break;
		case 4:
			showAssets();
			break;
		case 5:
			simulation();
			break;
		default:
			cout<<"\nMilego dnia! ";
			chrono::seconds dura(3);
			this_thread::sleep_for(dura);
			return 0;
		}	
		ofs.write((char *)&estates, sizeof(estates));
		ofs.write((char *)&ikeIkze, sizeof(ikeIkze));
		ofs.write((char *)&investments, sizeof(investments));
		ofs.write((char *)&contracts, sizeof(contracts));
		ofs.write((char *)&investmentFunds, sizeof(investmentFunds));
		ofs.write((char *)&structuredProducts, sizeof(structuredProducts));
	}

}