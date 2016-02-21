/**
* file;
*   virtuall_virtual_new.h
*  description:
*    this is more like the IClonable in c#, while the good things is that with the virtual function,   you can change the return type to match the real object being cloned. 
*  which is quite neat in some occasion.
*/


#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::string;
using std::ostream;

class Query
{
public:
	virtual Query* clone() = 0;
};

class NameQuery : public Query
{
public:
	NameQuery(string name) : _name(name) { }
	NameQuery(const NameQuery &rhs) : _name(rhs._name) {}
	//virtual Query* clone()
	//	// invokes the NameQuery constructor
	//{ return new NameQuery(*this); }

	// while the following is what you should do
	virtual NameQuery *clone()
	{
		return new NameQuery(*this); 
	}
private:
	string _name;
};


