#pragma once
#include<iostream>
#include<string>

using namespace std;

class Asset
{
protected:
	string name;
	double profit;
	double contribution; 

public:
	double countProfits(double years);
	virtual void edit() = 0;
	
};

