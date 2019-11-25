#include<iostream>
#include "Asset.h"
using namespace std;

class IkeIkze : public Asset
{
	string product;

public:
	void info();
	void edit();
	IkeIkze(bool var);
	IkeIkze();
	~IkeIkze();
	IkeIkze& operator += (double elem) {
		contribution += elem;
		return *this;
	};
	IkeIkze& operator -= (double elem) {
		contribution -= elem;
		return *this;
	}
};

