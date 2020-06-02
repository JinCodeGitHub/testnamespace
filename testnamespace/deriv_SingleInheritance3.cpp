#include <iostream>
using namespace std;

class Document {
public:
	char *Name;
	void  PrintNameOf();

};

class Book : public Document {
	Book(char *name, long pagecount );
	void PrintNameOf();
	long PageCount;
};

void Book::PrintNameOf() {
	cout << "Name of book :";
	Document::PrintNameOf();
}