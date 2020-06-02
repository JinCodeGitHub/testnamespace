// read the standard input a line at a time.

// read two strings and report whether the strings have the same length
// If not, report which is longer

// read two strings and report whether the strings are equal
// If not, report which of the two is larger.

//read strings from the standard input, concatenating what is read into one large string. 
//Print the concatenated string.


//separate adjacent input strings by a space.

// read a sequence of strings from cin and
// store those values in a vector.

//
//Redo the first exercise from § 3.3.3 (p. 105) using iterators.
//

//
//Revise the loop that printed the first paragraph in text 
//to instead change the elements in text that correspond 
//to the first paragraph to all uppercase. 
//After you’ve updated text, print its contents.
//

// more discuss: https://github.com/Mooophy/Cpp-Primer/pull/241
// @frank67

//
//  When a zero entered, the code below would crash with feedback as :
//  "Unhandled exception at 0x75834598 in just_for_cpp.exe: Microsoft C++ exception: std::runtime_error at memory location 0x0054F9F4."
//  
//  Tested on Windows 8.1 + Vs 2013
//

// @author @shbling @Yue Wang
//
// Exercise 9.13:
// How would you initialize a vector<double> from a list<int>?
// From a vector<int>?
// Write code to check your answers.
//




#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<iterator>
#include<cstring>
#include "Chapter6.h"
#include<stdexcept>
#include<initializer_list>
#include<fstream>
#include<sstream>
#include<list>
#include<deque>
#include<forward_list>


using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::vector;
using std::isalpha;
using std::iterator;
using Iter = vector<int>::const_iterator;
using std::istream;
using std::ifstream;
using std::list;
using std::deque;
using std::end;
using std::advance;
using std::forward_list;

const char  cstr1[] = "Hello";
const char  cstr2[] = "World!";

void check_and_print(const vector<int>& vec) {
	cout << "size:" << vec.size() << "-content:[";
	for (auto it = vec.begin(); it != vec.end(); it++)
		cout << *it << (it != vec.end() - 1 ? "," : "");
	cout << "]\n" << endl;
}

void check_and_print(const vector<string>& vec) {
	cout << "size:" << vec.size() << "-content:[";
	for (auto it = vec.begin(); it != vec.end(); it++)
		cout << *it << (it != vec.end() - 1 ? "," : "");
	cout << "]\n" << endl;
}
// pb point to begin of the array, pe point to end of the array.
bool compare(int* const pb1, int* const pe1,int* const pb2,int* const pe2){
	if ((pe1 - pb1) != (pe2 - pb2)) {
		return false;
	}
	else {
		for (int* i = pb1, *j = pb2; (i != pe1)&&(j != pe2); ++i, ++j) {
			if (*i != *j) {
				return false;
			}
		}
	}
	return true;
}

bool is_prefix(vector<int> const& lhs, vector<int> const &rhs) {
	if (lhs.size() > rhs.size()) {
		return is_prefix(rhs,lhs);
	}
	for (unsigned i = 0; i != lhs.size(); ++i) {
		if (lhs[i] != rhs[i]) return false;

	}
	return true;

}

int fact(int i) {
	if (i < 0) {
		std::runtime_error err("Input cannot be a negative number");
		cout << err.what() << endl;
	}
	return i > 1 ? i * (fact(i - 1)) : 1;
}

int fact1(int i ) {
	return  i > 1 ? i * fact1(i - 1) : 1;
}
void interactive_fact() {
	string const prompt = "Enter a number within [1,13):\n";
	string const out_of_range = "Out of range ,pleast try again.\n";
	for (int i; cout << prompt, cin >> i;) {
		if (i < 1 || i >12) {
			cout << out_of_range;
			continue;
		}
		cout << fact1(i) << endl;
	}
}
	
	size_t add_cout(int n){
		static size_t  ctr = 0;
		ctr += n;
		return ctr;
	}

	size_t generate() {
		static size_t  ctr = 0;
		return  ctr++;
	}
	//@Yue wang
	//
	// Exercise 6.10:
	// Using pointers, write a function to swap the values of two ints.
	// Test the function by calling it and printing the swapped values.
	//
	void swap(int* lhs, int* rhs) {
		int tmp;
		tmp = *lhs;
		*lhs = *rhs;
		*rhs = tmp;

	}

	void reset(int &i) {
		i = 0;
	}

	//@Yue Wang
	//
	// Exercise 6.12:
	// Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to use
	// references instead of pointers to swap the value of two ints. Which
	// version do you think would be easier to use and why?
	//  The version using reference is easier.
	//

	void swap1(int& lhs,int& rhs){
		int tmp = lhs;
		lhs = rhs;
		rhs = tmp;
	}

	bool any_capital(string const& str) {
		for (auto ch : str) {
			if (isupper(ch)) return true;
		}
		return false;
	}

	void to_lowervase(string& str) {
		for (auto& ch : str) {
			ch = tolower(ch);
		}
	}

	// @Yue Wang
	//
	// Exercise 6.21:
	// Write a function that takes an int and a pointer to an int and
	// returns the larger of the int value or the value to which the
	// pointer points. What type should you use for the pointer?
	//

	int large_one(const int i , const int *const p ) {
		return (i > *p) ? i : *p;
	}
	int sum(std::initializer_list<int> const& il) {
		int sum = 0;
		for (auto i : il) sum += i;
		return sum;
	}

	void print(Iter first, Iter last) {
		if (first != last) {
			cout << *first << " ";
			print(++first, last);
		}
	}

	void f()
	{
		cout << "f()" << endl;
	}

	void f(int)
	{
		cout << "f(int)" << endl;
	}

	void f(int, int)
	{
		cout << "f(int, int)" << endl;
	}

	void f(double, double)
	{
		cout << "f(double, double)" << endl;
	}
	//
	//  ex8_02.cpp
	//  Exercise 8.2
	//
	//  Created by pezy on 11/27/14.
	//
	//  @Brief  Test your function by calling it, passing cin as an argument
	istream& func(istream &is) {
		string buf;
		while (is >> buf) {
			cout << buf << endl;
		}
		if (!is.eof()) {
			cout << "Other Error!" << endl;
		}
		else {
			cout << "EOF Exit!" << endl;
		}
		is.clear();
		return is;
	}
	//
	//  ex8_04.cpp
	//  Exercise 8.4
	//
	//  Created by pezy on 11/9/14.
	//
	//  @Brief  Write a function to open a file for input and read its contents into a vector of strings, 
	//          storing each line as a separate element in the vector. 

	//
	//  ex8_09.cpp
	//  Exercise 8.9
	//
	//  Created by pezy on 11/29/14.
	//
	//  @Brief  Use the function you wrote for the first exercise in § 8.1.2 (p.314) to print the contents of an istringstream object.
	//  @See    Exercise 8.1
	void ReadFileToVec(const string& FileName, vector<string>& vec) {
		ifstream ifs(FileName);
		if (ifs) {
			string buf;
			while (std::getline(ifs, buf))
				vec.push_back(buf);
		}

	}

	void double_and_insert(vector<int>& v , int some_val) {
		auto mid = [&] {return v.begin() + v.size() / 2; };
		for (auto curr = v.begin(); curr != mid(); ++curr) {
			if (*curr == some_val) {
				++(curr = v.insert(curr, 2 * some_val));
				
			}
		}
	}
	// @author @TungWah @Yue Wang
	// @date   4 Oct, 2014. Oct, 2015.
	//
	// Exercise 9.45:
	// Write a funtion that takes a string representing a name and two other
	// strings representing a prefix, such as “Mr.” or “Ms.” and a suffix,
	// such as “Jr.” or “III”. Using iterators and the insert and append functions,
	// generate and return a new string with the suffix and prefix added to the
	// given name.
	//
	// Exercise 9.45
	auto add_pre_and_suffix(string name, string const& pre, string const& su)
	{
		name.insert(name.begin(), pre.cbegin(), pre.cend());
		return name.append(su);
	}

	//
	//  ex9_31.cpp
	//  Exercise 9.31 
	//
	//  Created by pezy on 12/3/14.
	//
	//  @Brief  The program on page 354 to remove even-valued elements and 
	//          duplicate odd ones will not work on a list or forward_list. Why? 
	//          Revise the program so that it works on these types as well. 
	//  @list   iter += 2; -> advance(iter, 2);
	//
	//  Refactored by Yue Wang Oct 2015
	//
	auto remove_evens_and_double_odds(list<int>& data)
	{
		for (auto cur = data.begin(); cur != data.end();)
			if (*cur & 0x1)
				cur = data.insert(cur, *cur), advance(cur, 2);
			else
				cur = data.erase(cur);
	}

	//
	//  ex9_31.cpp
	//  Exercise 9.31 
	//
	//  Created by pezy on 12/3/14.
	//
	//  @Brief  The program on page 354 to remove even-valued elements and 
	//          duplicate odd ones will not work on a list or forward_list. Why? 
	//          Revise the program so that it works on these types as well. 
	//  
	//  Refactored by Yue Wang Oct 2015  
	//
	auto remove_evens_and_double_odds(forward_list<int>& data)
	{
		for (auto cur = data.begin(), prv = data.before_begin(); cur != data.end();)
			if (*cur & 0x1)
				cur = data.insert_after(prv, *cur),
				advance(cur, 2),
				advance(prv, 2);
			else
				cur = data.erase_after(prv);
	}


/*int main() {
	//for (string str; getline(cin, str); cout << str << endl);
	/*for (string str1, str2; cin >> str1 >> str2;) {
		if (str1.size() == str2.size()) {
			cout << "The two strings have the  same length" << endl;
		}
		else {
			cout << "The longer string is " << ((str1.size() > str2.size()) ? str1 : str2) << endl;
		}
	}
	*/

	/*
	string str1, str2;
	while (cin >> str1 >> str2) {
		if (str1 == str2) {
			cout << "The two strings are equal" << endl;
		}
		else {
			cout << "The large string is " << ((str1 > str2) ? str1 : str2) << endl;
		}
	}
	*/

	/*string concatenated;
	for (string buffer; cin >> buffer; concatenated += buffer) {
		cout << "The concatenated string is :" << concatenated + buffer << endl;
	}*/

	/*string str("asimplestring");
	for (auto &c : str) c = 'X'
	cout << str << str.size()<<endl;*/

	/*string str;
	for (string buf; cin >> buf; str += (str.empty() ? "" : "") + buf) {
		//cout << "The concatenated string is :" << buf << buf.size() << endl;
		cout << "The concatenated string is :" << str+buf << " "<<str.size() << endl;
	}*/

	/*vector<string> vec;
	for (string buffer; cin >> buffer; vec.push_back(buffer)) {
		cout << "data is " << vec.size() << endl;

	}*/

	/*string str("a simple string");
	decltype(str.size()) i = 0;
	while (i < str.size() )str[i++] = 'X';
	cout << str << endl;

	for (i = 0; i < str.size(); str[i++] = 'Y');
	cout << str << endl;*/
	/*vector<int> v1;
	cout << "{\n \"v1\":{\"size\":\"" << v1.size() << "\",\"value\":[";
	for (auto i : v1)
		cout << i << ",";
	if (!v1.empty()) cout << "\b";
	cout << "]}" << endl;

	vector<int> v2(10);
	cout << " \"v2\":{\"size\":\"" << v2.size() << "\",\"value\":[";
	for (auto i : v2)
		cout << i << ",";
	if (!v2.empty()) cout << "\b";
	cout << "]}" << endl;

	vector<int> v3(10, 42);
	cout << " \"v3\":{\"size\":\"" << v3.size() << "\",\"value\":[";
	for (auto i : v3)
		cout << i << ",";
	if (!v3.empty()) cout << "\b";
	cout << "]}" << endl;

	vector<int> v4{ 10 };
	cout << " \"v4\":{\"size\":\"" << v4.size() << "\",\"value\":[";
	for (auto i : v4)
		cout << i << ",";
	if (!v4.empty()) cout << "\b";
	cout << "]}" << endl;

	vector<int> v5{ 10, 42 };
	cout << " \"v5\":{\"size\":\"" << v5.size() << "\",\"value\":[";
	for (auto i : v5)
		cout << i << ",";
	if (!v5.empty()) cout << "\b";
	cout << "]}" << endl;

	vector<string> v6{ 10 };
	cout << " \"v6\":{\"size\":\"" << v6.size() << "\",\"value\":[";
	for (auto i : v6)
		if (i.empty()) cout << "(null)" << ",";
		else cout << i << ",";
		if (!v6.empty()) cout << "\b";
		cout << "]}" << endl;

		vector<string> v7{ 10, "hi" };
		cout << " \"v7\":{\"size\":\"" << v7.size() << "\",\"value\":[";
		for (auto i : v7)
			if (i.empty()) cout << "(null)" << ",";
			else cout << i << ",";
			if (!v7.empty()) cout << "\b";
			cout << "]}\n}" << endl;*/

    /*vector<string> vec;
	for (string word; cin >> word; vec.push_back(word));
	for (auto &str : vec) for (auto &c : str) c = toupper(c);
	for (string::size_type i = 0; i != vec.size(); ++i) {
		if (i != 0 && i % 8 == 0) cout << endl;
		cout << vec[i] << endl;

	}
	cout << endl;*/
    /*vector<int> ivec1(10,42);
    vector<int> ivec2{ 42,42,42,42,42,42,42,42,42,42 };
    vector<int> ivec3;
    for (int i = 0; i != 10; ++i) ivec3.push_back(42);
    cout << "The first approach is better!" << std::endl;
	*/
/*
//程序的结束主要靠输入的数据错误
vector<int> ivec;
int cnt = 0, ret = 0;
for (int i; cin >> i; ivec.push_back(i))
{
	cnt++;
		cout << cnt << ret << endl;
}

if (ivec.empty())
{
	cout << "input at least one integer." << endl;
	return -1;
}

if (ivec.size() == 1)
{
	cout << "only one integer " << ivec[0] << ", it doesn't have any adjacent elements." << endl;
	return -1;
}

for (int i = 0; i < ivec.size() - 1; ++i)
	cout << ivec[i] + ivec[i + 1] << " ";
cout << endl;  */
/*
//3.3.3
vector<int> v1;
vector<int> v2(10);
vector<int> v3(10,42);
vector<int> v4{ 10 };
vector<int> v5{ 10,42 };
vector <string> v6{ 10 };
vector<string> v7{ 10,"hi" };
check_and_print(v1);
check_and_print(v2);
check_and_print(v3);
check_and_print(v4);
check_and_print(v5);
check_and_print(v6);
check_and_print(v7);
*/
/*vector<string> text;
for (string line; getline(cin, line); text.push_back(line));
for (auto&word:text) {
	for (auto&ch : word) 
		if (isalpha(ch)) ch = toupper(ch);
	cout << word << "";
	
}*/

/*vector<int> v{ 0,1,2,3,4,5,6,7,8,9 };
for (auto it = v.begin(); it != v.end(); it++) *it *= 2;
for (auto i : v) cout << i << "";*/

/*vector <unsigned> scores(11,0);

for (unsigned grade; cin >> grade;) {
	if (grade <= 100) {
		++*(scores.begin() + grade / 10);

	}
}
for (auto s : scores) {
	cout << s << "";
}
cout << endl; */ 

/*int arr1[3] = {0, 1, 2};
int arr2[3] = { 0, 2, 4 };
if (compare(std::begin(arr1), std::end(arr1), std::begin(arr2), std::end(arr2))) {
	cout << "The two arrays are equal" << endl;
}
else {
	cout << "The two arrays are not equal" << endl;
}

cout << "=========" << endl;
vector< int > vec1 = { 0 ,1 ,2 };
vector <int > vec2 = { 0 ,2, 4 };
if (vec1 == vec2) {
	cout << "The two vectors are equal " << endl;

}
else {
	cout << "The two vectors are not equal" << endl;
}*/

/*// use C-Style character strings.
const char* cs1 = "Wangyue";
const char* cs2 = "Pezy";

auto result = strcmp(cs1,cs2);
if (result == 0) {
	cout << "same string" << endl;
}
else if (result <0) {
	cout << "Wangyue < Pezy" << endl;
}
else {
	cout << "Wangyue > Pezy" << endl;
}*/

//constexpr size_t cstr11 = strlen(cstr1);
//size_t cstr12 = strlen(" ");
//size_t cstr13 = strlen(cstr2);

/*constexpr size_t new_size = strlen(cstr1) + strlen(" ") + strlen(cstr2) + 1;
char cstr3[new_size];
strcpy(cstr3, cstr1);
strcat(cstr3, "");
strcat(cstr3, cstr2);
cout << cstr3 << endl;*/

/*int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
vector<int> vec(std::begin(arr), std::end(arr));
for (auto i : vec) {
	cout << i << "";
}
cout << endl;*/
//int ia[3][4] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

// a range for to manage the iteration
// use type alias
//using int_array = int[4];
/*for (int_array& p : ia)
for (int q : p)
cout << q << " ";
cout << endl;*/
// using pointers.
// use type alias
/*for (int_array* p = ia; p != ia + 3; ++p)
for (int *q = *p; q != *p + 4; ++q)
cout << *q << " ";
cout << endl;*/

/*const char ca[] = {'h','e','l','l','o'};
const char *cp = ca;
while (*cp) {
	cout << *cp << endl;
	++cp;
}*/

/*vector<int> vec{ 1,2,3,4,5,6,7,8,9 };
for (auto i : vec) {
	cout << ((i & 0x1) ? i * 2 : i) << endl;
}
cout << endl;*/

/*for (unsigned g; cin >> g;) {
	auto  resutl = g > 90 ? "high pass"  : g < 60 ?   "fail " : g < 75 ?  "low pass " :  "pass";
    
	// if statements
	if (g > 90)         cout << "high pass";
	else if (g < 60)    cout << "fail";
	else if (g < 75)    cout << "low pass";
	else                cout << "pass";
	cout << endl;  
}*/
/*
// void type
cout << "void: nullptr_t\t" << sizeof(std::nullptr_t) << " bytes" << endl << endl;

// boolean type
cout << "bool:\t\t" << sizeof(bool) << " bytes" << endl << endl;

// charactor type
cout << "char:\t\t" << sizeof(char) << " bytes" << endl;
cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << endl;
cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << endl;
cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << endl << endl;

// integers type
cout << "short:\t\t" << sizeof(short) << " bytes" << endl;
cout << "int:\t\t" << sizeof(int) << " bytes" << endl;
cout << "long:\t\t" << sizeof(long) << " bytes" << endl;
cout << "long long:\t" << sizeof(long long) << " bytes" << endl << endl;

// floating point type
cout << "float:\t\t" << sizeof(float) << " bytes" << endl;
cout << "double:\t\t" << sizeof(double) << " bytes" << endl;
cout << "long double:\t" << sizeof(long double) << " bytes" << endl << endl;

// Fixed width integers
cout << "int8_t:\t\t" << sizeof(int8_t) << " bytes" << endl;
cout << "uint8_t:\t" << sizeof(uint8_t) << " bytes" << endl;
cout << "int16_t:\t" << sizeof(int16_t) << " bytes" << endl;
cout << "uint16_t:\t" << sizeof(uint16_t) << " bytes" << endl;
cout << "int32_t:\t" << sizeof(int32_t) << " bytes" << endl;
cout << "uint32_t:\t" << sizeof(uint32_t) << " bytes" << endl;
cout << "int64_t:\t" << sizeof(int64_t) << " bytes" << endl;
cout << "uint64_t:\t" << sizeof(uint64_t) << " bytes" << endl;

cout << 5 + 10 * 20 / 2 << endl;*/

/*unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, newLineCnt = 0;
char ch;
while (cin >> std::noskipws >> ch)
switch (ch)
{
case 'a':
case 'A':
	++aCnt;
	break;
case 'e':
case 'E':
	++eCnt;
	break;
case 'i':
case 'I':
	++iCnt;
	break;
case 'o':
case 'O':
	++oCnt;
	break;
case 'u':
case 'U':
	++uCnt;
	break;
case ' ':
	++spaceCnt;
	break;
case '\t':
	++tabCnt;
	break;
case '\n':
	++newLineCnt;
	break;
}

cout << "Number of vowel a(A): \t" << aCnt << '\n'
<< "Number of vowel e(E): \t" << eCnt << '\n'
<< "Number of vowel i(I): \t" << iCnt << '\n'
<< "Number of vowel o(O): \t" << oCnt << '\n'
<< "Number of vowel u(U): \t" << uCnt << '\n'
<< "Number of space: \t" << spaceCnt << '\n'
<< "Number of tab char: \t" << tabCnt << '\n'
<< "Number of new line: \t" << newLineCnt << endl;*/

/*vector<int> l{ 0, 1, 1, 2 };
vector<int> r{ 0, 1, 1, 2, 3, 5, 8 };
cout << (is_prefix(r, l) ? "yes\n" : "no\n");*/

/*int i, j;
std::cin >> i >> j;
if (j == 0) {
	throw std::runtime_error("divisor is 0");
}
cout << i / j << endl;*/

/*for (int i, j; cout << "Input two integers:\n"; cin >> i >> j) {
	try {
		if (j == 0) {
			throw std::runtime_error("divisor is 0");
		cout << i / j << endl;
		}
	}
	catch (std::runtime_error err) {
		cout << err.what() << "\nTry again? Enter y or n " << endl;
		char c;
		cin >> c;
		if (!cin || c == 'n')
			break;
	}
}*/

//cout << std::boolalpha << (120 == fact(5)) << endl;
//interactive_fact();
/*for (size_t i = 0; i != 10; ++i) {
	cout << add_cout(i) << endl;
}*/

/*for (int lft, rht; cout << "Please Enter:\n", cin >> lft >> rht;) {
	swap(&lft, &rht);
	cout << lft << " " << rht << endl;
}*/

/*int i = 42;
reset(i);
cout << i << endl;*/

/*for (int lfs, rfs; cout << "Please Enter:\n", cin >> lfs >> rfs;) {
	swap1(lfs, rfs);
	cout << lfs << " " << rfs << endl;
}*/

/*string hello("Hello World");
cout << std::boolalpha << any_capital(hello) << endl;
to_lowervase(hello);
cout  << hello << endl;*/
/*int i = 6;
cout << large_one(7, &i) << endl;*/
/*auto il = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
std::cout << sum(il) << std::endl;*/

/*vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
print(vec.cbegin(), vec.cend());*/
/*f(42);
f(42, 0);
f(2.56, 3.14);*/
/*istream& is = func(cin);
cout << std::boolalpha <<  is.rdstate() << endl;*/

/*vector<string>  vec;
ReadFileToVec("C:/Users/dell/Desktop/GNSS/ubuntu命令.txt",vec);
for (const auto &str : vec) {
	cout << str << endl;
}*/

/*std::istringstream iss("hello");
func(iss);*/

/*list<int> ilist(5,4);
vector<int> ivc(5,5);

vector<double> dvc(ilist.begin(), ilist.end());
for (auto i : ilist) cout << i << "";
cout << endl;
for (auto d :dvc) cout << d << "";
cout << endl;

vector<double> dvc2(ivc.begin(), ivc.end());
for (auto i : ivc) cout << i << "";
cout << endl;
for (auto d : dvc2) cout << d << "";*/

// @Yue Wang @pezy
//
// Exercise 9.14:
// Write a program to assign the elements from a list of char* pointers
// to C-style character strings
//
/*list<const char*> i{ "Mooophy", "pezy", "Queeuqueg" };
vector<string> v;
v.assign(i.cbegin(), i.cend());
for (auto ptr : v) {
	cout << ptr << endl;
}*/
//
//  ex9_15.cpp
//  Exercise 9.15
//
//  Created by pezy on 12/2/14.
//
//  @Brief  Write a program to determine whether two vector<int>s are equal.

/*vector<int> vec1{ 1, 2, 3, 4, 5 };
vector<int> vec2{ 1, 2, 3, 4, 5 };
vector<int> vec3{ 1, 2, 3, 4 };
cout << (vec1 == vec2 ? "true" : "false") << endl;
cout << (vec1 == vec3 ? "true" : "false") << endl;*/


/*list<int> li{ 1,2,3,4,5 };
vector<int> vec2{ 1,2,3,4,5 };
vector<int> vec3{ 1,2,3,4 };
//cout << (vec1 == vec2 ? "true" : "false") << endl;
//cout << (vec1 == vec3 ? "true" : "false") << endl;
std::cout << (std::vector<int>(li.begin(), li.end()) == vec2 ? "true" : "false") << std::endl;
std::cout << (std::vector<int>(li.begin(), li.end()) == vec3 ? "true" : "false") << std::endl;*/
//
//  ex9_18.cpp
//  Exercise 9.18
//
//  Created by pezy on 12/3/14.
//
//  @Brief  Write a program to read a sequence of strings from the standard input into
//          a deque. Use iterators to write a loop to print the elements in the deque.

/*deque<string> deque1;
for (string input; cin >> input; deque1.push_back(input));
for (auto iter = deque1.begin(); iter != deque1.end(); ++iter) {
	cout << *iter << endl;
}*/


//
//  ex9_20.cpp
//  Exercise 9.20
//
//  Created by pezy on 12/3/14.
//
//  @Brief  Write a program to copy elements from a list<int> into two deques.
//          The even-valued elements should go into one deque and the odd ones into the other.

/*list<int> l{ 1,2,3,4,5,6,7,8,9,10 };
deque<int> odd, even;
for (auto i : l) {
	(i & 0x1 ?  odd : even).push_back(i);
}
for (auto i : odd) cout << i << "";
cout << endl;
for (auto i : even) cout << i << "";
cout << endl;*/

/*vector<int> v{1,9,1,9,9,9,1,1};
double_and_insert(v, 1);
for (auto i : v) {
	cout << i << endl;
}*/

/*int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

// init
vector<int> vec(ia, end(ia));
list<int> lst(vec.begin(), vec.end());

// remove odd value
for (auto it = lst.begin(); it != lst.end(); )
if (*it & 0x1) it = lst.erase(it);
else ++it;

// remove even value
for (auto it = vec.begin(); it != vec.end(); )
if (!(*it & 0x1)) it = vec.erase(it);
else ++it;

// print
cout << "list : ";
for (auto i : lst)   cout << i << " ";
cout << "\nvector : ";
for (auto i : vec)   cout << i << " ";
cout << std::endl;
*/

/*string name("Wang");
cout << add_pre_and_suffix(name, "Mr.", ", Jr.") << endl;*/
/*list<int> data{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
remove_evens_and_double_odds(data);
for (auto i : data) cout << i << " ";*/

/*forward_list<int> data{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
remove_evens_and_double_odds(data);
for (auto i : data)
cout << i << " ";*/

//
//  ex9_33.cpp
//  Exercise 9.33 
//
//  Created by pezy on 12/3/14.
//
//  @Brief  In the final example in this section what would happen 
//          if we did not assign the result of insert to begin? 
//          Write a program that omits this assignment to see if your expectation was correct.  
//  @Answer Crash, because the iterator is invalid after inserting.
/*vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
auto begin = v.begin();
while (begin != v.end()) {
	++begin;
	v.insert(begin, 42);
	//++begin;
}

for (auto i : v)
cout << i << " ";

    system("pause");


	return 0;
}*/