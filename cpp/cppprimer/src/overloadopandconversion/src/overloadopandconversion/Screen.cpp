/**
* file 
*   Screen.h
*
*  description:
*   this is the header file definition of the screen and the ScreenPtr
*/
#include "stdafx.h"
#include "Screen.h"
#include <iostream>
#include <exception>

using std::cout;
using std::endl;
using std::cerr;
using std::exception;

void Screen::move(int x, int y) 
{
	cout << "Screen move -> x: " << x << " y: " << y << endl; 
}

/**
*  point is examined to determine its type, if point is a pointer of some class type, the statement use the semantics of the built-in members
* access operator new . if  point is an object or a reference of some class type, the class is examined for an overloaded member access operator arrow.
*/

void test_use_of_ptr_overload() 
{
	Screen *screen = new Screen();
	ScreenPtr ptr(screen);
	ptr->move(1, 2);
}

void * Screen::operator new(size_t size) { 
	cout << "void * Screen::opreator new (size_t size) " << endl;
	return ::new char[size];
}
void * Screen::operator new(size_t size, Screen* start) {
	cout << "void * Screen::operator new (size_t size, Screen* start) " << endl;
	if (start == NULL) // if you provide a placement new operator and the placement new operaor allocate memory, then you should provide a overloaded delete operator
	{
		throw new exception("bad argument - " "start");
	}
	return start;
}

void Screen::operator delete(void * ptr) 
{
	cout << "void Screen::operator delete(void* start) " << endl;
	::delete ptr;
}

void Screen::operator delete(void * ptr, size_t size)
{
	cout << "void Screen::operator delete(void *start, size_t size) " << endl;
	::delete ptr;
}

void Screen::operator delete(void * ptr, Screen * start)
{
	cout << "void * Screen::operator delete (void * ptr, Screen* start) " << endl;
	// do nothing...
}

/**
*  func(Screen* start) 
*/
// what is steps of the calls of Screen* ps =   new (start) Screen;
// 1. it calls the class operaor new (size_t, Screen *)
// 2. it then calls the default constructor for class Screen to initialize the object
// 3. it then initializes ps with the address of the Screen object
void func(Screen * start) 
{
	Screen* ps = new (start) Screen;
	delete ps; // it calles void Screen::operator delete(void * ptr) , not void Screen::operator delete(void * ptr, Screen start) 
}

void func2()
{
	Screen *ps = new Screen;
	delete ps; // it calls void Screen::operator delete(void * ptr) 
}


void func3(Screen * start) 
{
	try 
	{
		Screen *ps = new (start) Screen(start);
		delete ps; // this is never reached.
	}
	catch (const char *) {
		// you will probably see the "void Screen::operator delete(void * ptr, Screen * start)" called.
	}
}

void func4()
{
	try 
	{
		Screen *ps = new Screen(NULL);
		delete ps; // this line of code is never reached.
	}
	catch (const char *) 
	{
		// you will probably see the "void Screen::operator delete(void * ptr)" called.
	}
}