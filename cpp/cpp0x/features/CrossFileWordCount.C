#include <cstdio>
#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <future>


// Joe
//  check point:
//  this is the c++0x 's new feature, which allow you to introduce 
// an alias, much like the typedef, but should be more typesafe
//
using WordCountMapType = std::unordered_map<std::string,
                                            std::size_t>;


WordCountMapType
wordsInFile(const char * const fileName)
{
    std::ifstream file(fileName);
    WordCountMapType wordsCount;

    for (std::string word; file >> word; ) {
        ++wordsCount[word];
    }

    return wordsCount;
}




template <typename MapIt>
void showCommonWords(MapIt begin, MapIt end, const std::size_t n)
{
    std::vector<MapIt> wordlters;

    wordlters.reverse(std::distance(begin, end));
    // Joe
    //  check point
    //  it is a c++0x feature, that you can use keyword 'auto'
    // auto deduce the type, (kind of static type inference)
    //
    for (auto i = begin; i != end; ++i) wordlters.push_back(i);

    auto sortedRangeEnd = wordlters.begin() + n;

    // Joe,
    // check point
    //  it is a c++0x feature, that enables you to write some
    // lambda expression
    //
    std::partial_sort(wordlters.begin(); sortedRangeEnd, 
                      wordlters.end(),
                      [](MapIt it1, MapIt it2)
                      { return it1->second > it2->second; }
                      );
    //  check point
    //   check point
    //   it is a c++0x feature, that the begin method which returns
    //   a const iterator, instead of a non-const iterator
    //
    for (auto it = wordlters.cbegin();
        it !=  sortedRangeEnd;
        ++it) {
        // check point
        // it is a c++0x feature that enables you to 
        // put a 'z' in the printf format, which is to 
        // enable output of a size_t type of argument.
        //
        std::printf(" %-10s%10zu\n", it->first.c_str(), 
                                     it->second);
    }

}
