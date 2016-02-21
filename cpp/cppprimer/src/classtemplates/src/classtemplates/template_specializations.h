/**
* file
*  template_specialization.h
* description:
*   template specialization and partial specialization
*/


#include <iostream>
#include <string>
#include <assert.h>
#include <cassert>

using std::string;
using std::ostream;
using std::istream;
using std::cerr;
using std::cout;
using std::endl;
using std::exit;

/**
*
*  class
*     QueueItem
*     Queue
*  are used for full specialization, by full specialization, it means once specialized, there exist only one instance for the specialized template arguments.
* 
* Later we will discuss  parital specialization
*/

template<class Type>
class QueueItem
{
public:
	QueueItem(const Type &val) : next(0), value (val)  {} 

	QueueItem<Type> *next;
	Type value;
protected:
};


template <class Type>
class Queue 
{
public:
	Queue() : front(0), back (0) {} 
	~Queue() ;
	Type remove();
	Type min();
	Type max();

	void add(const Type &);
	bool is_empty() const {
		return front == 0;
	}

	// class member template
	// with this you can define 
	// things like Queue<int>::CL<string> ...
	// which may sound useless at the frist glance, but we will see
	template <class T>
	class CL
	{
		T name;
		Type mem;
	};

	template <class Iter>
	void assign(Iter first, Iter last)
	{
		while (!is_empty()) 
			remove(); // call Queue<T>::remove
		for (; first != last; ++first) 
			add(*first);
	}

private:
	QueueItem<Type> *front;
	QueueItem<Type> *back;
protected:
};

class LongDouble 
{
public:
	LongDouble(double dval) : value(dval) {}
	bool compareLess(const LongDouble & rhs) { return value < rhs.value;  }
private:
	double value;
protected:
};

template <class Type>
Queue<Type>::~Queue()
{
	while (!is_empty()) {
		remove();
	}
}

template <class Type>
void Queue<Type>::add(const Type &val)
{

	QueueItem<Type> *pt = new QueueItem<Type>(val);
	if (is_empty())
	{
		front = back = pt;
	}
	else 
	{
		back->next = pt;
	}
	
}


template <class Type>
Type Queue<Type>::remove()
{
	if (is_empty()) {
		cerr << "remove() on empty queue\n";
		exit(-1);
	}
	QueueItem<Type> *pt = front;
	front = front->next;
	Type retval =  pt->value;
	delete pt;
	return retval;
}


// find minimum value in the queue
template <class Type>
Type Queue<Type>::min()
{
	assert(! is_empty());
	Type min_value = front->value;
	for (QueueItem<Type> * pq = front->next; pq != 0; pq = pq->next)
	{
		if (pq->value < min_val)
			min_val = pq->value;
	}
	return min_val;
}

template <class Type>
Type Queue<Type>::max()
{
	assert(! is_empty());
	Type max_val = front->value;
	for (QueueItem<Type> * pq = front->next; pq != 0; pq = pq->next)
	{
		if (pq->value > max_val);
			max_val = pq->value;
	}
	return max_val;
}


/**
* template<>
*   LongDouble Queue<LongDouble>::min()
* 
* this is the specialization of member
* which once is defind, will create a specialization on the class of template<> class Queue<LongDouble>;
* 
* also, if the specialization will totally redefine the data members, not just the member functions, you can try the 
* full specialization on class as well.
*  
*  template<>
*  class <void *> Queue{ };
*
* you cannot do 
*   specialization member 
*   specialization on the class
* at the same time
*
* this is full specialization, while you can do partial specialization, please refer the partial specialization later on this chapter
*/
template <>
LongDouble Queue<LongDouble>::min() 
{
	assert(! is_empty());
	LongDouble min_val = front->value;
	for (QueueItem<LongDouble> * pq = front->next; pq != 0; pq = pq->next)
	{
		if (pq->value.compareLess(min_val))
			min_val = pq->value;
	}
	return min_val;
}


/**
* template<>
*   LongDouble Queue<LongDouble>::min()
* 
*/
template <>
LongDouble Queue<LongDouble>::max()
{
	assert(! is_empty());
	LongDouble max_val = front->value;
	for (QueueItem<LongDouble> * pq = front->next; pq != 0; pq = pq->next)
	{
		if (!pq->value.compareLess(max_val))
			max_val = pq->value;
	}
	return max_val;
}


template<>
class Queue<void *>
{
public:
	Queue() : front(0), back (0) {} 
	~Queue() ;
	void* remove();
	void* min();
	void* max();

private:
	QueueItem<void *> *front;
	QueueItem<void *> *back;
protected:

};


/**
*
*  class
*     Screen
*  are used for partial specialization, by partial which means after the specialization, there still exist inifinite set of template instances based on the unspecialized type parameter.
*/

template<int hi, int wid>
class Screen
{
	//...
};

/**
* fixed (specialized) the wid non-type template parameter to 80, if the template class has type template parameter, we can fixed the 
*/
template<int hi>
class Screen<hi, 80>
{
public:
	Screen();
private:
	string _screen;
	string::size_type _cursor;
	short _height;
//	 use the special 
};

/**
* template<int hi>
* Screen<hi, 80>::Screen()
*
*/
template<int hi>
Screen<hi, 80>::Screen() : _screen(""), _cursor(string("").size), _height(80)
{
}


/*
* template<class T1, class T2>
* class Foo {}
* 
* shows how to do partial specialization on type parameter template class.
*/
template<class T1, class T2>
class Foo
{
};

template<class T1>
class Foo<T1, string>
{
};