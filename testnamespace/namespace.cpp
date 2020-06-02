#include <iostream>
#include "namespace.h"
using namespace std;
#if !defined(__cplusplus)
#error C++ compiler required.
#endif

#if __cplusplus >= 201103L 
#error should use C++11 implementation
#endif
//using namespace Han;

#include <cassert>

char* ArrayAlloc(int n) {
	assert(n>0);
	return new char[n];

}
/*
int main(int argc , char *argv[]) {
	
	//Li::flag = 9;
	//cout << Li::flag << endl;

	//cout << boolalpha;
	//cout << boolalpha<<Han::flag << endl;

	//test();
	long long ll_min = LLONG_MIN;
	long long ll_max = LLONG_MAX;
	unsigned long long  ull_max = ULLONG_MAX;

	printf("min of long long :%lld\n",ll_min);
	printf("max of long long :%lld\n", ll_max);
	printf("max of unsigned long long :%llu\n",ull_max);
	
	char* a = ArrayAlloc(0);

	

	system ("pause");
	return 0;

}
*/