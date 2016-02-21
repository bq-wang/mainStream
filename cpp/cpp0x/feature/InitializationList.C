#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <locale>
#include <array>   // <array> for std::array
#include <initializer_list>

/////////////////////////////////////////////////////////////////////////////////////////////////////
// in c++0x/c++11, it is basically saying that the initialization list will be uniformed, and the  //
// extent of application has been extended, that you can expect that you might use anywhere.	   //
// in this example, I will try to introduce some of the syntax very briefully			   //
/////////////////////////////////////////////////////////////////////////////////////////////////////


int main(
  int argc, 
  char * argv[]
)
{
  
  return 0;
}

// this is actually the same structure (memberwise) as the Cpp98Struct
// for better illustration purpose, a different name is given
struct Cpp0xStruct
{
  int x, y;
};


static int static_a[]  {1, 2, 3, 4, 5};

class Cpp0xAllowedWidget
{
public:
  Cpp0xAllowedWidget(): data {1, 2, static_a[3], 4, 5 } {}
  // it can also be written as such 
  //  which is also legal
  // Cpp0xAllowedWidget() : data ({1, 2, static_a[3], 4, 5 } {} 
private:
  const int data[5];
};

struct Cpp0xAllowedPoint
{

  // and the 
  //  uniformed Initialization Syntax can be literally be used anywhere.
  // such as below, you don't need to specifically write the type name Cpp0xAllowedPoint
public:
  Cpp0xAllowedPoint MakePoint() { return {0, 0}; }

  int x, y;
};

void f(const std::vector<int> & v);


void f(const std::vector<int> & v)
{
  int k = 0;
  for (const auto & i : v) {
    std::cout << ++k 
	      << i
	      << ",";
  }
  std::cout << std::endl;

}

int WhatAllowedInCpp0x()
{
  // non-aggregate
  const int val1 {5};
  const int val2 {5};

  // aggregate
  int a[] { 1, 2, val1, val1 + val2};

  // UDT (user defined type)
  const Cpp0xStruct p1 { 10, 20 };

  // Collections (vector, map, set)
  const std::vector<int> cv { a[0], 20, val2 };

  // and even with the new operator
  const float * pData = new const float[4] {1.5, val1 - val2, 3.5, 4.5 };

  // to follow up the func.declaration / func argument, here is how you can do about it
  f({val1, val2, 10, 20, 30} );
}

/**
 * The uniformed initializtion syntax
 *   semantics differs for aggregates and non-aggregates
 * - aggregates: (e.g. arrays and structs):
 *    -- initialize members/elements beginning to end
 * - non-aggregate
 *    -- invoke a constructor
 * there are some edge cases that need to be understood, but that is not very important
 * in common day-to-day use.
 */


struct Cpp0xNonAggregatePoint
{
public:
  Cpp0xNonAggregatePoint(int x, int y);

  int x, y;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// It is allowed to have the '=' sign, when it dose, it transit from the uniform initialization list   //
// to the Brace-Initializating?? 								       //
// I actually will refrain the use of the Brace-Initializing because such a term does not exit at all? //
/////////////////////////////////////////////////////////////////////////////////////////////////////////


int WhatAllowedInCpp0xCont() 
{
  // it is allowed to have less than required # of values in the initializer
  const Cpp0xAllowedPoint  p1 = {10};

  // but not more
  // const Cpp0xallowedpoint p2 = {10, 20, 30};

  // std::array is also an aggregate
  std::array<long, 3> m_array = {1, 2, 3};


  // like the uniformed initializer, if a UDT has constructors (which renderes the UDT as Non-aggregate)
  // it is not allowed to have LESS or MORE than required 
  // # of arguments when you try to initialize with the Brace-Initializing on a non-aggreaget UDT
  // (such as the Cpp0xNonAggregatePoint)
  // 
  //  const Cpp0xNonAggregatePoint p2 = {10};

  // if the containers has a constructor, the semantic is to call the ctor as well, as below
  // it is because of details that will be introduced soon
  std::vector<int> v { 1, p1.x, 2, p1.y, 3}; // call a vector ctor?
  std::unordered_set<float> s { 0, 1.5, 3 }; // call a unordered_set ctor??

  return 0;
}

/**
 * As you might be aware it is allowed to have the '=' or not to have the '=' sign, in most cases, but NOT ALWAYS
 */

class Cpp0xEqualSignNotAllowedWidget
{
public: 
  // this is not allowed.
  // Cpp0xEqualSignNotAllowedWidget() : data = {1, 2, static_a[3],4, 5 } {}
  Cpp0xEqualSignNotAllowedWidget() : data ({ 1, 2, static_a[3], 4, 5}) {}
private:
  const int data[5];
};
int WhatEqualSignNotAllowed() 
{

  const float val1 {1};
  const float val2 = {2};

  // the following '=' is not allowed
  // const float *pData = new const float[4] = {1.5, val1 - val1, 3.5, 4.5};
  
  // the following are not allowed neither.
  // Point2 makePoint() { return = {0.0}; }

  // void f (const std::vector<int> & v) ;
  // f ( = {val1, val2, 10, 20, 30} );

  // also, if the UDT has an explicit constructor, it is not allowd.

   // class Widget
   // {
   // public : 
   //   explicit Widget(int); 
   //   ...
   // };

   // Widget w1(10);  // allowed,
   // Widget w2{10};

   // Widget w3 = 10; // not allowed.
   // Widget w4 = {10};
}


// another rule of thumb is that in c++0x, the auto narrowing will not work, for more details, please read the 
// doc yourself.


struct Cpp98Struct 
{
  int x, y;
};


struct Cpp98Struct2
{
  int x, y;
public:
  Cpp98Struct2(int x, int y)
  {
    this->x = x;
    this->y = y;
  }
};



int WhatAreAllowedInCpp98()
{
  int vals[] = {10, 20, 30};
  const std::vector<int> cv(vals, vals + 3);

  // this is the way that you will need to initialize the non-aggregate
  const int y(5);    // it is a initialization, easy to tell
  const int x = 5;   // this is ALSO an initialization, though a bit obscure to apprehend

  // this is the easy way to initialize the structure in c++98
  const Cpp98Struct p1 = {10, 20};    // this is acceptable
  const Cpp98Struct2 p2(10, 20);       // this is also acceptable

  return 0;
}

// below are not allowed in the cpp98 standard

// class Cpp98NotAllowedInitClass
// {
// public :
//   Cpp98NotAllowedInitClass() : data (???) {}
// private:
//   const int data[5];
// };


int WhatAreNotAllowedInCpp98()
{

}


///////////////////////////////////////////////////////////////
// Initializer Lists					     //
// a mechanism to generalize array aggregate initialization: //
//    core                                                   //
//    -- std::initializer_list object                        //
///////////////////////////////////////////////////////////////

// simple:
//    brace initializer list convertible to std::initializer_list object
//  stores in an array and offers
//   size
//   begin
//   end
// to use
//  include <initializer_list>


std::u16string getName(int ID);

class Initializer_ListWidget 
{
public:

  Initializer_ListWidget(std::initializer_list<int> nameIDs)
  {
    names.reserve(nameIDs.size());
    for (auto id : nameIDs) names.push_back(getName(id));
  }

private:
  std::vector<std::u16string> names;
};


std::u16string getName(int ID)
{
  // TODO:
  //  find a name that corresponds to the ID 
  return nullptr;
 
}


int Initializer_ListDrive()
{
  Initializer_ListWidget w { 1, 2};
}


// a note to the initializer list
// 1.  the std::initializer_list can be templatized.
// 2. when overloaded, the std::initializer_list parameters are preferred for brace-delimited arguments.
//    for more details on the resolution on overloading, please see the appropriate docs.
