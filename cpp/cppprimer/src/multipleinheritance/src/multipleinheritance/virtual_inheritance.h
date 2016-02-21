/**
* File
*  virtual_inheritance.h
* Description:
*  this is to test the use and characteristics of virtual inheritance
*/

/**
* C++ is a language which supports multiple inheritance. We have learned that 
* when a class subclass another class, the super class become a subobject of the derived class, suppose 
* if through multiple inheritance tree, a class appears twice on both side, then it has some problem
* this has two implications
*   1. it waste spaces
*   2. a more serious problem is ambiguity, which member method/data object to call?
* 
* virtual inhertiance is just to address the issue we have identified earlier. 
* under virtual inheritance:
*  there is only a single, shared base class subobject is inherited regardless of how many times the base class occurs within hte derivation hierarchy
*/

#include <iostream>
#include <string>
#include <vector>
#include <list>


using std::ostream;
using std::iostream;
using std::vector;
using std::list;
using std::endl;
using std::cout;
using std::cerr;
using std::string;


/** 
* hierarchy_example 1
*
*                ZooAnimal                                 Endangered
*             /            \                                /
*          -V-              -V-                            /
*         /                   \                           /
*      Bear                   Racoon                    /
*            \                   \                     /
*             ------------\       \                   /
*                          \       \       --------- /
*                           \       \     /    
*                           ------  Panda
*/

//class ZooAnimal {} ;
//class Bear: public virtual ZooAnimal { };
//
//class Raccoon : virtual public ZooAnimal { };

//class ZooAnimal {
//
//public:
//	ZooAnimal(string name, bool onExhibit, string fam_name) : _name(name), _onExhibit(onExhibit), _fam_name(fam_name) {}
//
//
//	virtual ~ZooAnimal();
//	virtual ostream& print (ostream &) const; 
//	string name() const { return _name; } 
//	string family_name() const { return _fam_name; } 
//private:
//protected:
//	bool _onExhibit;
//	string _name;
//	string _fam_name;
//
//} ;

/*
* ZooAnimal to support a void paramter constructor
*/
class ZooAnimal {

public:
	ZooAnimal(string name, bool onExhibit, string fam_name) : _name(name), _onExhibit(onExhibit), _fam_name(fam_name) {}

	virtual ~ZooAnimal();
	virtual ostream& print (ostream &) const; 
	string name() const { return _name; } 
	string family_name() const { return _fam_name; } 
private:
protected:
	ZooAnimal() : _name(NULL), _onExhibit(false), _fam_name(NULL) {}
	bool _onExhibit;
	string _name;
	string _fam_name;
} ;

class Bear: public virtual ZooAnimal { 
public:
	enum DanceType { two_left_feet, macarena, fandango, waltz } ;
	Bear(string name, bool onExhibit= true) : ZooAnimal(name, onExhibit, "Bear") , _dance(two_left_feet)
	{}
	virtual ostream & print(ostream& ) const; 
	void dance(DanceType );
private:
protected:
	DanceType _dance;
};

//class Bear: public virtual ZooAnimal { 
//public:
//	enum DanceType { two_left_feet, macarena, fandango, waltz } ;
//	/// When the most derived class
//	Bear(string name, bool onExhibit= true) : ZooAnimal(name, onExhibit, "Bear") , _dance(two_left_feet)
//	{}
//	virtual ostream & print(ostream& ) const; 
//	void dance(DanceType );
//private:
//protected:
//	// when an intermediate derived class
//	Bear() : _dance( two_left_feet) {}
//	DanceType _dance;
//};

class Raccoon : virtual public ZooAnimal { 
public:
	Raccoon(string name, bool onExhibit = true) : ZooAnimal(name, onExhibit, "Raccoon"), _pettable(false) {}
	virtual ostream& print(ostream& ) const;
	bool pettable() const { return _pettable; }
	void pettable(bool petval) { _pettable = petval; } 
private:
protected:
	bool _pettable;
};

class Endangered
{
public:
	enum CriticalLevel { critical, high, low, trivial };
	enum EndangeredCause { environment, population } ;


	Endangered(EndangeredCause cause, CriticalLevel level) : _cause(cause), _level(level) { }
private:
protected:
	CriticalLevel _level;
	EndangeredCause _cause;
};


class Panda : public Bear, public Raccoon, public Endangered 
{
public: 
	Panda(string name, bool onExhibit = true) ;
	virtual ostream& print(ostream &) const; 

	bool sleeping () const { return _sleeping; } 

private:
protected:
	bool _sleeping;
};

/**
* when a Panda object is initialized , (1) the explicit nvocation of the ZooAnimal constructor within Raccoon and Bear are no loger executed
*  during the execution and (2) the ZooAnimal constructor is invoked with the arguments specified for the ZooAnimal constructors in the initialization
* list of the Panda constructor,
*
* within Panda, both the Bear and Raccoon classes serve as intermediates rather as the most derived class, As an intermediate derived class, direct invocation of all virtual 
* base class constructor are suppresessed automatically. Were panda subsequently derived from, then Panda itself would become  an inermediate class of the derived class object, 
* and its invocation of the ZooAnimal constructor would be suppressed automatically.  
*/
Panda::Panda(string name, bool onExhibit) : ZooAnimal (name, onExhibit, "Panda"),
											Bear(name, onExhibit),
											Raccoon(name, onExhibit), 
											Endangered(Endangered::environment, 
											Endangered::critical),
											_sleeping(false)
{
}

/**
* the code below provides code singleton that simply makes the code compiles
*/
#include <exception>
using std::exception;

template <class Type>
ostream& ZooAnimal::print(ostream& os) const { 
	throw new exception();
}

template <class Type>
ostream& Bear::print(ostream& os) const {
	throw new exception();
}

template <class Type>
ostream& Panda::print(ostream& os) const { 
	throw new exception();
}

template <class Type>
ostream& Raccoon::print(ostream& os) const { 
	throw new exception();
}

/**
* you may have noticed that the two arguments being passed to both the Bear and Raccoon constructors are unnecessary when the classes serve as intermediate derived classes. 
* another solution is as follow
*/
//class Bear: public virtual ZooAnimal { 
//public:
//	enum DanceType { two_left_feet, macarena, fandango, waltz } ;
//	/// When the most derived class
//	Bear(string name, bool onExhibit= true) : ZooAnimal(name, onExhibit, "Bear") , _dance(two_left_feet)
//	{}
//	virtual ostream & print(ostream& ) const; 
//	void dance(DanceType );
//private:
//protected:
//	/** 
//	* NOTE:
//	*   however, as according to my test, it is recognized by the C++ compiler (I am using Visual C++)
//	*/
//	// when an intermediate derived class
//	Bear() : _dance( two_left_feet) {}
//	DanceType _dance;
//};

/*
* when design of the bear has changed to something above, you can redefine your 
*
*/
//Panda::Panda(string name, bool onExhibit) : ZooAnimal (name, onExhibit, "Panda"),
//											Raccoon(name, onExhibit),
//											Endangered(Endangered::environment, 
//											Endangered::critical),
//											_sleeping(false)
//{
//}


/** 
* hierarchy_example 2
*
*    Character      ZooAnimal      ToyAnimal
*       ^               ^             ^
*       |               v            v
*       |               |           /
*    RockCharacter   Bear          /
*          ^            ^         /
*          |            |        /
*          \           /   --- -
*            \       /   /      
*             TdeddyBear
*
*/

/*
*  there is a  basic rule in terms the order of the Constructor and Destructor Order
*   Virtual base classes are always constructed prior to to nonvirutal base classes regardless where they appear in the inheritance hierarchy. 
*  Let's see the example above, we are going to illustrate the discussion we have seen before.
* 
*/
class Character {} ;
class BookCharacter : public Character { };
class ToyAnimal { } ;
class TeddyBear : public BookCharacter, public Bear, public virtual ToyAnimal 
{

};

/**
* The immediate base classes are examined in the order of their declaration for the presence of virutal base calsses. In our example, the inheritance 
* subtree of BookCharacter is examined first, then that of Bear,  and finally that of ToyAnimal, Each subtreee is examined in depth first, tat is the sarch begins 
* first with the root classes and moves down. For the BookCharacter subtree, first Charcter, then BookCharacter are examined . For the Bear Subtree, first ZooAnimal, then Bear are examined. 
* The order of virtual base class constructor are nvoked. the nonvirtual base classes constructors are invoked in the order of declaration.: BookCharacter then Bear. Prior to execution of the BookCharacter
* , its base Character constructor is invoked. 
* 
* Given the declaration 
*   TeddyBear Paggington;
*  ZooAnimal();
* ToyAnimal();
*  Character()
* BookCharacter()
* Bear();
* TeddyBear()
*/


/**
* virtual inheritance example
*  in this example, we are going to discuss the topic of multiple inheritance in an example 
*  
* 
*/
template <class Type>
class Array;

template <class Type>
ostream& operator << (ostream&, const Array<Type>&);

template <class Type>
class Array
{
	static const int ArraySize = 12;
public:
	explicit Array(int sz = ArraySize) { init (0, sz); }
	Array(const Type *ar, int sz) { init(ar, sz); } 
	Array(const Array &ia) { init(ia.ia, ia.size()); } 

	virtual ~Array() { delete[] ia; } 
	Array& operator= (const Array&);
	int size() { return _size; } 
	virtual void grow(); 

	virtual void print (ostream& = cout); 
	
	// program technique, in order to allow for better performance, 
	// since we are going to allow user to polymorphically 
	//retrieve the element at a specified index,
	// in order not to sacrifise the performance, we are making some helper class which is called 
	// at() which can be inlined. 
	Type at(int ix) const { return ia[ix]; } 
	virtual Type& operator[] (int ix) { return ia[ix]; }

	virtual void sort(int, int);
	virtual int find(Type );
	virtual Type min();
	virtual Type max();
protected:

	void swap(int , int);
	void init(const Type* , int);

	int _size;
	Type * ia;
private:

};


template <class Type>
class Array_RC : public virtual Array<Type> 
{
public: 
	// it is wrong to write as 
	//   Array_RC(int sz = ArraySize) : Array (sz)  {} any reference to the base template base class type specifier must be fully
	//     qualitified with its formal paramters list. 
	Array_RC(int sz = ArraySize) : Array<Type> (sz) {}
	Array_RC(const Array_RC& r) ;
	Array_RC(const Type * ar, int sz);
	Type& operator[] (int ix);

protected:
private:
};

#include <assert.h>

template <class Type>
Array_RC<Type>::Array_RC(const Array_RC<Type> &r) : Array<Type>(r) {}

template<class Type>
Array_RC<Type>::Array_RC(const Type * ar, int sz) : Array<Type>(ar, sz) {}

template <class Type>
Type& Array_RC<Type>::operator[] (int ix)
{
	assert(ix >= 0 && ix < Array<Type>::_size);
	return ia[ix];
}


template <class Type>
class Array_Sort : public virtual Array<Type> {
public:
	Array_Sort(const Array_Sort<Type> &);
	Array_Sort(const int sz = Array<Type>::ArraySize) : Array<Type>(sz) { clear_bit(); } 
	Array_Sort(const Type* arr, int sz) :Array<Type>(arr, sz) { sort(0, Aray<Type>::_size - 1); clear_bit(); } 

	Type operator[] (int ix) { 
		set_bit(); return ia[ix];
	}

	void print(ostream& os = cout ) { 
		check_bit(); Array<Type>::print(os); 
	}

	Type min() { check_bit(); return ia[0]; } 
	Type max() { check_bit(); return ia[Array<Type>::_size - 1]; } 
	
	bool is_dirty() const { return dirty_bit; }
	int find(Type); 
	void grow();
protected:
	void set_bit() { dirty_bit = true; } 
	void clear_bit() { dirty_bit = true; }
	void check_bit() { 
		if (dirty_bit) { 
			sort(0, Array<Type>::_size);
			clear_bit();
		}
	}
private:
};


template <class Type>
Array_Sort<Type>::Array_Sort(const Array_Sort<Type> &as) 
{
	// note: as.check_bit() does not work 
	// -- see explanation below
	if (as.is_dirty()) {
		sort(0, Array<Type>::_size - 1 ); 
	}
	clear_bit();
}

/** this is a very typical implemenation of the divide 2 search 
*/
template <class Type>
int Array_Sort<Type>::find(Type value) 
{
	int low = 0;
	int high = Array<Type>::_size - 1;
	check_bit();

	while (low <= high) {
		int mid = (low + high ) / 2;
		if (val == ia[mid]) return mid;
		if (val < ia[mid]) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}

/** 
* now we are going to make a class that shall inherits both the 
* Array_Sort and the Array_RC
* and the new class would be named as 
*   Array_RC_S
*
*/

template <class Type> 
class Array_RC_S : public Array_RC<Type>, public Array_Sort<Type>
{
public:
	Array_RC_S(int sz = Array<Type>::ArraySize) : Array<Type>(sz) {
		Sort(0, Array<Type>::_size - 1);
		clear_bit();
	}
	Array_RC_S(const Array_RC_S<Type> & rca)  : Array<Type>(rca)
	{
		sort(0, Array<Type>::_size -1 ); clear_bit(); 
	}

	Array_RC_S(const Type* arr, int sz) 
		: Array<Type> (rca)
	{
		sort(0, Array<Type>::_size - 1); 
		clear_bit();
	}

	Type& operator[] (int index) { 
		set_bit(); 
		return Array_RC<Type>::operator[] (index); 
	}

};

