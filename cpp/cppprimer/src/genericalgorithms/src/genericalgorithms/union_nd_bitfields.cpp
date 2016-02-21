/**
* file
*  union_and_bitfields.cpp
* This file tells how to use the enums and the bit fields. 
* 
*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <functional>
#include <iterator>
#include <algorithm>
#include <cstring>

using std::string;
using std::fstream;
using std::copy;
using std::cout;
using std::endl;
using std::cerr;
using std::strcpy;
using std::strcat;
using std::istream;
using std::ostream;

/**
* Suppose we have some expressin as below 
*  int i = 0;
*
* can be converted to the following sequence of symbols. 
*  Type ID Assign Constant Semicolon.
*
* We may choose some data type with member named 'value' to store the the value of the symbol, while we can have another
* member named "token" as a unique cdoe that identifies the token one of the following.. 
*     Type, ID, Assign, Constant, Semicolon; 
* the problem with the value is that it only has one value, but it can multiple data type 
*
*/




enum TokenKind 
{
	Type, 
	ID, 
	Assign, 
	Constant,
	Semicolon
};

/*
* Onething about the union type
* what a union can have
*  it can contain public/private access modifier
*  it can contains constructor or destructor
*  it can conly copy assignment operator or something...
* while what union cannot have:
*  it cannot have member who has contructor, destructor, or copy assignment operator 
*  it cannot have static member functions
*  It cannot have reference members such as int &rfi;
*/
union TokenValue {

public :
	TokenValue()  {}
	TokenValue(int ix_ ): _ival(ix_) {}
	TokenValue(char ch_) : _cval(ch_) {}
	TokenValue(char * sval_): _sval(sval_) {}
	TokenValue(double dval_) : _dval(dval_) {}

	int ival() { return _ival; } 
	char cval() { return _cval; }
	char * sval() { return _sval;} 
	double dval() { return _dval;} 

	char _cval;
	int _ival;
	char *_sval;
	double _dval;
};

class Token 
{
public:
	TokenKind tok;
	TokenValue val;
};


TokenKind parse() 
{
	return ID;
}
/*
*  below shows you how to use the union, it is a best practise to keep a token kind to keep track of what type of data is stored in the union type. 
*/
int lex() {
	Token curToken;
	char * curString;

	int curIVal;


	switch (parse()) { 
	case ID:
		curToken.tok = ID;
		curToken.val._sval  = curString;
		break;
	case Constant:
		curToken.tok = Constant;
		curToken.val._ival = curIVal;
		break;
	default:
		break;
	}
	return 0;
}


/**
*bit fiels
*  bit fiels is a space saving member
*/

typedef unsigned int Bit;

class File {
public:
	Bit mode: 2;
	Bit modified : 1;
	Bit prot_owner : 3;
	Bit prot_group : 3; 
	Bit prot_world : 3; 

	void write();
	void close();
};

void File:: write() {
	modified = 1;
}


void File::close() {
	if (modified) {
		// ... save contents
	}
}

enum { READ = 01, WRITE = 02 } ;

int test_bitfields() {
	File myfile ; 

	myfile.mode != READ;

	if (myfile.mode & READ) { 
		cout << "myfile.mode is set to READ \n";
	}

	return 0;
}