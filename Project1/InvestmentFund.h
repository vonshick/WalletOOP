#include<iostream>
#include "Asset.h"
using namespace std;

class InvestmentFund: public Asset
{
	int unitCount;

public:
	void info();
	void edit();
	InvestmentFund();
	InvestmentFund(bool var);
	~InvestmentFund();
	InvestmentFund& operator += (double elem) {
		contribution += elem;
		return *this;
	};
	InvestmentFund& operator -= (double elem) {
		contribution -= elem;
		return *this;
	}
};