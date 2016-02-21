/**
* file
*  member_templates.cppp
* description:
*   this is a file that demonstrate the use of the member template inside template classes
*/

#include "stdafx.h"
#include "member_templates.h"
#include <vector>
#include <iostream>
#include <string>
#include <list>

using std::vector;
using std::cout;
using std::string;
using std::list;

void demo_class_templates()
{
	Queue<int> qi;

	vector<int> vsi;

	qi.assign(vsi.begin(), vsi.end());

	list<int> lp;

	qi.assign(lp.begin(), lp.end());

	list<int*> lvp;

	//qi.assign(lvp.begin(), lvp.end());
}