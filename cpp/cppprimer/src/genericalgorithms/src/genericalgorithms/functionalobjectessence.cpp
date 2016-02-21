/**
* functionalobjectessence.cpp
*
*  this discuss the essence of using the functional object
*
* we will discuss the essence of using the functional object, starting from some template function
* then we examine the limitation of the template function, and then introduced a temporarily solution
* but later we proceed to the possibility of using a more advanced features which is called function object and how it solves the problem we have
*/

#include "stdafx.h"
#include <iostream>
#include <functional>
#include <iterator>
#include <vector>
#include <list>


/*
* min
*
*  the limitation of the min function is there is constrain on the use of teh less-than operator. In one case, the underlying type may not support the less-than
*  operator, an image class, may not have the < operator built in
*/
template <typename Type>
const Type & 
min(const Type* p, int size) 
{
	int minIndex = 0;
	for (int ix = 1; ix < size; ++ix) { 
		if (p[ix] < p[minIndex] ) {
			minIndex = ix;
		}
	}
	return p[minIndex];
}

/**
* min
*
* while this solves the problem types not supported, it has a performance overhead that there is a indirect invocation, and there is no way to optimize away the performance overhead.
*/
template <typename Type, bool (*comp)(const Type &, const Type &)>
const Type &
min(const Type* p, int size) 
{
	int minIndex = 0;
	for (int ix = 1; ix < size; ++ix) { 
		if ( comp(p[ix], p[minIndex]) ) {
			minIndex = ix;
		}
	}
	return p[minIndex];

}

/**
* min
* 
* because of the limitation of providing a bool (*comp) (const Type &, const Type& ), here we try to provide a function object
* a function objec behaves like a function, but it is a class
* 
* the benefit of function object is two fold, first, the function call is a inline function, so ther is room for optimization; second, the 
*  object can hold an arbitrary amount of additional data, either cached results or data to help in current operation.
*
* another thing to note is that, you can still pass in a pointer to function, which can automatically deduced to type Comp;
*/
template <typename Type, typename Comp>
const Type&
min(const Type *, int size, Comp comp)
{
	int minIndex = 0;
	for (int ix = 1; ix < size; ++ix) { 
		if ( comp(p[ix], p[minIndex]) ) {
			minIndex = ix;
		}
	}
	return p[minIndex]; 
}