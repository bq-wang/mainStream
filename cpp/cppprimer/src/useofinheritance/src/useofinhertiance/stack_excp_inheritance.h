/**
* file:
*  stack_excp_inheritance.cpp
* description:
* the header file that shows how to effectively use class hierarchy to use the stack exception
*/
#include <iostream>
#include <string>
using std::cout;
using std::cerr;
using std::endl;
using std::string;


class Excp 
{
public : 
	// print error message
	static void print(string msg) { 
		cerr << msg << endl;
	}
};

class popOnEmpty : public Excp { };
class pushOnFull: public Excp {
public:
	pushOnFull(int value ) {} ;
};

class iStack { 
public:
	void push(int value);
	bool full() { return true ; } 
};