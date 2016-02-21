/**
* file:
*   inheritance_access_level.h
*description:
*    this shows the three types of inheritance
*      public inheritance - type inheritance
*      private inhertiance - implemenation inhertiance
*      protected inheritance - protected inheritance
*/

/**
*  A public derivation is refered to as type inhertitance, the dervied class is a subtype of the bse classes; it overrides the implementation of all type-specific member funcitons. 
* of the base class while inheriting those that are shared. 
*
*  The derived class in general reflects is-a relationship
*
*/

/**
*  A private derivation is refered to as implementation inheritance, the derived class does not support the public interface of hte base directly. rather, it wishes to reuses the implementation 
* of the base class while providing its own interface. To illustrate the issues involved, let's implements a PeekbackStack. 
*
*/

class IntArray
{
public:
	IntArray(int size) : _size(size) {
		init(size, 0);
	}
	IntArray(const IntArray & rhs) { 
		init(rhs.size(), rhs.ia);
	}
	int size() const { return _size; }
	int& operator[](int index) { return ia[index]; }

	virtual ~IntArray() { 
		delete[] ia;
	}
private:
	void init(int sz, int * array_) { 
		_size = sz;
		ia = new int[_size];
		for (int i = 0; i < _size; ++i) {
			if (! array_)
				ia[i] = 0;
			else ia[i] = array_[i];
		}
	}
protected:
	int _size;
	int *ia;
};

//class PeekbackStack : public IntArray
//{
//private:
//	const int static bos = -1;
//public:
//	explicit PeekbackStack(int size) : IntArray(size), _top(bos) { }
//
//	bool empty() const { return _top == bos;  } 
//	bool full() const { return _top == size() - 1; }
//	bool top() const { return _top; } 
//
//	int pop() { 
//		if (empty()) {
//			/* handle error condiiton */
//			return ia[_top --];
//		}
//	}
//	void push(int value ) {
//		if (full() ) {
//			/* handle error condition */
//			ia[++_top] = value; 
//		}
//	}
//	bool peekback(int index, int & value) const;
//
//private:
//	int _top;
//};
//
//inline bool
//	PeekbackStack::peekback(int index, int & value) const { 
//		if (empty() ) {
//			/* handle error condition */
//		}
//		if (index < 0 || index > _top) 
//		{
//			value = ia[_top];
//			return false; 
//		}
//		value = ia[index];
//		return true;
//}

/*
* PeekbackStack now use IntArray as a private base class
*/

//class PeekbackStack : private IntArray
//{
//private:
//	const int static bos = -1;
//public:
//	explicit PeekbackStack(int size) : IntArray(size), _top(bos) { }
//
//	bool empty() const { return _top == bos;  } 
//	bool full() const { return _top == size() - 1; }
//	bool top() const { return _top; } 
//
//	int pop() { 
//		if (empty()) {
//			/* handle error condiiton */
//			return ia[_top --];
//		}
//	}
//	void push(int value ) {
//		if (full() ) {
//			/* handle error condition */
//			ia[++_top] = value; 
//		}
//	}
//	bool peekback(int index, int & value) const;
//
//private:
//	int _top;
//};
//
//inline bool
//	PeekbackStack::peekback(int index, int & value) const { 
//		if (empty() ) {
//			/* handle error condition */
//		}
//		if (index < 0 || index > _top) 
//		{
//			value = ia[_top];
//			return false; 
//		}
//		value = ia[index];
//		return true;
//}


/**
* PeekbackStack with the composition pattern
*/
//class PeekbackStack 
//{
//private: 
//	const int static bos = -1;
//public:
//	explicit PeekbackStack (int size):	stack (size), _top(bos) {}
//
//	bool empty() const { return _top == bos; }
//	bool full() const { return _top == stack.size() - 1; }
//	int top() const { return _top; } 
//
//	int pop() {
//		if (empty() ) {
//			 // handling error 
//		}
//		return stack[_top -- ];
//	}
//
//	void push(int value) 
//	{
//		if ( full() ) {
//			// handle error condition
//		}
//		stack[++_top] = value; 
//	}
//
//	bool peekback(int index, int & value) const; 
//
//private: 
//	int _top;
//	IntArray stack;
//};

/** 
*  PeekbackStack with exempt invididual members
*/
class PeekbackStack : private IntArray
{
private:
	const int static bos = -1;
public:
	explicit PeekbackStack(int size) : IntArray(size), _top(bos) { }

	bool empty() const { return _top == bos;  } 
	bool full() const { return _top == size() - 1; }
	bool top() const { return _top; } 

	int pop() { 
		if (empty()) {
			/* handle error condiiton */
			return ia[_top --];
		}
	}
	void push(int value ) {
		if (full() ) {
			/* handle error condition */
			ia[++_top] = value; 
		}
	}
	bool peekback(int index, int & value) const;
	// you can allow the client to access the IntArray size method by exempting the size method in the public section 
	using IntArray::size;

	// you can allow further subsequent derivation access to the protected members. you can exempt individual members in the protected section
protected: 
	using IntArray::_size;
	using IntArray::ia;

private:
	int _top;
};

inline bool
	PeekbackStack::peekback(int index, int & value) const { 
		if (empty() ) {
			/* handle error condition */
		}
		if (index < 0 || index > _top) 
		{
			value = ia[_top];
			return false; 
		}
		value = ia[index];
		return true;
}

/**
* A third form of derivation is the protected inheritance , Under protected inheritance, all the public members they can be access from class subsequently derived from the class. But not from outside 
* the class hierarchy
*
* We have protected derivation is because private inheritance is too restrictive,because making the IntArray within Stack private public its a subsequent derivation from accessing from accessing the members.  
*
*/