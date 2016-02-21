/**
* file: 
*  friends_in_class_templates.h
*
* description:
*  the friends in the class templates.
*/

/** - A nontemplate friend class or friend function.
* A nontemplate friend class or friend function. In the following example, the function foo(), the member function bar()
* the member function bar() and the class foobar are friends to all instantiation of the class tepmlate QueueItem .
*  
*  this is a one-to-one relationship and the fiends are determined/fixed right in the declaration (there is only one declaration of the friends)
*/
//class Foo {
//	void bar();
//};
//
//class foobar {}
//
//template <class T>
//class QueueItem {
//	friend class foobar;
//	friend void foo();
//	friend void Foo::bar();
//};

/** - A bound friend class template or function template 
*   this is a one-to-one relationship and the friends are not determined (the friends is created when the class is instantiated).-
*/
//template <class Type>
//class foobar { 
////
//};
//
//template <class Type>
//void foo(QueueItem<Type>);
//
//template <class Type>
//class Queue {
//	void bar();
//};
//
//template <class Type>
//class QueueItem {
//	friend class foobar<Type>;
//	friend class foo<Type>(QueueItem<Type>);
//	friend class Queue<Type>::bar();
//};

/** - An unbound friend class template or function template 
*  unbound friend classes are multiple-to-one relationship
*   
*/
//template <class Type>
//template QueueItem
//{
//	friend class foobar;
//	template <class T>
//	friend void foo(QueueItem<T>);
//	template <class T>
//	friend void Queue<T>::bar();
//};



