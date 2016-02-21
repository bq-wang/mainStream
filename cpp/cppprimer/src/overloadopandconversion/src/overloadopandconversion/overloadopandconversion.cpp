// overloadopandconversion.cpp : 定义控制台应用程序的入口点。
//

/** 
* file 
*   overloadopandconversion.cpp
*
*/

#include "stdafx.h"
#include "MyString.h"
#include "Screen.h"


void test_use_of_ptr_overload();
void func(Screen * );
void func2();
void func3(Screen * );
void func4();

int _tmain(int argc, _TCHAR* argv[])
{
	//test_use_of_ptr_overload();
	Screen * screen  = new Screen();
	func(screen);
	func2();
	screen = new Screen();
	func3(screen);
	delete screen;
	func4();
	return 0;
}

