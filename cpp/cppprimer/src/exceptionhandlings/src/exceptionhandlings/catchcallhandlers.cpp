#include "stdafx.h"
/**
* file :
*  catchcallhandlers.cpp
* this is a code that shows how you do the catch all exception handler in C++
* it may sound platitude, but C++ lacks of the type system which dictate that all the excpetion should derive from the Exception base class
* so to catch all exception , no matter which type it is (may it be an primitive type, a string, or an exception derived class or even a  custom class)
* you can catch and handle it 
* also, there is no such finally keyword that can do some resource release work, so it is adviced that you can use the catch all and do the proper deallocation there.
*/


class resource
{
public:
	void lock() ;
	void releaes();
};


void resource::lock() { }
void resource::releaes() { }


void catchCallHandler() 
{
	  resource res;
	  res.lock();
	  try 
	  {

	  // use res
	  // some action that causes an exception to be thrown
	  res.releaes();
	  }
	  catch (...)  // ... the tree dots are refered as the ellipsis, which is quite often used in many a place. 
	  {
		  res.releaes();
		  throw; // and you can rethrow the exception after you do the proper deallocation of the resources
		         // or you can opt not rethrow, but you can just return if the handler have handled the exception safely
	  }

	  res.releaes();
}

/**
* though we discussed the catch (...) expression , it is not the only way of recover from the exception site, a better way 
* and a more native way is to use the C++'s resource initialization is the resource aquisition paradigm/paragon. 
* whereas the destructor which exit the function will take responsibility of cleaning up the resource.
*/

