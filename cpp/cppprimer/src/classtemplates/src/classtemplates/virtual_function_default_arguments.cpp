/**
* file
*  virtual_function_default_arguments.cpp
* description:
*  this file demonstrate the use of default argument when the virtual function are considered
*
*/
#include "stdafx.h"
#include "virtual_function_default_arguments.h"


/**
*  void virtual_function_default_arguments()
*  
* as you can see from the output, the default value applied is determined through the the invoker, could it be the pointer, or the reference.
* so that if you invoke through derived *, then the default argument value of derived version is used. 
* should you use the base *pointer, the default arguments value of the base classes is choosen.
* 
* so in nutshell, the value of defaulot argument is not determined at runtime, but rather at compile time.
*/
void virtual_function_default_arguments()
{
	derived * pd =  new derived;
	base *pb = pd;

	int val = pb->foo();
	cout << "main(): val through base: "
		<< val << endl;

	val = pd->foo();
	cout << "main() : val through derived" 
		<< val << endl;
}

/**
*  void virtual_function_default_arguments2()
*  
* to use the default value with virtual functio has farreaching meaning, the runtime nature of virtual function and the static nature 
* of default argument does not fit in well with each other. however, if you do want to have default argument with virtual function
* instead of simply saying no, you can provide some place holder value which indicate that no value has been passed by the user
* as shown in the code below.
*/
void virtual_function_default_arguments2()
{
	derived * pd =  new derived;
	base *pb = pd;

	int val = pb->bar();
	cout << "main(): val through base: "
		<< val << endl;

	val = pd->bar();
	cout << "main() : val through derived" 
		<< val << endl;
}