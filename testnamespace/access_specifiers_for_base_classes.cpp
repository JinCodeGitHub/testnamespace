#include <iostream>
using namespace std;

class  BaseClass {
public:
	int PublicFunc() { return 0; }
protected:
	int ProtectedFunc() {};
private:
	int PrivateFunc() {};
};

class DerivedClass1 : public BaseClass {
	void foo() {
		PublicFunc();
		ProtectedFunc();
		//PrivateFunc();
	}
};

class DerivedClass2 : private BaseClass {
	void foo() {
		PublicFunc();
		ProtectedFunc();
//		PrivateFunc();
	}
};
/*
int main() {
	DerivedClass1 derivedclass1;
	//DerivedClass2 derivedclass2;

	derivedclass1.PublicFunc();
	//derivedclass2.PublicFunc();
}
*/

