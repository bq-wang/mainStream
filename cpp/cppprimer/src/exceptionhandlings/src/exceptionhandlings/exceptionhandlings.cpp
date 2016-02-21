// exceptionhandlings.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


void intermixedTryClause() ;
void functionTryBody();

int _tmain(int argc, _TCHAR* argv[])
{
	intermixedTryClause();
	// then we are going to try the function try body 
	functionTryBody();
	return 0;
}



