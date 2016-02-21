/**
* file
*  pointer_to_members.cpp
* This file show show to use pointer to member or pointer to member function.
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


namespace {
	class Screen 
{

private: 
	typedef Screen& (Screen::*Action)();

	//Action (*Menu)[6]; // this is a pointer to pionter to an array of 6 
	//Action *Menu[6];      // this is a array of pointer, size of 6, the same as Action (*Menu[6]);
	static Action Menu[6];

	enum CursorMovements { 
		HOME, FORWARD, BACK, UP, DOWN, END
	};


public:
	// constructor
	inline Screen(int hi = 8, int wid = 40, char bk = '*');


	inline Screen& home() { _cursor = 0; return *this; } 
	void move(int, int); 

	void move(int , int ) const;
	char get() { return _screen[_cursor]; } 
	inline char get(int, int );
	bool checkRange(int, int) const;
	int height() { return _height;  } 
	int width() { return _width;} 

	// 
	inline Screen& forward();
	inline Screen& back();
	inline Screen& end();
	inline Screen& up();
	inline Screen& down();
	
	inline int row();
	
	// not defined, we might go to that later. 
	friend istream& operator >>(istream &, Screen &) ;
	friend ostream& operator <<(ostream&, const Screen &) ;

	void copy(const Screen & obj);

	inline void set(const string &s);
	inline void set(char s);
	

	// below we are going to show the importance of the function as pointer to members
	Screen& repeat(Action op, int times);
	Screen& move(CursorMovements cm);

private:
	inline int remainingSpace();

	string _screen;
	// from the above declaration below, to allow the move method to be called from a const object
	//string::size_type _cursor;
	mutable string::size_type _cursor;
	int _height;
	int _width;


	/*static const int _height = 24;
	static const int _width =80;*/

	static const int BELL = '\007';


};

void Screen::copy(const Screen &obj) 
{
	/// fif this Screen object and objs are the same objcet
	// no copy necessary 
	/// we look at hte 'this ' pointer 
	if (this != &obj) { 
		_height = obj._height;
		_width =obj._width;
		_cursor = 0;
		// create a new string 
		// its content is the same as obj._screen
		_screen = obj._screen;
	}
}


bool Screen::checkRange(int row, int col) const { 
	if (row < 1 || row > _height || 
		col < 1 || col > _width ) { 
			cerr << "Screen coordinates (" 
				<< row << ", " << col
				<< " ) out of bounds.\n";
			return false; 
	}
	return true;
	// a  better way is to write as such 
	//return !((row < 1 || row > _height || col < 1 || col > _width));
}

inline void Screen::move(int r,  int c) 
{
  // move _cursor to absolute position
	if (checkRange(r, c) ) { 
		int row = ( r - 1) * _width; // row location 
		_cursor = row + c - 1;
	}
}

inline void Screen::move(int r, int c) const 
{
	// can we directly call the Screen::move method or can we ask the Screen::move(int r, int c) to call the (Screen::move(int r, int c) const" method
	if (checkRange(r, c)) { 
		int row = (r - 1) * _width;
		_cursor = row + c - 1; // because now the _cursor is mutable members, it does not matter if you call it from a const contetxt
	}
}


// a side note, inline declaration should be placed 
// in the header file. normally you will carry the inline keyword with you . 
inline char Screen::get(int r, int c) {
	move(r, c);
	return get();
}

inline void Screen::set(const string &s) {
	// write string beginning at current _cursor position 
	int space = remainingSpace();
	int len = s.size();
	if (space < len) {
		cerr << "Screen: warning: truncate: " 
			<< "space: " << space 
			<< "string length: " << len << endl;
	}
}

inline void Screen::set(char ch) {
	if (ch == '\0') { 
		cerr << "Screen: Warning: " 
			<< "Null character (ignored).\n";
	} else { 
		_screen[_cursor] = ch;
	}
}
inline int Screen::remainingSpace() { 
	 // currrent position is no longer remaining
	int sz = _width * _height;
    return (sz - _cursor);
}


inline Screen::Screen(int hi, int wid, char bk) : 
    _height (hi),
	_width(wid),
	_cursor(0),
	_screen(hi * wid, bk) 
{
	// all the work is done with the number initialize list 

}

Screen::Action Screen::Menu[6] = {
		&Screen::home, 
		&Screen::forward,
		&Screen::back,
		&Screen::up,
		&Screen::down, 
		&Screen::end
	};

inline Screen& Screen::forward() { 
	++_cursor;

	// check if top of screen: wrap around
	if (_cursor == 0) 
	{
		home();
	}
	return *this;

}

inline Screen& Screen::back() { 
	// move _cursor backward one screen element
	// check for opt of screen: wrap around

	if (_cursor == 0)  {
		end();
	}
	else --_cursor;

	return *this;
}

inline Screen& Screen::end() { 
	_cursor = _width * _height - 1;
	return *this;
}

inline Screen& Screen::up() { 
	// move _cursor up one row of screen
	// do not wrap around; rather, ring bells

	if (row() == 1) // at top ?
		cout << BELL << endl;
	else 
		_cursor -= _width;

	return *this;
}
inline Screen& Screen::down() { 
	if (row() == _height) // at bottom?
		cout << BELL << endl;
	else 
		_cursor += _width;

	return *this;
}


inline int Screen::row() {
	return (_cursor + _width) / _width;
}




inline Screen& Screen::repeat(Action op, int times) {
	for (int i = 0; i < times; ++i) 
	{
		(this->*op)();
	}
	return *this;
}

inline Screen& Screen::move(CursorMovements cm)
{
	return (this->*Menu[cm])();
}

// A pointer to member function must first be bound to an object or a pionter to obtain a this pointer for 
// function invocation before the function to which it refers can be called. 

// below shows you how to define 
//    "a pointer to member of class Screen of type short."
//
//  short Screen::*
//


//short Screen::*ps_Screen;
//
//int Screen::*ps_Screen  = &Screen::_height;
//ps_Screen = &Screen::_width;
//
//// if you want to declare 
////   a pointer to Screen member function capaple of referring to the mbme rfunction height() and width() is as follow
//int (Screen::*) ();
//// e.g.
//int (Screen::*pmf1)() = 0;
//int (Screen::*pmf2)() = &Screen::height;
//
//pmf1 = pmf2;
//pmf2 = &Screen::width;


//// you can make some typedefs
//typedef Screen& (Screen::*Action)();
//
//
//Action _default = &Screen::home;
//Action next = &Screen::forward;
//
//// below shows how you can invoke method through the pointer to member methods
//Screen myScreen;
//typedef Screen& (Screen::*Action)();
//Action _default = &Screen::home;
//
//extern Screen& action(Screen&, Action = &Screen::display);
//
//void ff()
//{
//	action(myScreen);
//	action(myScreen, _default);
//	action(myScreen, &Screen::end);
//}

////invocation of the pointer to class member
////
//int (Screen::*pmfi) () = &Screen::height;
//Screen& (Screen::*pmfS)(const Screen&) = &Screen::copy;
//
//
//Screen myScreen, *bufScreen;
//
//// direct invocation of the member function 
//if (myScreen.height() == bufScreen->height() )  
//	bufScreen->copy(myScreen);
//
//// equivalent invocation through the pointer to member function 
//if ( (myScreen.*pmfi)() == (bufScreen->*pmfi()()) {
//	(bufScreen->*pmfS)(myScreen);
//}

//typedef int Screen::*ps_Screen;
//Screen myScreen, *tmpScreen = new Screen(10, 10);
//
//ps_Screen pH = &Screen::_height;
//ps_Screen pW = &Screen::_width;
//tempScreen->*pH = myScreen.*pH;
//tempScreen->*pW = myScreen.*pW;


}



