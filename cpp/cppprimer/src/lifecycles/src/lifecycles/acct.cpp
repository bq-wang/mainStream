/**
* file 
*   acct.cpp
* description: 
*   the implementation source file of the acct.h
*/


#include "stdafx.h"
#include "acct.h"
#include <iostream>
#include <typeinfo>
#include <exception>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
#include <list>
#include <array>
#include <iterator>
#include <cstring>
#include <memory>

using std::cout;
using std::endl;
using std::end;
using std::cerr;
using std::fstream;
using std::vector;
using std::list;

using std::strcpy;
using std::strcat;
using std::strlen;

using std::auto_ptr;


/*=================================
* ctor(s) and dtor(s)
==================================*/

// for non-class members, it does not matter if you initialize the non-class member in the initializer list of you initialize the 
// the non-class member inside the constructor's body
// the convention is to initialize the non-class members inside the ctor's body, while initialize the class members in the initializer's initializer list
Account::Account() {
	_balance = 0.0;
	_name = 0;
	_acct_nmbr = 0;
	_acct_nmbr = get_unique_acct_nmbr();

	cout << "Account::Account" << endl;
}

// As said before,you can initialize the non-class member in the initliazer list. 
//Account::Account() :
//   _balance (0.0), _name(0), _acct_nmber(0)
//{
//}

// though the declaration of the Account is as such
// Account(const char * naem_, double balance_ = 0.0);
// but in our discussion, we can NOT redefine the default value of the balance_
Account::Account(const char * name_, double balance_) {
	cout << "Account::Account(const char * name_, double balance_)" << endl;

	if (name_ != NULL) {
		// thereis no need to call the delete operator because 
		// in the intializer, the name_ is guaranteed to be filled with som randome bitness
		// while the static members will be filled with zero or its default values (normally it is zeros)
		//delete name_;
		_name = new char[strlen(name_) + 1];
		strcpy(_name, name_);
	}
	_balance = balance_;

	_acct_nmbr = get_unique_acct_nmbr();
}

Account::Account(const Account& rhs) 
	: _balance(rhs._balance)
{
	cout << "Account::Account(const Account & rhs)" << endl;
	_name = new char[strlen(rhs._name) + 1];
	strcpy(_name, rhs._name);

	// must copy rhs._acct_nmbr
	_acct_nmbr = get_unique_acct_nmbr();
}

unsigned int 
	Account::_unique_acct_nmbr;

unsigned int
Account::get_unique_acct_nmbr() { 

	return ++_unique_acct_nmbr;
}

void 
	Account::return_acct_nmbr(unsigned int acct_nmbr) { 

}

inline
const char *
	Account::name() {
		return _name;
}

// Destructor server primarily to relinquish resources acquired either within the constructor or urnig the lifetime 
// thelifetime of the class object, again such as freeing a mutal exclsion lock or deleting memory allocated through operator new.
Account::~Account()  
{
	delete _name;
	return_acct_nmbr(_acct_nmbr);

	// there is no need to do the check 
	// because the compiler will ensure that. 
	//if (_name != NULL ) delete _name;
	// and since the object is destructed, there is no need to rest to some uninitialized value.
	//_name = 0;
	//_balance = 0;
	//_acct_nmbr = 0;
}

Account global;

void destructor_life_cycle_test()
{
	Account local("Anna live Plurablle", 1000);
	Account &loc_ref = global;
	auto_ptr<Account> pact(new Account("stephen Dedalus"));

	{
		Account local_too("Stephen Hero");
		// the local_too will destroy before exit the current local space. 
	}
	// the auto_ptr will destruct here

}

/**
[placeholder]


there is some discussion on the use of explicit call of the destructor, you can find the code from the book
*/

//void destructor_explicit_call() 
//{
//	char *arena = new char[sizeof Image];
//
//	Image * ptr = new (arena) Image("Quasimodo");
//
//	Image *ptr = new (arena) Image("Esmerelda");
//
//	//you cannot delete the ptr, because it will reclaim the memory in addition to call the destructor
//	delete ptr;
//
//	// but instead, you should do something like this:
//	ptr->~Image();
//
//	// and when  you finish using the arena memory , you can free the location by this 
//	delete arena;
//	// it will not call the destructor, because arena is of type char *
//}
