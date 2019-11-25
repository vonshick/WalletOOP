#include "Asset.h"
#include <cmath>


double Asset::countProfits(double years) {
	double profits;
	profits = contribution * pow((1 + profit), years);
	return profits; 
}

