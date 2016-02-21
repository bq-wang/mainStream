// templatecompilationmodels.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "model1.h"
#include "model2.h"

/*
* templatecompilationmodels.cpp
* @Summary
*  there are two type of compilation model when function templates are talked about. an official definition of "C++ template compilation model" is tat 
*   a C++ template compilation model specifies the requirements for the way programs that defines and use template mus be organized. 
*  there are two types of template compilation model, they are 
*   1. inclusion Compilation model (or inline compilation model)
*   2. seperation compilation model (use of export keyword )
*/
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}


/**
* the definition of the min is in the model1. h
* and you in this file, templatcompilationmodels.cpp, where the template is instantiated, we include 
* the mode1.h file, so this model is called the inclusion compilation model 
*/
int main1(int argc, char* argv[]) 
{
	int i, j; 

	double dobj  = min(i, j);
	return 0;
}



int main2(int argc, char* argv[]) 
{
	int i, j; 

	// the export keyword is not supported in visual studio 2010, and it is not suppported in many compilers
	// have to comment out the following code in order to compile
	//double dobj  = min2(i, j);
	return 0;
}

