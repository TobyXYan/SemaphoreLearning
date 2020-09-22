#include "SemaTest.h"
#include <iostream>

using namespace std;

int main()
{
	CSemaTest semaTest;
	semaTest.WaitAllDone();
	cout << "Hello World" << endl;
}