/**
* virtualnewoperator.cpp
*
*  There is an exception to the exact match of the return type, in the base/dervied class hierarchy, it is allowed that you return a object/reference/pointer to derived class while 
*  the based class declared to return a base one 
*  
* this is indeed supported, unlike the non-class function, where you just must proivde the exact match 
*/

#include "stdafx.h"

class Base 
{
public :
	Base() { }
	Base(Base &base) {}
	virtual Base *clone();
protected:
	Base *print();
private:

};


class Derived : public Base {
public:
	Derived() {}
	Derived (Derived &derived) : Base(derived) {} 
	virtual Derived *clone();
protected:
	Base *print();

};



Base* Base::clone(){ 
	return new Base(*this);
}


Derived* Derived::clone() {
	return new Derived(*this);
}


void test_exception_to_return_match() {
	Derived * d = new Derived();
	Base *b = d;

	b = d->clone();
	Derived *d2 = d->clone();
}