/**
* file 
*   Screen_Alloc.h
*
*  description:
*   This is the code that shows you how to overload the allocation
*/

/** Comment the following defintion so it does not conflict the defintion of the Screen.h

class Screen
{
public:
	void * operator new(size_t );
	void operator delete(void *, size_t);

	void * operator new[](size_t);
	void operator delete[](void *, size_t);
private:
	Screen * next;
	static Screen *freeStore;
	static const int screenChunk;
protected:
};


class ScreenPtr
{
public:
	ScreenPtr(Screen &s, int arraySize = 0) : ptr(&s), size(arraySize), offset(0) {}
private:
	int size;
	int offset;
	Screen *ptr;
protected:
};


*/

