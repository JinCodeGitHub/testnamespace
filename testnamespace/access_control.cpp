#include<iostream>
using namespace std;

class Base {
public :
	int Print();
	static int CountOf();
};

class Derived1 : private Base {

};

class Derived2 : public Derived1 {
	int ShowCount();
};
/*
int  Derived2::ShowCount() {
	//int cCount = Base::CountOf();
	//cCount = this->CountOf();
	//return cCount;

};
*/