#include <cstring>


/**
* @NOTE:
*   some gotchas for the template4 function specialization
*   1. if you provide a function template specialiation, it should be visible in every file that uses it . 
*      otherwise, there would be compilation error (you can not hvae some instantiation for the same template argument from the generic template function, and some instantiation from the specializatoin)
*      normally, you should put the specialization in the header file with the generic template.
*   2. Second, the function template specialiation should be in the same namespace as the template that it specialize
* e.g.
// primer.h
namespace cplusplus_primer {
  template <class type>
    type min(Type* array, int size) { /* ... * / }

}

// user.h
class SmallInt { /*   * / } 

// user.C
template< > SmallInt min(SmallInt * array, int size); // this is an error, because it is a differente namespace from the generic template.

*/

// below is the generic specialiation definition
template <class T>
T max(T t1, T t2) 
{
	return (t1 > t2 ? t1: t2);
}

// the below is the template specialization on the type argument of const char * (typedefed as PCC)
typedef const char * PCC;

using std::strcmp;


template<>
PCC max<PCC>(PCC t1, PCC t2)
{
	return (strcmp(t1, t2) > 0 ? t1 : t2);
}

// it is possible to omit the template argument if the type of 
// template argument can be deduced from the the function parameters
//template<>
//PCC max(PCC t1, PCC t2) 
//{
//	return (strcmp(t1, t2) >0 ? t1 : t2);
//}
