#include "stdafx.h"

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::copy;
using std::inserter;


class CustomClass 
{
public: 
	CustomClass(string name_, int age_) : name(name_), age(age_) {
	  cout << "inside CustomClass(string name, int age)" << endl;
	}
	CustomClass(const CustomClass& rhs) : name(rhs.name), age(rhs.age) {
	  cout << "inside CustomClass(const CustomClass& rhs)" << endl;
	}
private:
	std::string name;
	int age;
};

void TestVectorCopy()
{
	//vector<CustomClass> customClasses(4) = 
	// the results shows that it will first call the constructor with (string, int), then with the const CustomClass& - the copy constructor
	cout << "the aray initializer []" << endl;
	CustomClass customClasses[] = { CustomClass("joe", 29), CustomClass("Yun", 30), CustomClass("Cliff", 31), CustomClass("Nora", 31), CustomClass("Tom", 30) }; 

	vector<CustomClass> v_customClasses;

	v_customClasses.reserve(sizeof(customClasses) / sizeof(CustomClass));

	cout << "the defalt CustomClass" << endl;
	// as you can see, there are in total const CustomClasses&  called when copy from the CustomClass[] to the vector<CustomClass>
	copy(customClasses, customClasses + 4, inserter(v_customClasses, v_customClasses.begin())); 

	// as you will find in the following code, another CustomClasses is called
	vector<CustomClass> v_customClasses2 = v_customClasses;

	// 
	cout << "copy constructor on the CustomClass" << endl;
	vector<CustomClass> v_customClasses3;
	v_customClasses.reserve(v_customClasses2.size());
	copy(v_customClasses.cbegin(), v_customClasses.cend(), inserter(v_customClasses3, v_customClasses3.begin()));

}