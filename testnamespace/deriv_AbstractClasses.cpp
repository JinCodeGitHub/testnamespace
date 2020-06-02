#include <iostream>
class Account
{
public:
	Account(double d);
	virtual double GetBalance();
	virtual void   PrintBalance() = 0;
	

private:
	double _balance;
};

class Base {
public:
	Base(){}
	virtual ~Base() = 0;

};

Base::~Base(){}

class derived :public Base {
public :
	derived() {};
	~derived(){}
};
/*
int main() {
	derived *pDerived = new derived;
	delete pDerived;
	system("pause");
}
*/