#include <iostream>

using namespace std;

// if you have this statement uncommented
// then you will have the following 
// unresolved symbols: 
//    void __cdecl f(void) (?@@YAXXZ)
// -- 

/**
* @Name
*  lib.cpp
* @Comment:
*   use an external symbol, which is f(), there is a local f symbol defined in the main.cpp file
* you are suppose to get the following compile error or similar (depends on the implementation of the compiler)
*   unresolved symbols: 
*     void __cdecl f(void) (?@@YAXXZ)
*   
*/
//extern void f();
//
//void g()
//{
//	f();
//};

