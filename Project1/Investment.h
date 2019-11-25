#pragma once
#include<iostream>
#include "Asset.h"


using namespace std;

class Investment: public Asset
{
	string bankName;

public:
	void info();
	void edit();
	Investment();
	Investment(bool var);
	~Investment();
	Investment& operator += (double elem) {
		contribution += elem;
		return *this;
	};
	Investment& operator -= (double elem) {
		contribution -= elem;
		return *this;
	}
};

