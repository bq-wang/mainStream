#include "stdafx.h"
#include "stackExcp.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

//void iStack::pop(int &top_value)
//{
//	if (empty()) 
//	{
//		throw popOnEmpty();
//	}
//	top_value = _stack[--_top];
//	cout << "istack::pop(): " << top_value << endl;
//}
//
//
//void iStack::push(int value)
//{
//	cout << "istack::push( " << value << " ) \n";
//	if (full()) 
//	{
//		throw pushOnFull();
//	}
//	_stack[_top++] = value;
//
//}

/**
* @ version 2
* this version contains the function declaration contains the function exception specification
*/
void iStack::pop(int &top_value) throw (popOnEmpty)
{
	if (empty()) 
	{
		throw popOnEmpty();
	}
	top_value = _stack[--_top];
	cout << "istack::pop(): " << top_value << endl;
}


void iStack::push(int value) throw (pushOnFull)
{
	cout << "istack::push( " << value << " ) \n";
	if (full()) 
	{
		throw pushOnFull();
	}
	_stack[_top++] = value;

}


bool iStack::empty()
{
	return _top <= 0;
}

bool iStack::full()
{
	return _top > _stack.capacity(); // a common pitfall is tha the use _stack.size();
}

void iStack::display()
{
	cout << "display: ( ";
	for (int i = 0; i < _top; ++i)
	{
		// a common case of error is that if you write as follow
		// the code will be like this:
		//   cout << _stack[i} << ( i == _top - 1) ? ")" : "";
		// it will output some wierd output , guess the compiler try to output the value of the condition test part of the  the ternary expression
		// that is because of the order of the execution , 
		// where the ?: has a lower precedence than the << operator
		// so it will first output the evalution value of the condition expression and then if depends on the return resutlt, which is a 

		cout << _stack[i] << " " << ((i == _top - 1) ? " )" : "") ;
		if (i != 0 && i % 8 == 0 || i == _top - 1 ) cout << endl;
	}

}


void intermixedTryClause()
{
	iStack stack(32);

	for (int ix = 0;ix < 51; ++ix)
	{
		try 
		{
			if (ix % 3 == 0) {
				stack.push(ix);
			}
		}
		catch (pushOnFull) 
		{
			//cout << "caught error on pushOnFull" << endl;
		}
		if (ix % 4 == 0) 
		{
			stack.display();
		}


		try 
		{
			if (ix % 10 == 0)
			{
				int dummy;
				stack.pop(dummy);
				stack.display();
			}
		}
		catch (popOnEmpty) 
		{
			//cout << "caught error on popOnEmpty" << endl;
		}
	}
}

/**
* Below test the function try body techniques where you can put the try clause with the catch clauses right after the function body without 
* the function opening body '{' or the function closing body '}'
*/
void functionTryBody() try 
{
	 iStack stack(32);
	 for (int i = 0; i < 51; ++i ) {
		 int val;
		 if (i % 3 == 0) stack.push(i);
		 if (i % 4 == 0) stack.display();
		 if (i % 10 == 0) { stack.pop(val); stack.display(); } 
	 }
}
catch (popOnEmpty) { /* */ } 
catch (pushOnFull) { /* */ }


void (* pf) (int) throw (std::string);

/**
* exception declaration is part of the function interface.
*/
typedef int exceptionType;
void no_problem() throw ()
{}
void doit(int, int) throw (std::string,  exceptionType)
{}
void recoup(int , int ) throw (exceptionType) {}

int exception_specification() 
{
	// ok, recoup is as restrictive as pf1
  void (*pf1)(int, int) throw (exceptionType) = &recoup;
  // OK, no_problem is more restrictive than pf2
  void (*pf2)() throw (std::string) = &no_problem;
  // it is error as according to the book, however, it does work 
  // on VC++, it does not throw out errors?
  void (*pf3)(int , int) throw (std::string) = &doit;
  return 0;
}

/** an empty exception specification guaranttees that the function does not throw any exception .for example 
* the function no_problem guarantee not to throw any exception 
*/
extern void no_problem() throw();