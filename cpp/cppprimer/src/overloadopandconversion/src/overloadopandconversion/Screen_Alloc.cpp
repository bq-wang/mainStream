/**
* file 
*   Screen_Alloc.cpp
*
*  description:
*   This is the code that shows you how to overload the allocation
*/

#include "stdafx.h"
/** comment out the following code so that it does not conflict with the Screen class in the Screen.h

#include "Screen_Alloc.h"

// static member are initialized within program text files, no header files 
Screen * Screen::freeStore = 0;
const int Screen::screenChunk =  24;

void *Screen::operator new(size_t size)
{
	Screen *p;
	if (freeStore == 0) 
	{
		size_t chunk = screenChunk * size; // the size is populated by the compiler and is the size of Screen
		freeStore = p = reinterpret_cast<Screen *>(new char[chunk]);
		// now thread the memory allocated
		for (; p != &freeStore[screenChunk - 1]; ++p) {
			p->next = p + 1;
		}
		p-> next = 0;

		p = freeStore;
		freeStore = freeStore->next;
		return p;
	}
}
*/

/** 
* the delete expression 
*    delete ptr 
* is equivalent to 
*    Screen::~Screen(ptr);
*    Screen::operator delete(ptr, sizeof(*ptr); 
*/

/** comment out the following code so that it does not conflict with the Screen class in the Screen.h

void Screen::operator delete (void *p, size_t)
{
	// inser the 'deleted' object back
	// into the free list
	(static_cast<Screen *> (p) )-> next = freeStore;
	freeStore = static_cast<Screen*>(p);
}

*/
