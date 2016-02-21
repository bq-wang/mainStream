#include <iostream>


// using namespace std;

template <typename T, int size>
const T min(T const (&r_arr)[size]) 
{
  T min_val = r_arr[0];
  for (int i = 0; i < size; i++) { 
    if (r_arr[i] < min_val) {
      min_val = r_arr[i];
    }
  }
  return min_val;
}


typedef double (&rad)[20];
typedef double (&rid)[10];


void func(double (*) (rad)) { 

}

void func(int (*) (rid)) 
{

}

typedef const double const_double;

int main(int argc, char *argv[]) 
{
   // func(static_cast<double (*)(double (&)[20])>(&min);   
   //  const_double  (*  a)(double (&)[20]) = &min;
   // func(static_cast<double (*)(double (&)[20])>(&min);   

  // const_double& (* a)(double (&)[20]) = &min; 
   const_double (* a)(const double (&)[20]) = &min; 

}

