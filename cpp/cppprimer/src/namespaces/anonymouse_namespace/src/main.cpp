/**
* @Name
*   main.cpp
* @Summary
*   Test that unnamed (anonymous) namespace can be used in lieu of static something in C (some local scope construct)
* @NOTE
*  this is a test cpp source file 
*/

#include <iostream>
using namespace std;

namespace {
	void f() { 
		cout << "inside f() " << endl;
	}
}

int main(int argc, char* argv[])  
{
    f();
}


// you can have static to have the same effects.
static void k() 
{
	cout << "inside k()" << endl;
}