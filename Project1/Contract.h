#include<iostream>
#include "Asset.h"
using namespace std;

class Contract : public Asset
{
public:
	void info();
	void edit();
	Contract(bool var);
	Contract();
	~Contract();
	Contract& operator += (double elem) {
		contribution += elem;
		return *this;
	};
	Contract& operator -= (double elem) {
		contribution -= elem;
		return *this;
	}
};

