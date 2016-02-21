// explicitspecialization.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "explicitspecialization.h"
using std::cout;
using std::endl;
#include "templatefunctionoverloading.h"

/**
* in this project we are going to examine the template explicit specialiation
*
* @Comment
* So what is function template specialization; given an example, for the following function template
*   template <class T>
     T max (T t1, T t2) 
	 {
	    return (t1 > t2 ? t1 : t2);
     }
* it works for most value types, however what if the type passed in is a pointer, list const char *, or what if the function does not provide the less than operator
* and it provides some alternatives;
* 
* In such situation we might provide a specified template with a more explicity value of parameter type and define/declare the template's body for that specialized type parameter.
*/



int _tmain(int argc, _TCHAR* argv[])
{
	int i = max(10, 5); // this will instantiate the generic function template 

	// call to explict specialiation 
	// const char * max<const char *> (const char *, const char *);
	const char * p= max("hello", "world");

	cout << "i: " << i << " p: " << p << endl;


	//TestTemplateAfterMin_T_U();
	TestTheMostSpecialized();

	return 0;
}

