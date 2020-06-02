#include<iostream>
using namespace std;


class DataOnly {
/*public :
	DataOnly(); // default constructor	
	~DataOnly(); // destructor
	DataOnly(const DataOnly & rhs);// copy constructor
	DataOnly & operator= (const DataOnly & rhs);// copy assignment operator
	DataOnly(const DataOnly && rhs);  // C++11, move constructor
	DataOnly & operator= (DataOnly && rhs); // C++11, move assignment operator
	*/
/*public:
	DataOnly() {};
	~DataOnly()
	{

	};
	DataOnly(const DataOnly & rhs) = delete; //禁止使用该函数
	DataOnly & operator= (DataOnly & rhs) = delete; //禁止使用该函数

	DataOnly(const DataOnly && rhs) {};
	DataOnly & operator= (DataOnly && rhs) {};
*/
public:
	void func(int a ) {}
	void func(float a) = delete;
};

/*int main(int argc , char *argv[]) {
	DataOnly data1;
	//DataOnly data2(data1);
	//DataOnly data3 = data1;

	
	data1.func(1);
	//data1.func(0.5);
	
}*/