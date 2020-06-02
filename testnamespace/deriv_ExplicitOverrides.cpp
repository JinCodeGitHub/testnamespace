#include<iostream>
#include<stdio.h>
using namespace std;
extern "C" int  printf_s(const char *,...);

__interface IMyInt1{
void mf1();
void mf1(int);
void mf2();
void mf2(int);
};

__interface IMyInt2 {
	void mf1();
	void mf1(int);
	void mf2();
	void mf2(int);
};

class CMyClass : public IMyInt1, public IMyInt2 {
public:
	void IMyInt1::mf1() {
		printf_s("In CMyClass::IMyInt1::mf1()\n");
	}

	void IMyInt1::mf1(int) {
		printf_s("In CMyClass::IMyInt1::mf1(int)\n");
	}

	void IMyInt1::mf2();
	void IMyInt1::mf2(int);

	void IMyInt2::mf1() {
		printf_s("In CMyClass::IMyInt2::mf1()\n");
	}

	void IMyInt2::mf1(int) {
		printf_s("In CMyClass::IMyInt2::mf1(int)\n");
	}

	void IMyInt2::mf2();
	void IMyInt2::mf2(int);
};

void CMyClass::IMyInt1::mf2() {
	printf_s("In CMyClass::IMyInt1::mf2()\n");
}

void CMyClass::IMyInt1::mf2(int) {
	printf_s("In CMyClass::IMyInt1::mf2(int)\n");
}

void CMyClass::IMyInt2::mf2() {
	printf_s("In CMyClass::IMyInt2::mf2()\n");
}

void CMyClass::IMyInt2::mf2(int) {
	printf_s("In CMyClass::IMyInt2::mf2(int)\n");
}
/*
int main() {
	IMyInt1 *pIMyInt1 = new CMyClass();
	IMyInt2 *pIMyInt2 = dynamic_cast<IMyInt2 *>(pIMyInt1);

	pIMyInt1->mf1();
	pIMyInt1->mf1(1);
	pIMyInt1->mf2();
	pIMyInt1->mf2(2);
	pIMyInt2->mf1();
	pIMyInt2->mf1(3);
	pIMyInt2->mf2();
	pIMyInt2->mf2(4);

	// Cast to a CMyClass pointer so that the destructor gets called
	CMyClass *p = dynamic_cast<CMyClass *>(pIMyInt1);
	delete p;
}
*/
