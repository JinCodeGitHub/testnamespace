struct B1 {
	void mf(int ){}
};

struct B2 {
	void mf(short){}
	void mf (char){}
};

struct D :B1, B2 {
	void mf(short) {
		__super::mf(1);
		__super::mf('s');
	}
};