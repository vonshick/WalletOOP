#include<iostream>
#include "Asset.h"
using namespace std;

class StructuredProduct: public Asset
{
	string managerName;

public:
	void edit();
	void info();
	StructuredProduct();
	StructuredProduct(bool var);
	~StructuredProduct();
	StructuredProduct& operator += (double elem) {
		contribution += elem;
		return *this;
	};
	StructuredProduct& operator -= (double elem) {
		contribution -= elem;
		return *this;
	}
};

