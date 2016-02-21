/**
* file 
*  MyString.h
*  
*  this header is the demonstrate the use of user defined constructor and overload operator
*/
#include <iostream>

class MyString
{
public :
	// overload set of constructors
	// provide automatic initialization
	MyString(const char * = 0);
	MyString (const MyString & );

	// destructor: automatic deinitialization
	~MyString();

	// overload set of assignment operators
	MyString&  operator ==(const char *) const;
	MyString& operator ==(const MyString &) const;
	
	// member access function 
	int size() { return _size; } 
	char * c_str() {  return _string; } 

/*	const char& operator[](int elem) const;
	char & operator[] (int elem);*/  
	// I love better the definition above
	// ths is not safe..
	char& operator[](int elem) const;

private:
	int _size;
	char * _string;
protected:
};