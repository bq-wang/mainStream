/**
* file
*  virtual_function_default_arguments.h
* description:
*  this file demonstrate the use of default argument when the virtual function are considered
*
*/

#include <vector>
#include <list>
#include <iostream>
#include <string>

using std::vector;
using std::list;
using std::cout;
using std::cerr;
using std::endl;


class base
{
public:
	virtual int foo(int ival = 1024) {
		cout << "base::foo() -- ival: " << ival << endl;
	}

	const base_default_value = -1; 

	virtual int bar(int ival  = base_default_value) {
		int real_default_value = 1024;
		if (ival == base_default_value) {
			ival = real_default_value;
		}

		cout << "base::foo() -- ival: " << ival << endl;
	}

};



class derived : public base
{
public:
	virtual int foo(int ival =2048) {
		cout << "derived:foo() -- ival: " << ival << endl;
	}

	virtual int bar(int ival = base_default_value) {
		int real_default_value = 2048;
		if (ival == base_default_value) {
			ival = real_default_value;
		}

		cout << "base::foo() -- ival: " << ival << endl;
	}
}
