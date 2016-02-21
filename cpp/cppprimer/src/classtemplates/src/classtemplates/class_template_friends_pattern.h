/**
* file:
*  class_template_friends_pattern.h
*
*/
#include <iostream>
#include <string>
using std::istream;
using std::ostream;

template <class Type>
class QueueItem;

template <class Type>
void foo(QueueItem<Type>);

template <class Type>
class Queue 
{
public:
	friend void foo(Queue<Type>); // - this mean foo is a non-template function, it is just a normal function which accepts the parameter of type Queue<Type>
	// or you can write as follow
	friend void foo<Type>(Queue<Type>); // - this means that foo is a template function

	// whether we should write as 
	template<class Type>       // since we cannot do as friend ostream& operator << (ostream&, const Queue<Type> &);, we have to provide the templtae<class Type> is there better ways?
	friend ostream& operator <<(ostream& , const Queue<Type> &);
	// or as 
	//friend operator <<(ostream&, const Queue<Type> &);
	// while you cannoot provide type parameter as the non-operator normal function template 
	//friend ostream& operator << <Type>(ostream&, const Queue<Type> &);
	// this is a partial function instantiation
	//template <> friend ostream& operator << (ostream& , const Queue<Type> &);
protected:
	virtual ostream& print(ostream&) const;
private:
	QueueItem<Type> *front;
	QueueItem<Type> *back;
};

template <class Type>
class QueueItem
{
public:
	// all queue instantiation are friends
	// to each QueueItem instantiation
	//template <class T> friend class Queue; // it is not "friend template <class T> class Queue;
	friend class Queue<Type>;
	//
	//friend ostream& operator << <Type>(ostream &, const Queue<Type> &);
	// or you can write as follow
	template<class Type>
	friend ostream& operator << (ostream &, const QueueItem<Type> &);
	template<class Type>
	friend ostream& operator << (ostream &, const Queue<Type> &);
	//template <class T> friend ostream& operator << (ostream& , const QueueItem<T> &);
	operator Type () { return value; } // - the data accessor 
protected:
	virtual ostream& print(ostream &) const;
private:
	QueueItem<Type> *next;
	Type            value;
};

// and if you want to define the helper ostream oeprator, how would you do that 
// you can make the function a template function
//
template <class Type>
ostream& operator <<(ostream &, const Queue<Type> &);

// and how is it implemented
template <class Type>
ostream& operator <<(ostream &os, const Queue<Type> & q)
{
	os << "< ";
	QueueItem<Type>* p;
	for (p = q.front; p; p = p->next) { 
		os << *p << " ";
	}
	os << "> ";
	return os;
}

template <class Type>
ostream& operator <<(ostream& os, const QueueItem<Type> & q)
{
	os << q.value;
	return os;
}


// however, what if the QueueItem and Queue template class may have derived type and you want 
// the real class to handle the display their self. 
// you can use the virtual function


template <class Type>
ostream& operator <<(ostream &os, const Queue<Type> & q)
{
	q.print(os);
	return os;
}

template <class Type>
ostream& operator <<(ostream& os, const QueueItem<Type> & q)
{
	q.print(os);
	return os;
}

template <class Type>
ostream& Queue<Type>::print(ostream &os) const
{
	os << "< ";
	QueueItem<Type>* p;
	for (p = this->front; p; p = p->next) { 
		p->print(os);
	}
	os << "> ";
	return os;
}


template <class Type>
ostream& QueueItem<Type>::print(ostream &os) const
{
	//os << *this; // we use the conversion operator , but possibly the recusion?
	os << this->value;
	return os;
}