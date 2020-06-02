/*命名的多义性*/

class A {
public:
	unsigned a;
	unsigned b();
};

class B {
public:
	unsigned a();
	int b();
	char c;
};

class C : public A, public B {

};