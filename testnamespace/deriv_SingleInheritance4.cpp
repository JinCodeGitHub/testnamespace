#include <iostream>
using namespace std;

struct Document
{
	char *Name;
	void PrintNameOf(){}
};

class PaperBook :public Document {

};
/*
int main() {
	Document *DocLib[10];
	for (int i = 0; i < 5; i++)
		DocLib[i] = new Document;
	for (int  i = 5; i < 10; i++)
	{
		DocLib[i] = new PaperBook;
	}
}
*/