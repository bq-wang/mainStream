#include <iostream>
#include <string>
using std::string;

void exception_specification();

int main(int argc, char * argv[])
{
    exception_specification();
}



typedef int exceptionType;
void no_problem() throw ()
{}
void doit(int , int) throw (std::string, exceptionType)
{}
void recoup(int, int) throw (exceptionType) {}

void exception_specification()
{
   // ok , recoup is as restrictive as pf1
   void (*pf1) (int, int) throw (exceptionType)  = &recoup;

   void (*pf2) () throw (std::string) = &no_problem;
   // it seems the following code is as OK as before ?
   // why? pfc3 is more restrictive thatn the doit function
   void (*pf3)(int, int) throw (std::string) = &doit;
}
