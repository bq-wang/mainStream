/**
* file:
*  stack_excp_inheritance.cpp
* description:
* the source file that shows how to use class hierarchy to throw and handle exception and some knowledge about how the exception handling system works. 
*/

#include "stdafx.h"
#include "stack_excp_inheritance.h"

/** 
* many stap take place as a consequence of executing this throw exception 
*   
* 1. the throw exception creates a temporary object of class type pushOnFull by calling the class constructor
* 2. An exception object of type pushOnFull is created to be passed to the exception handler. The exception object is is a copy of the temporary object created by the throw expression in step 1. it is created by calling 
the calss pushOnfull's copy constructor
* 3. The temporary object created by the throw expression in step 1 is destroyed byfore the search for a handler starts.
*/

//void iStack::push(int value)
//{
//	if (full() ) 
//	{
//		// value stored in exception object 
//		throw pushOnFull(value);
//	}
//}
/**
 you may wonder why the step 2 is needed and why an expression object is created -  
 
 
   the expression 
      pushOnFull(value);

 create a temporary boject that is destroyed at the end of throw expression. The exception, however must last until a handler has been found, which may be many functions further up the chain 
 of the function calls. It is therefore necessary to copy the temporary object into a storage location, called the exception object, that is guaranteed to last until the exception hass ben handled
 
 however, this a classic way how how an exception is constructed, but in some cases it may be possible for the implementation to create the exception object directly, without creating the temporary object in step 1,
 however, this temporary elinimation is not required or always possible. 
*/

/**
 because of the discussion we had before, since the dereference will return the type of object what the pionter points to, so the return value is of type Excp... even though the pointer actually 
 point to a more derived class object , the actualy type is not examined to create the exception object
  
 the implied restriction on the kind of classes that can be used to create exception objects, the throw exception in the iStack member function push() is in error if 
 1. the class pushOnFull does not have a constructor that accepts an arguments of type int or if this constructor is not accessible
 2. the class pushOnFull has neither a copy constructor  or the constructor is not acceesible 
 3. the class pushOnFull is an abstract base class, because a program cannot create an object of an abstract class type . (as mentioned in section 17.1)
*/
void iStack::push(int value) 
{
	if (full()) { 
		pushOnFull except(value);

		Excp *pse = &except;
		throw *pse; // exception object has type Excp
	}
}

