#pragma once
#include<iostream>
using namespace std;

template <class T> class WalletDivider
{
	T * savingsArray;
	int index;
public:
	WalletDivider();
	~WalletDivider();

	void addElem() {
		T newElem(true);
		savingsArray[index] = newElem;
		index++;
	}

	void deleteElem() {
		if (index > 0) {
			short int checker;
			cout << "\nPodaj numer elementu, ktory chcesz usunac:\n";
			showElems();
			cin >> checker;
			while (checker < 1 || checker >index + 1) {
				cout << "\nPodaj wlasciwy numer z zakresu od 1 do " << index + 1 << ".\n";
				cin >> checker;
			}
			for (int i = checker - 1; i < index; i++) {
				savingsArray[i] = savingsArray[i + 1];
			}
			index--;
		}
		else
			cout << "\nBrak elementow do usuniecia.\n\n";
	}

	void editElems() {
		if (index > 0) {
			short int checker;
			cout << "\nPodaj numer elementu, ktory chcesz edytowac:\n";
			showElems();
			cin >> checker;
			while (checker < 1 || checker >index + 1) {
				cout << "\nPodaj wlasciwy numer z zakresu od 1 do " << index + 1 << ".\n";
				cin >> checker;
			}
			savingsArray[checker - 1].edit();
		}
		else
			cout << "Brak elementow do edytowania.\n\n";
	}

	void showElems() {
		if (index > 0) {
			for (int i = 0; i < index; i++) {
				cout << (i + 1)<<".\n ";
				savingsArray[i].info();
				cout << "\n";
			}
		}
		else
			cout << "\nBrak elementow do wyswietlenia.\n";
	}

	double sumProfits(double years) {
		double sum = 0;
		for (int i = 0; i < index; i++) {
			sum+=savingsArray[i].countProfits(years);
		}
		return sum;
	}

};

template <class T> WalletDivider <T>::WalletDivider() {
	savingsArray = new T[100];
	index = 0;
}

template <class T> WalletDivider <T>::~WalletDivider() {
	delete[] savingsArray;
}
