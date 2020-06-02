#include<iostream>
using namespace std;

class Widget {
public :
	template<typename T>
	
	
	void ProcessPointer(T* ptr) {
		cout << typeid(T).name() << endl;
	}
	//template<typename V>
	/*void ProcessPointer1(V *ptr) {
		cout << typeid(V).name() << endl;
	}*/

	
	
private:
	void ProcessPointer(void*) {
		cout << "void " << endl;
	}
	/*void ProcessPointer1(int *x) {
		cout << "x" << endl;
	}*/

};

int main(int argc, char *argv[]) {
	Widget w;
	int* ip = NULL;
	w.ProcessPointer(ip);

	double *vp = NULL;
	w.ProcessPointer(vp);
	system("pause");
	return 0;
}