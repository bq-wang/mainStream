/***
* @summary
*  istack.h is the header file that define the class that is called iStack, which we will use as the data object to manipulate and demonstate the use 
* of exception in C++
*/

#include <vector>
using std::vector;

class iStack 
{
public : 
	iStack(int capacity ) : _stack(capacity) , _top(0) { }
	bool pop(int & top_value) ;
	bool push (int value);

	bool full();
	bool empty();
	void display();

	int size();

private: 
	int _top;
	vector <int> _stack;
};


