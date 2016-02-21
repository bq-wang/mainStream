/**
* file 
*   array_initializer.cpp
* description: 
*   This shows how to use the array initializer to apply the array initialization
*/

#include "stdafx.h"
#include "acct.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cerr;


void test_array_initializer() { 
	cout << "initialize with the default single argument" << endl;

	// if object only has one single explicit constructor argument ,you can do this 
	Account pooh_pals_single_args[] = { "piglet", "Eeyore", "Tigger" };

	// and of course, if you want to specify mutiple arguments, here is the way 
	// ther is one misunderstood in that 
	// if will first call the 
	//    Account ("piglet", 1000.0);
	// and then the copy constructor will be called
	//   Account(const Account & rhs);
	// the misconcept is that it will first create the temporary objects, which are 
	// in the { ... } 
	// block, then pooh_pals_mutiple_args will be invoked to get the right object contructed. 
	//
	cout << "initialize with the multiple arguments" << endl;
	Account pooh_pals_multiple_args[] = {
		 Account("piglet", 1000.0),
		 Account("Eeyore", 1000.0),
		 Account("Tigger", 1000.0)
	};

	// if you want to initialize some with the default constructor, here is the way how you do it
	cout << "initialize with the multiple arguments mixed with default argument" << endl;
	Account pooh_pals_multiple_args_with_default_constructor[] = { 
		Account("piglet", 1000.0),
		Account("Eeyore", 1000.0),
		Account(),
	};

	// and if you specify the size, but in the initializer list, there is no insufficient  number of 
	// object in the initializer list, 
	// then the default constructor will be called
	cout << "Default constructor will be called if the initializer list number is smaller than the array/contaier size" << endl;
	Account pooh_pals_multiple_args_with_insufficient_objects[3] = {
		Account("piglet", 1000.0),
		Account("Eeyore", 1000.0),
	};

	// while if you are calling the new opertor, there is no way to specify the initializer with arguments
	cout << "default constructo will be called new operator on the heap" << endl;
	Account * pact = new Account[10];

	// 
	delete[] pact;

}