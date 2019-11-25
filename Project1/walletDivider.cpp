#include<iostream>
using namespace std;

template <class T> class WalletDivider
{
	T * savingsArray;
	int * index;
public:
	WalletDivider();
	~WalletDivider();

	void addElem() {
		T newElem;
		savingsArray[*index] = newElem;
		(*index)++;
	}

	void deleteElem() {
		short int checker;
		cout << "Podaj numer elementu, ktory chcesz usunac:\n";
		showElems();
		cin >> checker;
		while (checker < 1 || checker >(*index) + 1) {
			cout << "Podaj wlasciwy numer z zakresu od 1 do " << (*index) + 1 << ".\n";
			cin >> checker;
		}
		savingsArray[checker - 1] = NULL;
		for (int i = checker - 1; i < index; i++) {
			savingsArray[i] = savingsArray[i + 1];
		}
		(*index)--;
	}

	void editElem() {
		short int checker;
		cout << "Podaj numer elementu, ktory chcesz edytowac:\n";
		showElems();
		cin >> checker;
		while (checker < 1 || checker >(*index) + 1) {
			cout << "Podaj wlasciwy numer z zakresu od 1 do " << (*index) + 1 << ".\n";
			cin >> checker;
		}
		savingsArray[checker + 1].edit();
	}

	void showElems() {
		for (int i = 0; i <= *index; i++) {
			cout << i + 1 << ". " << savingsArray[i] << "\n";
		}
	}
		
};

template <class T> WalletDivider <T>::WalletDivider() {
	savingsArray = new T[100];
	index = new int;
	*index = 0;
}

template <class T> WalletDivider <T>::~WalletDivider() {
	delete[] savingsArray;
	delete[] index;
}
