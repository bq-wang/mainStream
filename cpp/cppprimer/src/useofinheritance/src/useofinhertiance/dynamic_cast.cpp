/**
* file:
*  dynamic_cast.cpp
* description:
* example to show how/when to use the dynamic cast 
*/

#include "stdafx.h"


/** why do we need dynamic_cast
* consider the following case. 
*/

//class employee
//{
//public: 
//	virtual int salary(); 
//};
//
//class manager : public employee
//{
//public: 
//	int salary();
//};
//
//class programmer : public employee
//{
//public: 
//	int salary(); 
//};

/* 
* now we will add more method to the class hierarchy above 
*/

//class employee
//{
//public:
//	virtual int salary(); 
//	virtual int bonus();
//};
//
//class manager : public employee 
//{
//public:
//	int salary();
//};
//
//class programmer : public employee
//{
//public:
//	int salary(); 
//	int bonus();
//};





class employee
{
public:
	virtual int salary();
};

class manager : public  employee
{
public: 
	int salary();
};


class programmer : public employee
{
public:
	int salary(); 
	int bonus();
};

#include <exception>
using std::exception;

int employee::salary() { throw new exception(); } 
int manager::salary() { throw new exception(); } 
int programmer::bonus() { throw new exception(); } 
int programmer::salary() { throw new exception(); } 

class company
{
public :
	//void payroll(employee *pe);
	void payroll(employee &re) ;
};

/**
* the 
*  dynamic_cast 
* operator therefore performans two operational at once, it verifies that the request cast is indeede valid, and then only if it
* is valid does it performs the cast. The verfication take place at 
*  compile time
* the dynamic_cast is safer than the other c++ cast operations because the other casts do no verify whether the cast can actually be performed. 
* 
* the dynamic_cast is used for safe casting from a pointer to base class to a pointer to a derived class, often referred to as safe downcasting. 
*/
//void company::payroll(employee *pe) 
//{
//	// 
//	programmer *pm = dynamic_cast<programmer *> (pe); 
//
//	// if pe refers to an object of type programmer, 
//	// the dynamic_cast is successful,
//	// and pm refers to the start of the programmer object
//	if (pm) { 
//		// use pm to call programmer::bonus();
//		// if pe not refer to an object of type programmer, 
//		// the dynamic_cast fails, 
//		// an pm has the vlaue 0 
//	} else {
//		// use of employee's member function 
//	}
//}

/*
* dynamic_cast
* 
* can converts a pointer to a base class to a pointer to a derived class. A dynamic cast can also be used to convert an lvalule 
* of base class to a reference to a derived class the syntax is as follow 
*/
void dynamic_cast_references()
{
	//employee * pe = new employee();
	programmer * pp= new programmer();
	employee & emp = dynamic_cast<programmer&>(*pp);
}

/** 
* error condition
* 
*/
#include <typeinfo>
void company::payroll(employee & re) 
{
	try { 
		programmer &rm = dynamic_cast<programmer &>( re); 
	} catch (std::bad_cast) { 
		// use of employee member functions 
	}
}