
 #ifndef  NAMESPACE_H
#define   NAMESPACE_H

//namespace Li { 
	//int flag = 1;
//}

//namespace Han {
//	bool flag = true;
//}

#endif // !

#include "iostream"
#include "cstdlib"
#include "cstring"
#include <stdio.h>
#include <climits>
#include <cstdio>

#define LOG(...) { \
fprintf(stderr, "%s: Line %d:\t", __FILE__, __LINE__); \
fprintf(stderr, __VA_ARGS__); \
fprintf(stderr, "\n"); \
}


struct TestStruct
{
	TestStruct():name(__func__){}
	const char* name;
};


 void test();
 


/*
class Array {
public:
	Array(int len);
	Array(const Array &arr);   // �������캯��
	~Array();
public:
	int operator[](int i) const { return m_p[i]; }  // �Գ���Ա����(ֻ��)��ʽ����[]�����
	int & operator[](int i) { return m_p[i]; }  // ��ȡԪ��(д��)
	Array & operator=(const Array &arr);  // ���ظ�ֵ�����������operator=()���β�������const Array &,���������ܹ������ڴ���ʱ���ÿ������캯�������ܹ�ͬʱ����const���ͺͷ�const���͵�ʵ��
	int length() const { return m_len; }
	void show();
private:
	int m_len;
	int *m_p;
};
// ���캯���Ķ���
Array::Array(int len) :m_len(len) {
	m_p = (int *)calloc(len, sizeof(int));  // ��̬�����ڴ�ռ䣬ʹ��ָ��m_pָ���·�����ڴ�ռ�
}
// �������캯���Ķ���
Array::Array(const Array &arr) {
	this->m_len = arr.m_len;
	this->m_p = (int *)calloc(this->m_len, sizeof(int));
	memcpy(this->m_p, arr.m_p, m_len * sizeof(int));
}

Array::~Array() {
	free(m_p);
}
// ���ظ�ֵ�����
Array & Array::operator=(const Array &arr) { // operator=()�ķ���ֵ������Array &,���������ܹ������ڷ�������ʱ���ÿ������캯�������ܹ��ﵽ������ֵ��Ŀ��
	if (this != &arr) {  // �ж��Ƿ��Ǹ�ͬһ������ֵ
		this->m_len = arr.m_len;
		free(this->m_p);
		this->m_p = (int*)calloc(this->m_len, sizeof(int));
		memcpy(this->m_p, arr.m_p, m_len * sizeof(int));
	}
	return *this;  // ��ʾ���ص�ǰ����
}

// ��ͨ��Ա�����Ķ���
void Array::show() {
	cout << "������ͨ��Ա����....\n";
}

// ��ӡ����Ԫ��
void printArray(const Array &arr) {
	int len = arr.length();
	for (int i = 0; i<len; i++) {
		if (i == len - 1) {
			cout << arr[i] << endl;
		}
		else {
			cout << arr[i] << ", ";
		}
	}
}
int main() {
	Array arr1(10);
	for (int i = 0; i<10; i++) {
		arr1[i] = i;
	}
	cout << "arr1:";
	printArray(arr1);

	Array arr2(5);
	for (int i = 0; i<5; i++) {
		arr2[i] = i;
	}
	cout << "arr2:";
	printArray(arr2);
	cout << "------------------------------------\n";
	arr2 = arr1;  // ����operator=()
	cout << "��arr1��ֵ��arr2:";
	printArray(arr2);
	arr2[3] = 234;  // �޸�arr2�����ݲ���Ӱ��arr1,�����operator=()ע�͵�,�޸�arr2��ֵ�ͻ�Ӱ��arr1��ֵ
	arr2[7] = 920;
	cout << "�޸�arr2��ֵ����Ӱ��arr1:";
	printArray(arr1);
	return 0;
}
*/
/*
cmake_minimum_required(VERSION 3.0)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER "arm-linux-gnueabihf-gcc")

add_definitions("-Wall")

project(brain)

set(TARGET_NAME ${ CMAKE_PROJECT_NAME })

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include"
"${CMAKE_CURRENT_SOURCE_DIR}/common"
"${CMAKE_CURRENT_SOURCE_DIR}/zlog"
)

file(GLOB_RECURSE SRC_FILES
"${CMAKE_CURRENT_SOURCE_DIR}/base/*.c"
"${CMAKE_CURRENT_SOURCE_DIR}/common/*.c"
"${CMAKE_CURRENT_SOURCE_DIR}/zlog/*.c"
)

add_library(${ TARGET_NAME } SHARED ${ SRC_FILES })

target_link_libraries(${ TARGET_NAME } pthread m rt)
*/



