/**
* while const enforce that only const clas sobject can invoke the const member functions. 
* however, there is an exception to that, the exception is the use of mutable keyword
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

class Screen 
{
public:
	// constructor
	inline Screen(int hi = 8, int wid = 40, char bk = '*');


	void home() { _cursor = 0; } 
	void move(int, int); 

	void move(int , int ) const;
	char get() { return _screen[_cursor]; } 
	inline char get(int, int );
	bool checkRange(int, int) const;
	int height() { return _height;  } 
	int width() { return _width;} 

	// not defined, we might go to that later. 
	friend istream& operator >>(istream &, Screen &) ;
	friend ostream& operator <<(ostream&, const Screen &) ;

	void copy(const Screen & obj);

	inline void set(const string &s);
	inline void set(char s);

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

void test_screen1() 
{
	Screen sobj(3, 3); 
	string init("abcdefghi");

	cout << "Screen object )" 
		<< sobj.height() << " , "
		<< sobj.width() << " ) \n\n";

	// Set the content of hte screen 
	string::size_type initops = 0;
    
	for (int ix = 1; ix <= sobj.width(); ++ix) {
		for (int iy = 1; iy <= sobj.height(); ++iy) {
			sobj.move(ix, iy);
			sobj.set(init[initops++]);
		}
	}

	// print the conent of the screen
	for (int ix = 1; ix <= sobj.width(); ++ix) {
		for (int iy = 1; iy <= sobj.height(); ++iy) { 
			cout << sobj.get(ix, iy);
		}
		cout << "\n";
	}

}

void test_const_mutable()
{
	const Screen cs(5, 5);

	// however, now you cannot call the move method, because the move method change the _cursor 
	// to make that happen, you have to change the type of the _cursor
	// from
	//     string::size_type _cursor;
	//
	// to 
	//     mutable string::size_type _cursor;
	cs.move(3, 4);

}