/**
* file 
*   heap_array_initializer.cpp
* description: 
*   THis shows some way to initialize an array of classes in the heap 
*/

#include "stdafx.h"
#include "acct.h"
#include <iostream>
#include <cstddef>
#include <new>  // include this header to use the placement new operator.
#include <utility> // what willl use use this for? abort()???
#include <vector>


using std::cout;
using std::endl;
using std::cerr;
using std::vector;
using std::pair;

typedef pair<char *, double > value_pair;

/** init_heap_array() 
*
*  declared as a static member function
*  provides for allocation and initialization
*  of heap array of class objects
*  init_values: init value pair for array elements
*  elem_count: number of elements in array if 0, array is size of init_value vector
*/

// the default value cannot be redefined.
Account * 
	Account::init_heap_array(vector<value_pair> &init_values, 
	vector<value_pair>::size_type elem_count) 
{

	vector<value_pair>::size_type vec_size = init_values.size();

	if (vec_size == 0 && elem_count == 0) { 
		return 0;
	}

	// size of the array to allocate is either elem_count 
	// or, if elem_count is 0, the size of vector..
	size_t elems = elem_count ? elem_count : vec_size;

	//grab a chunk of raw memory to stoe array
	char * p = new char [sizeof(Account) * elems];

	// individuallky initialize each array elements
	int offset = sizeof(Account);
	for (int ix = 0; ix < elems; ++ix) {
		// offset to the ixth elements,
		// if an initial value pair is provided
		//   pass that pair to the constructor
		// otherwise, invoke the default constructor 
		if (ix < vec_size) { 
			new (p+offset * ix) Account(init_values[ix].first, init_values[ix].second);
		}
		else new (p+offset * ix) Account;
	}

	// ok: elements allocated and initialized
	//    retur pointer to first element
	return (Account *) p;

}