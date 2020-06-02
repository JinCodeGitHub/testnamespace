class A {
public :
	int a;
};

class B : virtual public A {
public :
	int a();
};

class C : virtual public A{};

class D : public B, public C {
public :
	D() { a(); }
};