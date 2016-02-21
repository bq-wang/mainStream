#include <iostream>
#include <memory>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <unordered_set>
#include <set>


//////////////////////////////////////////////////////////////////////
// Lambda/Closure Summary					    //
//   Lambda expressions generate closures.			    //
//   Calling state can be captured by value or by reference.	    //
//   Return types, when specified, use trailing return type syntax. //
//   Closures can be stored using auto or std::function.	    //
//  Be alert for dangling references/pointers in stored closures.   //
//   Short, clear, context-derived lambdas are best.		    //
//////////////////////////////////////////////////////////////////////



///////////////////////////////////
// Chapter 1 - Lambda Expression //
//  - Quick Guide		 //
///////////////////////////////////

void LambdaQuickStart()
{

  std::vector <int > v ;

  auto it = std::find_if(
    v.cbegin(), 
    v.cend(), 
    [](int i) { return i > 0 && i < 10; }
  );
}


// how does this work?
//  - quick answer 1
//   the following code has been generated.
//
// class MagicType1 {
// public :
//   bool operator()(int i) const { return i > 0 ; && i < 10; }
// };
// auto it = std::find_if(v.cbegin(), v.cend(), MagicType1());


class Widget 
{
public:
  int x, y;
  // you have to declare a comparison operator to make sure
  // that the lambda expression below to work.
  bool operator <(const Widget & w) const 
  {
    return this->x < w.x || (this->x == w.x &&  this->y < w.y);
  }
};


void Shared_Ptr_Dummy()
{
  typedef std::shared_ptr<Widget> SPWidget;

  std::deque<SPWidget> d;

  std::sort(d.begin(), d.end(),
	    [](const SPWidget& sp1, const SPWidget& sp2)
	    {
	      return *sp1 < *sp2;
	    }
   );

}




///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Chapter 2 - Closure											 //
// - default, the local variable coult not be captured, only the globals and the static can be captured. //
// - there is way to capture the local vals, detailes to be revailed soon in chapter 2.1		 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////

int a;

// std::function<bool(int)> is the way to tell the true type of the function
std::function<bool(int)> returnLambda()
{
  static int b, c;

  return [](int x) {
    return a* x * x + b * x + c == 0; };
}


void callReturnedLambda()
{
  auto f = returnLambda();
  if (f(22)) 
  {
    std::cout << "the correct answer "
	      << std::endl;
  }
}

////////////////////////////////////////////////////////////////////////
// Chapter 2.1 - Closure COPY VALUE				      //
// - this section will demonstrate how to capture the local variables //
////////////////////////////////////////////////////////////////////////

std::function<bool(int)> returnLambdaCaptureLocals()
{
  int minVal;
  double maxVal;

  std::vector<int> v;

  auto it = std::find_if(v.cbegin(), v.cend(), 
			 [minVal, maxVal](int i)
			 {
			   return i > minVal && i < maxVal;
			 }
			 );

}


//////////////////////////////////////////////////////////////////////////////////
// Chapter 2.1 - Closure : explained					        //
// 									        //
// the following code will be generated, 				        //
// please take care, the lambda above COPY VALUE, we will see another approach, //
// - COPY REFERENCE							        //
//////////////////////////////////////////////////////////////////////////////////

// class MagicType { 
// public:
//   MagicType(int v1, double v2): _minVal(v1), _maxVal(v2) {} 
//   bool operator()(int i) const { return i > _minVal && i < _maxVal; }
// private: 
//   int _minVal; 
//   double _maxVal;
// };
 
// auto it = std::find_if(v.cbegin(), v.cend(), MagicType(minVal, maxVal)); 

////////////////////////////////////////////////////////////////////////
// Chapter 2.2 - Closure COPY REFERENCE				      //
// - this section will demonstrate how to capture the local variables //
////////////////////////////////////////////////////////////////////////

std::function<bool(int)> returnLambdaCaptureLocalReferences()
{
  int minVal;
  double maxVal;

  std::vector<int> v;

  auto it = std::find_if(v.cbegin(), v.cend(), 
			 [&minVal, &maxVal](int i)
			 {
			   return i > minVal && i < maxVal;
			 }
			 );

}

//////////////////////////////////////////////////////////////////////////////////
// Chapter 2.2 - Closure COPY REFERENCE: explained			        //
// 									        //
// the following code will be generated, 				        //
// please take care, the lambda above COPY VALUE, we will see another approach, //
// - COPY REFERENCE							        //
//////////////////////////////////////////////////////////////////////////////////

// class MagicType { 
// public:
//   MagicType(int& v1, double& v2): _minVal(v1), _maxVal(v2) {} 
//   bool operator()(int i) const { return i > _minVal && i < _maxVal; }
// private: 
//   int& _minVal; 
//   double& _maxVal;
// };

//////////////////////////////////////////////////////////////////////////////////
// Chapter 2.3 - Closure COPY REFERENCE/COPY VALUE mixed:		        //
// 									        //
//   basically you can mix the & and the non-& paramters. examples ignored      //
//////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////
// Chapter 2.4 - Default mode                                                   //
// 									        //
//   [=] == by value  [&] == by ref                                             //
//////////////////////////////////////////////////////////////////////////////////

std::function<bool(int)> returnLambdaDefaultMode()
{
  int minVal;
  double maxVal;

  std::vector<int> v;

  auto it = std::find_if(v.cbegin(), v.cend(), 
			 [=](int i)
			 {
			   return i > minVal && i < maxVal;
			 }
			 );

  auto it2 = std::find_if(v.cbegin(), v.cend(),
			  [&](int i) 
			  {
			    return i > minVal && i < maxVal;
			  }
			  );
}

//////////////////////////////////////////////////////////////////////////////////
// Chapter 2.4 - Default mode                                                   //
// 									        //
//   Default overridable on a per-variable basis                                //
//////////////////////////////////////////////////////////////////////////////////

// example of the mixed default mode
// 
// auto it = std::find_if(v.cbegin(), v.cend(),  // default capture is 
// 		       [=, &maxVal](int i)  // by value, but maxVal
// 		       { return  i > minVal &&  // is by reference 
// 			 i < maxVal; });



//////////////////////////////////////////////////////////////////////////////////
// Chapter 2.4 - Capture class member                                           //
// 									        //
//   How to capture the class member?                                           //
//////////////////////////////////////////////////////////////////////////////////

class WidgetClassMemberCapture
{
public:
  void doSomething();
private : 
  std::list<int> li;
  int minVal;

};

void WidgetClassMemberCapture::doSomething() { 
 
  auto it = std::find_if(li.cbegin(), li.cend(), 
			 // do NOT use the following
			 // [minVal](int i) { 
			 // use the following
			 // However, the first statement shold compile just FINE.
			 [this](int i) {
			   return i > minVal;}
			 );
}


/////////////////////////////////////
// Chapter 3 - Return type	   //
// 				   //
// Optional when:		   //
//   Return type is void.	   //
//   Lambda body is ¡°return expr;¡± //
//  Return type is that of expr.   //
/////////////////////////////////////


std::function<double(double)> returnLambdaReturnType()
{
  std::vector<double> v;

  auto f =  [](double d) -> double 
    {
      std::cout << "std::transform" << std::endl;
      return std::sqrt(std::abs(d));
    };

  std::transform(v.begin(), 
		 v.end(),
		 v.begin(),
		 [](double d) -> double
		 {
		   std::cout << "std::transform"  << std::endl;
		   return std::sqrt(std::abs(d));
		 }
		 );

  return f;

}

///////////////////////////////////////////////////////////////
// Chapter 3 - Trailing Return Types			     //
//  - Must be used with lambdas (when a return type is given). //
//  - Often useful with decltype (described later).	     //
//  - Permitted for any function (with a leading auto):	     //
///////////////////////////////////////////////////////////////

// PLS note, it is permitted to annotate on any function
void f(int x);
auto f (int x)->void;

class WidgetTrailingReturnTypes
{
public:
  void mf1(int x);
  auto mf2() const -> bool;
};



////////////////////////////////////////
// Chapter 4 - Store the Closures     //
// 				      //
// - auto			      //
// - std::function		      //
// 				      //
// nothing special, ignored for space //
////////////////////////////////////////

// chapter x- advanced topics
// the advanced topic may include 
//  1. the mutable lambda
//  2. Short, clear, context-derived lambdas are best.
//  3. each lambda expression yeild a unique closure type, different impl has different rule to the generated names
//  4. the lambda recursion

//////////////////////////////////////////////////////////////////
// Chapter 5 - Specifying Function Types		        //
// - std::function<bool(long)>          // normal return type   //
// - std::function<auto (long)-> bool > // trailing return type //
//////////////////////////////////////////////////////////////////

void lambdaSpecifyFunctionType()
{
  std::function<bool(long)> multipleOf5 = [](long x) { return x % 5 == 0; };
  std::function<auto (long)-> bool> multipleOf5_2 = [](long x) { return x % 5 == 0; };
}

////////////////////////////////////
// Chapter 5 - Storing Closure 	  //
// too obvious, ignored for space //
////////////////////////////////////

///////////////////////////////////////
// Chapter 5.1 - Dangling references //
///////////////////////////////////////


// example as below.
// std::vector<long> vl;
// std::function<bool(long)> f;
// {  // some block
//   int divisor; 
//   ¡­ 
//     f = [&](long x) { return x % divisor == 0; };  // closure refers 
//   ¡­  // to local var
// }  // local var¡¯s 
// // scope ends
// vl.erase(std::remove_if(vl.begin(), vl.end(), f),  // calls to f use 
// vl.end());  // dangling ref!

//////////////////////////////////////////////////////////
// Chapter 6 - Lambda as Container Comparison Functions //
// 						        //
// - decltype: operator to get declartion type          //
//////////////////////////////////////////////////////////
void lambdaAsContainerComparison()
{

  auto cmpFunc = [](int *pa, int *pb) 
    {
      return *pa < *pb;
    };

  std::set<int *, decltype(cmpFunc)> s(cmpFunc); // sort this way
}

int main
(
 int argc,
 char *argv[]
)
{

  return 0;
}
