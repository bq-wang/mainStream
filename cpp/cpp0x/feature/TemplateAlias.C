#include <iostream>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <array>


// the following two statement are supposed to be the same
// but in fact, it is not the same as it is not supported yet in GCC 4.6
//
typedef std::unordered_set<int> IntHash1;
using IntHash =  std::unordered_set<int>;

// the following two statements are supposed to be the same
// which is to show that the 'using' statement is more comprehensive than you might though it is.
// the same as above, due to the limitation from the GCC compiler, it is not allowed to compile
typedef void (*CallBackPtr)(int);

using CallBackPtr = void (*)(int);


template <typename T>
using MyAllocVec = std::vector<T, MyAllocator>;


MyAllocVec<int> v;

// below declare a String array with a static template argument N, and the variable template name is std::string
// 

template <std::size_t N>
using StringArray = std::array<std::string, N>;

// declare a class with element type to be std::string, and len to be 15
//
StringArray<15> sa;


template <typename K, typename V>
using MapGT  = std::map<K, V, std::greater<K>>;

MapGT<long long, std::shared_ptr<std::string>> myMap; 



int main(
  int argc, 
  char * argv[]) 
{

  return 0;
}
