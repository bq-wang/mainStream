/**
* file 
*   MyString.cpp
*
*   this is the MyString.cpp 
*/
#include "stdafx.h"
#include "MyString.h"
#include <iostream>
#include <vector>
#include <assert.h>
#include <cstddef>
#include <utility>
#include <cassert>
#include <cstring>

using std::cout;
using std::endl;
using std::cerr;
using std::strcat;
using std::strlen;
using std::strcmp;
using std::strcpy;

/** 
MyString
*
*/
MyString::MyString(const char * name_) { 

	if (name_ != NULL) {
		_size = strlen(name_);
		_string = new char[_size + 1];
		strcpy(_string, name_);
	} else 
	{
		_string = NULL;
		_size = 0;
	}
}

MyString::MyString(const MyString& rhs) {
	// aovid the self coyping 
	if (this != &rhs) {
		_size = rhs._size;
		if (rhs._string != NULL) {
			delete _string;
			_string = new char[_size + 1];
			strcpy(_string, rhs._string);
		}
	}
}

MyString::~MyString() {
	delete _string;
}


//char & MyString::operator[](int elem) {
//	assert(elem >= 0 && elem < _size);
//	return _string[_size];
//}
//
//const char & MyString::operator[](int elem) const { 
//	assert(elem >= 0 && elem < _size);
//	return _string[_size];
//}

char & MyString::operator[](int elem) const { 
	assert(elem >= 0 && elem < _size);
	return _string[_size];
}


void test_MyString() 
{
	MyString mystring;
	char ch = mystring[0];
	mystring[0] = 'b';

	const MyString & mystringRef = mystring;
	mystringRef[0] = 'a'; // error, since the conference MyString& return a const char referece, it does not allow writting..
}
