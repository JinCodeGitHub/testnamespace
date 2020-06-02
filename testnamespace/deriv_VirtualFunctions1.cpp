#include "namespace.h"
#include <iostream>
using namespace std;


class Account {
public :
	Account(double d) { _balance = d; }
	virtual ~Account(){}
	virtual double GetBalance() { return _balance; }
	virtual void   PrintBalance() { cerr << "Error.Balance not available for base type." << endl; }
private: 
	double _balance;
};

class CheckAccount : public Account {
public:
	CheckAccount(double d ) : Account(d){}
	void PrintBalance() { cout << "Checking account balance:" << GetBalance()<<"\n"<<endl; }

};

class SavingsAccount : public Account {
public:
	SavingsAccount(double d ) : Account(d){}
	void PrintBalance() { cout << "Savings account balance:" << GetBalance()<<"\n"<<endl; }
};

/*
int main() {
	//Account account(10.00);
	//CheckAccount checking(100.00);
	//SavingsAccount saving(1000.00);

	
	/*
	Account *pAccount = &checking;
	pAccount->PrintBalance();

	pAccount = &saving;
	pAccount->PrintBalance();

	pAccount = &account;
	pAccount->PrintBalance();
	*
	CheckAccount *pCheckAccount = new CheckAccount(100.00);
	pCheckAccount->Account::PrintBalance();

	Account *pAccount = pCheckAccount;
	pAccount->Account::PrintBalance();

	system("pause");
}


*/