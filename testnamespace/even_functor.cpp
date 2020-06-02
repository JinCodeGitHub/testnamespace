#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class FunctorClass {
public:
	explicit FunctorClass(int& evenCount): m_evenCount(evenCount){}
	void operator()(int n) const {
		cout << n;
		if (n % 2 == 0) {
			cout << "is even " << endl;
			++m_evenCount;
		}
		else {
			cout << "is odd " << endl;
		}
	}
private:
	FunctorClass & operator = (const FunctorClass&);
	int& m_evenCount;
};
/*
int main(){
	vector<int> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
		cout << i << endl;
	}

	int evenCount = 0;
	for_each(v.begin(),v.end(),FunctorClass(evenCount));
	cout << "There are " << evenCount << " even numbers in the verctor." << endl;

	system("pause");
}
*/
