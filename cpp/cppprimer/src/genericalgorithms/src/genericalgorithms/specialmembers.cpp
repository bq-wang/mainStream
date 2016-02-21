/**
* file
*  specialmembers.cpp
* 
* 
* this file will go through some of the special members of the class
*  
*/



/**
*  what are the special functions, the special function includes the following. 
*   
*    constructor - initialization
*    destructor  - destruction
*    assignment
*    memmory management
*    type conversio
* 
*  what we are going to do discuss here is the const and volatile member function
*/


/**
*  const member function 
*/



#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <functional>
#include <iterator>
#include <algorithm>
#include <cstring>
#include <exception>

using std::string;
using std::fstream;
using std::copy;
using std::cout;
using std::endl;
using std::cerr;
using std::strcpy;
using std::strcat;
using std::string;
using std::exception;


class NotImplementedException : exception 
{
public:
	inline NotImplementedException();
	inline NotImplementedException(const char * const& message);
	inline NotImplementedException(const exception & excep);

};


NotImplementedException::NotImplementedException() : exception() {}
NotImplementedException::NotImplementedException(const char * const & message) : exception(message) {}
NotImplementedException::NotImplementedException( const exception & except) : exception(except) {}

namespace 
{


class Screen {
public:
	bool isEqual(char ch)  const; 

	/** overload of the const and non-const mmber functions 
	*
	*/
	char get(int x, int y);
	char get(int x, int y) const;

   /*
	* const member is easy to understand , but what about the volatile members
	* 
	* A class object is declared volatile if its value can possibly be changed in ways outside eithe rthe control or detection of the compilers (for example),
	* only volatile members functions, constructors, and the destructor can be inovked by a volatile class object.
	*/
	void poll() volatile;
private: 
	string::size_type _cursor;
	string            _screen;
};

bool Screen::isEqual(char ch) const {
    return ch == _screen[_cursor];
}

void Screen::poll() volatile { 
   // only volatile class object or anything 
}

char Screen::get(int x, int y) 
{
	throw *new NotImplementedException("Not Implemented");
}

char Screen::get(int x, int y) const 
{
	throw *new NotImplementedException("Not Implemented");
}

void test_volatile_member()
{
	volatile Screen vs;

	vs.poll();

	//vs.isEqual('a'); // error:  you can only call volatile member function by a volatile clas object
}

void test_const_members() 
{
	const Screen cs;
	Screen s;

	char ch = cs.get(0, 0); // calls the const membres
	ch = s.get(0, 0);       // calls the non-const members
}


/**
* In general , any class that is spected to be used extensivly should declare the member functions that do not modify the class data members as const members. 
*/
class Text
{
public:
	void bad(const string &param) const; 
private:
	char * _text;
};

/**
* though you cannot directly assign some value to class members, but the compiler is not able to guarantee that everything  to which the class object referes will remain invariant throughout the 
* invocation of hte member function
*/

//void Text::bad(const string &param) const 
//{
//	_text = param.c_str(); // error: _text cannot be modified
//
//	for (int ix = 0; ix < param.size(); ++ix) { 
//		_text[ix] = param[ix]; // bad style but not an error 
//	}
//}
}


