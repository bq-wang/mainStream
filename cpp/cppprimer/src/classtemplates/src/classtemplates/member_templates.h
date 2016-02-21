/**
* file
*  member_templates.h
* description:
*   this is a file that demonstrate the use of the member template inside template classes
*/

#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;
using std::cerr;
using std::cout;
using std::endl;
using std::exit;


template<class Type>
class QueueItem
{
public:
	QueueItem(const Type &val) : next(0), value (val)  {} 
	//~QueueItem() ;
//	Type value() { return this->value; }
//	QueueItem<Type> next() { return this->next; }
//private:
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


// if it does not have a good destructor, then do not provide one.
//template <class Type>
//QueueItem<Type>::~QueueItem()
//{
//	
//}


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