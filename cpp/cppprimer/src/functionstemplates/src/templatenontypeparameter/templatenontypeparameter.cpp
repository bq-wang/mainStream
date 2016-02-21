// templatenontypeparameter.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


/**
* @Summary
*   template non-type parameter 
* @Comment:
*   a non-type parameter consists of ordinary parameter declaration, A template non-type parameter indicate a constant in the template definition
*   an example of the non-type parameter is 'size' which represents the size of an array to which arr refers as follow.
*   
* below shows something about the template function initialization when non-type parameter is instantiated
*
* the results show that the compiler should be able to infer the value of the non-type parameter if it can, and there is no need to provide a explicit 
* value for such parameter, in this case 
* since 
*  int ia[] = { 10, 7, 14, 3, 25};
* has know size of 
*  5
* and when you call
*  min(ia);
* it will match agains the definition
*  Type min(const Type (&r_arr)[size])
* so we know 
*  size == 5
* so you don't need to write as 
*  min(ia, 5);
* and it will error, if you try to 
*  min(ia, 5)
*/


template<typename Type, int size>
Type min(Type (&r_arr)[size]) { 
	Type min_val = r_arr[0];
	for (int i = 1; i < size; i++) { 
		if (r_arr[i] < min_val) {
			min_val = r_arr[i];
		}
	}

	return min_val;
}


template<typename Type, int size>
const Type min(const Type (&r_arr)[size]) { 
	Type min_val = r_arr[0];
	for (int i = 1; i < size; i++) { 
		if (r_arr[i] < min_val) {
			min_val = r_arr[i];
		}
	}

	return min_val;
}

// if it is not the pointer type 
// the position of the const is irrelevant
// the same as the reference type
//
//template<typename Type, int size>
//Type& const min(Type& const (&r_arr)[size]) { 
//	Type min_val = r_arr[0];
//	for (int i = 1; i < size; i++) { 
//		if (r_arr[i] < min_val) {
//			min_val = r_arr[i];
//		}
//	}
//
//	return min_val;
//}


//template<typename Type, int size>
//const Type&  min(const Type& (&r_arr)[size]) { 
//	Type min_val = r_arr[0];
//	for (int i = 1; i < size; i++) { 
//		if (r_arr[i] < min_val) {
//			min_val = r_arr[i];
//		}
//	}
//
//	return min_val;
//}


//template<typename Type, int size>
//Type const&  min(Type const& (&r_arr)[size]) { 
//	Type min_val = r_arr[0];
//	for (int i = 1; i < size; i++) { 
//		if (r_arr[i] < min_val) {
//			min_val = r_arr[i];
//		}
//	}
//
//	return min_val;
//}

// #include <iostream>
using namespace std;
// suppose we hve two array whose size is known at conpile time
int ia[] =  { 10, 7, 14, 3, 25 } ;
double da[] = { 10.2, 7.1, 14.5, 3.2, 25.0, 16,8 } ;




int _tmain(int argc, _TCHAR* argv[])
{

	int i = min(ia);
	if (i != 3) { 
		cout << "?? oops: integer min() failed\n";
	} else { 
		cout << "!!OK: integer min() worked\n";
	}


	// instantiation of min() for an array o f6 doubles
	// with type => double, size => 6
	double d = min(da);
	if (d != 3.2) { 
		cout << "??oops: double min() failed\n";
	} else { 
		cout << "!!ok: double min() worked\n";
	}
	return 0;
}

/**
* @Summary
*  template function are instantiated when it is invoked or when its address is taken 
*/ 



typedef int (&ria)[10];
typedef double (&rda)[10];


typedef const int (&rcia)[10];
typedef const double (&rcda)[10];



void func( int (*) (ria))
{}

void func(double (*) (rda))
{}


void func( int (*) (rcia))
{}

void func(const double (*) (rcda))
{}

double fun1(rda r)
{
	return 0.0;
}


int main2(int argc, _TCHAR* argv[])
{
	// error: (which instantiaon of min()?
	//func(&min);

	//func((int (*) (int (&)[10])) &min);
	//func(static_cast<const double (*) (rcda)> (&min));
	//func(fun1);
	return 0;
}


int main3(int argc, _TCHAR* argv[]) { 

	// it does not matter if you have int const or const int
    const int c_a = 0;
	int const c_a2 = 0;

	// nor does it matter if you have const int & or int const & 
	const int &r_ca = c_a;
	int const &r_ca2 = c_a;

	// the thing that get tricker is when the pointer is involved
	// ponter to array
	int *p_ia = ia;
	// point to const array
	const int *p_cia = ia;

	// reference to pointer to const array
	const int *&r_cia = p_cia;
	// reference to pointer to const array
	int const *&r_cia2 = p_cia;

	// const reference to pointer to array
	int * const &r_cia3 = p_ia;
	//int * &const r_cia4 = p_ia; // this is a compilation warning, chronical use error, wrong qualification

	// const reference to pointer to const array
	const int * const & r_cia4 = p_cia;

	// you cannot change the value of r_cia3 and r_cia4
	//r_cia3 = 0; // error: you cannot assign to const 
	//r_cia4 = 0; // error: you cannot assign to const

	return 0;
}

