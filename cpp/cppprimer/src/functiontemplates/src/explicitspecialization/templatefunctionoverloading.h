/**
* this code will demonstrate that you can do template overloading 
*/

#include <iostream>

template <typename Type>
class Array { 
	/*    ... */ 
public:
	Array(int initialvalue) {}
	Type operator [](int index) {typename Type value; return value; }
} ;

// there are three templates function definition of min()
template <typename Type>
Type min(const Array<Type>&, int); // #1


template <typename Type>
Type min(const Type*, int); // #2


template <typename Type>
Type min(Type, Type); // #3


/**
* the code below may not be relevant to workable min method, it is just written down here to help understanding of metod 
*/
template <typename T>
T min5(T, T) ; // # added here to show the following code snippet may fail

// test the method of min(T, T)
//int TestTemplateAfterMin_T_T()
//{
//	int i; 
//	unsigned int ui;
//
//	// type dedcued to int
//	min5(1024, i);
//	// template argument deduction fails:
//	// two different types deduced for T
//	min5(i, ui);
//}


/**
* You may introduce the declaration of min5(T, U), but it may cause ambiguity for other types
*/
template <typename T, typename U>
T min5(T, U) ; // # added here to but call to min5(1024, i) may fail


template <typename T>
T min5(T  t1, T t2) 
{
	using std::cout;
	using std::endl;
	cout << "min5(T  t1, T t2) " << endl;
	typename T value;
	return value;
}

template <typename T, typename U>
T min5(T t, U u)
{
	using std::cout;
	using std::endl;
	cout << "inside min5(T t, U u)" << endl;
	typename T value;
	return value;
}

int TestTemplateAfterMin_T_U()
{
    int i; 
	unsigned int ui;

	// some compiler may flag it as error
	// but vc++ 11 does not complain it as error 
	// I think it is because min5(T, T) is more specialized than min5(T, U)
	// and when two template function is candidates, the more generalized one will win
	min5(1024, i); // -> min(T, T); 
	// template argument deduction fails:
	// two different types deduced for T
	min5(i, ui); // -> min(T, U)
	return 0;
}

/**
* @NOTE:
*  the rule of the most specialized - in situation of more than one candidates are availabe, the template with the most specialized
*  will be choosen
*/
template <typename Type>
Type sum(Type*, int);

template <typename Type>
Type sum(Type, int);

template <typename Type>
Type sum(Type*, int)
{
	using std::cout;
	using std::endl;
	cout << " sum(Type*, int)" << endl;
	Type t;
	return t;
}

template <typename Type>
Type sum(Type, int)
{
	using std::cout;
	using std::endl;
	cout << " sum(Type, int)" << endl;
	Type t;
	return t;
}

int TestTheMostSpecialized()
{


    int ia[1024];
	// Type == int: sum<int>(int *, int); or 
	// Type == int*: sum<int *>(int *, int); or ???
	int ival1 = sum(ia, 1024);
	return 0;
}



/** 
* below is the function template defintion
*/ 

template <typename Type>
Type min(const Array<Type>& arr, int size) //#1
{
	typename Type value;
	return value;
}


template <typename Type>
Type min(const Type* arr, int size) // #2
{
	if (arr != NULL) {
		return arr[0];
	}
	return NULL;
}


template <typename Type>
Type min(Type t1, Type t2)  // #3
{
    return t1 < t2 ? t1 : t2;
}