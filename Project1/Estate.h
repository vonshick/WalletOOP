#include<iostream>
#include "Asset.h"
using namespace std;

class Estate : public Asset
{
	double surface;
	string city;
	string street;
	short int houseNumber;
	short int flatNumber;
public:
	void info();
	void edit();
	Estate();
	Estate(bool var);
	~Estate();
	Estate& operator += (double elem) {
		contribution += elem;
		return *this;
	};
	Estate& operator -= (double elem) {
		contribution -= elem;
		return *this;
	}
};

