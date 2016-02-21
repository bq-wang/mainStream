/** 
* file 
*   virtual_destructor.h
* Description:
*   this file demonstrate how to use virtual destructor
*/
#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::ostream;
using std::istream;
using std::string;
using std::vector;
using std::list;


class Query
{
protected:
	virtual  ~Query();
};

class NotQuery : public Query
{
public :
	virtual ~NotQuery();
};

class Query1
{
public:
	virtual ~Query1();
};

class NotQuery1 : public Query1
{
public:
	virtual ~NotQuery1();
};


