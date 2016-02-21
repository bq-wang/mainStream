/***
* @summary
*  stackExcep.h is the header file that define the class that is called iStack, which we will use as the data object to manipulate and demonstate the use 
* of exception in C++
*/

#include <vector>
using std::vector;

//class iStack 
//{
//public : 
//	iStack(int capacity ) : _stack(capacity) , _top(0) { }
//	void pop(int & top_value) ;
//	void push (int value);
//
//	bool full();
//	bool empty();
//	void display();
//
//	int size();
//
//private: 
//	int _top;
//	vector <int> _stack;
//};





/**
* @Summary
* to demonstrate the use of Exception, we are going to define two classes, one is the 
*    popOnEmpty()
* the other is 
*    pushOnFull
*/
class popOnEmpty { /* ....  */ };

class pushOnFull { /* ... */ };

void intermixedTryClause();


/**
* @ verion 2
* this version has the exception spcification on it, where it has in it declaration  the exception that it has 
* 
*  
*/
class iStack 
{
public : 
	iStack(int capacity ) : _stack(capacity) , _top(0) { }
	void pop(int & top_value) throw (popOnEmpty);
	void push (int value) throw (pushOnFull);

	bool full();
	bool empty();
	void display();

	int size();

private: 
	int _top;
	vector <int> _stack;
};