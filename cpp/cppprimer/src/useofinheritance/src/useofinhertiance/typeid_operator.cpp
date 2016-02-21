/**
* file:
*  typeid_operator.cpp
* description:
* the code below hows how to use the typeid operator 
*/



#include "stdafx.h"
#include <typeinfo>
#include "typeid_operator.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cerr;
using std::type_info;

void typeid_test() { 
	programmer obj ;
	programmer &re = obj;

	// we look at name() in the subsection on type_info 
	// below, name() returns the C-style string: "programmer"
	cout << typeid(re).name() << endl;
}


/**
* the operand of the typeid operator can be expression or type names of any type 
*
*/
void typeid_operand()
{
  int iobj;
  cout << typeid(iobj).name() << endl; // print : ints
  cout <<typeid(8.16).name() << endl; // prints : double
}
/**
* if the typeid operand is a class type, but not of a class type with virtual functions. then the typeid operator indicates the type of 
* the operand is well, not the type of the underlying object
*/

class Base 
{
};
class Derived : public Base { };

void typeid_non_virtual_class() 
{
	Derived dobj;
	Base *pb = &dobj;

	cout << typeid(*pb).name() << endl; // prints : Base
}

/*
* The result of the typeid operator can be compared 
*/ 
void typeid_result_comparable() 
{
	employee * pe = new manager();
	employee & re = *pe;
	if (typeid(pe) == typeid(employee *) ) cout << "typeid(pe) == typeid(employee *)" << endl; // true 
	if (typeid(pe) == typeid(manager *) ) cout << "typeid(pe) == typeid(manager*)" << endl;    // false
	if (typeid(pe) == typeid(employee) ) cout <<  "typeid(pe) == typeid(employee)" << endl;    // false
	if (typeid(pe) == typeid(manager) ) cout << "typeid(pe) == typeid(manager) " << endl;      // false
}

/*
*  if the typeid oeprand is a class type , where if class to be examined is of virutal functions, then the 
* real derived classes will be returned.
*/
void typeid_result_virtual_class() 
{
	employee *pe = new manager();
	employee &re = *pe; 
	if (typeid(*pe) == typeid(manager)) cout << "typeid(*pe) == typeid(manager)" << endl; // true 
	if (typeid(re) == typeid(employee)) cout << "typeid(re) == typeid(employee)" << endl; // false 

	if (typeid(&re) == typeid(employee *)) cout << "typeid(&re) == typeid(employee *)" << endl;  // true 
	if (typeid(&re) == typeid(manager *)) cout << "typeid(&re) == typeid(manager *)" << endl; // false 
}

//class type_info { 
//private:
//	type_info(const type_info&);
//	type_info& operator = (const type_info &);
//public:
//	virtual ~type_info();
//
//	int operator ==(const type_info&) const; 
//	int operator!=(const type_info &) const;
//	
//	const char *name() const; 
//};

/*
* the only way to construct the type_info object is to use the typeid operator. 
*/
/**
* what is containd in the type_info class is implementation dependant. the name() const char * is the only member guaranteed to be provided by all C++ implementation
* , though it is possible that implementaion dependant may provide additional support. what can be added, basically any information that a compiler can provide about a type
* about a type can be added. 
*/
/*
* 1. a list of the class member functions. 
* 2. what the layout of an object of this clases type looks like in storage, that is , how the member and base subobjects are mapped
*/
class extended_type_info  :public type_info {};
typedef extended_type_info eti;

void func(employee * p)
{
	// downcast from type_info * to extended_type_info*
	if (const eti * eti_p = dynamic_cast<const eti *>(&typeid(*p))) {
		// if dynamic_cast succeeds
		// use extended_type_info information through eti_p
	} else{ 
		// if dynamically fails
		// use standard type_info information
	}
}