/**
* file:
*    genericalgorithmdemo1.cpp
* this is a file that demonstrate the use of the generic algorithm 
*
*/

#include "stdafx.h"
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>

using std::vector;
using std::find;
using std::list;

using std::cout;
using std::endl;
using std::cerr;
/*
* There are five kind of iterator used in the C++ standard libraries
*/



int arrayIteratorDemo1()
{
	int search_value = 0;

	int ia[6] = {27, 20, 17, 47, 109, 83};
	vector<int> vec(ia, ia + 6);

	vector<int>::iterator presult;
	presult = find(vec.begin(), vec.end(), search_value);
	if (presult != vec.end()) {  // this is a common way to test if the search is successful
		cerr << "Could not find the value " << search_value << endl;
	}

	cout << "The value : " 
		<< search_value 
		<< (presult == vec.end() ? "is not present " : " is present")
		<< endl;
	return 0;
}


// the containerIteratorDemo1 example shows that 
// the same generic algorithm can apply to both the conainer or array 
int containerIteratorDemo1()
{
	int search_value = 0;

	int ia[6] = {27, 20, 17, 47, 109, 83};
	// you can use list rather than vector 
	// 
	list<int> ilist(ia, ia + 6);

	// and to iterate through the container, you can get the container<type_argument>::iterator 
	// and use the iterator to search/enumerate through the collection.
	//
	list<int>::iterator presult;
	presult = find(ilist.begin(), ilist.end(), search_value);
	if (presult != ilist.end()) {  // this is a common way to test if the search is successful
		cerr << "Could not find the value " << search_value << endl;
	}

	cout << "The value : " 
		<< search_value 
		<< (presult == ilist.end() ? "is not present " : " is present")
		<< endl;

	return 0;
}

