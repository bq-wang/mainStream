/**
* file
*   template_specializations.cpp
* description
*   in this file, we are going to examing the template specialization and partial specialization
*/

#include "stdafx.h"
#include "template_specializations.h"
#include <vector>
#include <list>
#include <iostream>
#include <string>


using std::vector;
using std::list;
using std::cout;
using std::cerr;
using std::endl;

void test_template_specialization()
{
	Queue<int> queue1;
	vector<int> svec;
	queue1.assign(svec.begin(), svec.end());
	int max = queue1.max(); // this will call the general implementaion

	Queue<LongDouble> queue2;  // 
	vector <LongDouble> svec2;
	queue2.assign(svec2.begin(), svec2.end());
	LongDouble longdouble = queue2.max(); // this will call the 
}