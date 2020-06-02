/*预定义标识符__func__*/

#include <string>
#include <iostream>
#include "namespace.h"
using namespace std;

const char* hello() { return __func__; }
const char* world() { return __func__; }

void test() {
	TestStruct ts; 
	cout << hello() << "," << world() << endl;
	int x = 3;
	LOG("x = %d",x);
	cout << ts.name << endl;
	
}