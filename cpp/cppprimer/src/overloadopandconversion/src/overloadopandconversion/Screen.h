/**
* file 
*   Screen.h
*
*  description:
*   this is the header file definition of the screen and the ScreenPtr
*/

class Screen
{
public:
	void move(int x, int y);

	/** 
	* the placement new and delete operator
	*
	*/
	void *operator new(size_t );
	void *operator new(size_t, Screen*  );


	/** the placement delete operator 
	*
	*
	*/
	void operator delete(void *);
	void operator delete(void *, size_t size); // you can write as void operator delete (void *, size_t size); or you can write as void operator delte (void *); -- 
	void operator delete (void * , Screen *);

	/** the placement delete[] operator
	*   you can also overload hte array placement operator and the array placement delete operator 
	*/
	void *operator new[](size_t);
	void *operator new[](size_t, Screen *);

/** the following code is not implemented.
	void operator delete[](void *);
	void operator delete[](void *, Screen *);
*/

	Screen() { };
	Screen(Screen *) { throw "Screen(Screen *); ";}
private:
protected:
};

class ScreenPtr
{
public:
	ScreenPtr(Screen *ptr_) : ptr(ptr_) { }
	Screen& operator*() { return *ptr; } 
	Screen* operator->() { return ptr; }
	~ScreenPtr() { delete ptr; } // we shall we define the operator as well
private:

	Screen *ptr;
protected:
};
