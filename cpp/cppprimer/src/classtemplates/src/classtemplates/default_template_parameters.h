/**
* file: 
*  default_template_parameters.h
*
* description:
*  this file shows that you can provide default paramter value for either the type parameter or the nontype parameter
*/

#include<string>
using std::string;

template <class Type, int size = 1024>
class Buffer;


template <class Type = string, int size /* you don't need to provide "= 1024" */>
class Buffer;
//template <class Type = string, int size = 1024>
//class Buffer;

template <class Type, int size>
class Buffer
{
public:
	Buffer() : _size(size) {}
private:
	Type elem;
	int _size;
protected:
};