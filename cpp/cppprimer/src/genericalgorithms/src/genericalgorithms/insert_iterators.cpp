/**
* insert_iterator.cpp
*  this is the cpp source file that help to portray the use of iterator in the most common cases, such as inserter;
*/


#include "stdafx.h"

#include <iostream>
#include <functional>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>

using std::vector;
using std::back_inserter;
using std::front_inserter;
using std::inserter;  
using std::unique_copy;
using std::cout;
using std::cin;
using std::list;

using std::istream_iterator;
using std::ostream_iterator;

using std::greater;


/**
* this is a wrong use of iterator, which may cause the runtime error, because it is highly likely the container.begin() does not point to a valid insert location
*/
int test_runtime_error() { 
	int ia[] = { 0, 1, 1, 2, 3, 5, 5, 8 };
	vector<int> ivec(ia, ia + 8), vres;

	unique_copy(ivec.begin(), ivec.end(), vres.begin());  // this will fail, and more dreadfully it fails on runtime, because the vres may be empty
	return 0;
}

int test_back_inserter()
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 5, 8 };
	vector<int> ivec(ia, ia + 8), vres;

	unique_copy(ivec.begin(), ivec.end(), back_inserter(vres));

	return 0;
}


int test_front_inserter() 
{
	// oops, for a vector you cannot insert to the front, it is not suppported operation for vector
	//int ia[] = { 0, 1, 1, 2, 3, 5, 5, 8 };
	//vector<int> ivec(ia, ia + 8), vres;

	//unique_copy(ivec.begin(), ivec.end(), front_inserter(vres));

	int ia[] = { 0, 1, 1, 2, 3, 5, 5, 8 };
	list<int> ilist (ia, ia + 8), ires;

	unique_copy(ilist.begin(), ilist.end(), front_inserter(ires));
	return 0;
}

int test_inserter()
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 5, 8 };
	vector<int> ivec(ia, ia + 8), vres;

	unique_copy(ivec.begin(), ivec.end(), inserter(vres, vres.begin()));

	return 0;
}

int do_not_trust_this_code()
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 5, 8 };
	vector<int> ivec(ia, ia + 8), vres;

	vector<int>::iterator iter = vres.begin(), iter2 = ivec.begin();

	for (; iter2 != ivec.end(); ++iter, ++iter2) { 
		vres.insert(iter, *iter2);
	}

	return 0;
}



void display(const vector<int> & rvec)
{
	vector<int>::const_iterator it = rvec.begin();
	for (; it != rvec.end(); ++it) {
		cout << *it  << " ";
	}
}


/* =======================

the following will show  you how to use the reverse iterator, which give you the ability to go over a collection in the reverse ordre

  ======================== */

void reverse_iterator() {
	int ia[] = { 0, 1, 1, 2, 3, 5, 5, 8 };
	vector<int> ivec(ia, ia + 8), vres;

	vector<int>::reverse_iterator r_iter;
	for (r_iter = ivec.rbegin(); // do you see the danger, if a user write the code as ivec.begin(), which return a iter type, then it might fail, but the compile simply does not allow you to do that. so you have to write rbegin()
		r_iter != ivec.rend();
		++r_iter) 
	{
		cout << *r_iter << " ";
		/*
		...
		*/
	}

}

/* =======================

input : 23 109 4 80 6 34 12 90 34 23 56 23 8 89 23

output: 109 90 56 45 34 23 12 8 6

  ======================== */

void iostream_iterator()
{
   istream_iterator <int> input(cin);
   istream_iterator <int> end_of_stream; // an empty object of istream_iterator is marker of the end of stream

   vector<int> vec;
   copy(input, end_of_stream, inserter(vec, vec.begin()));
   sort (vec.begin(), vec.end(), greater<int>() );
   ostream_iterator <int> output (cout);
   unique_copy(vec.begin(), vec.end(), output);

}


#include <fstream>
#include <string>
using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::cerr;


void test_ifstream_iterator(){

	ifstream infile ("data1.txt");
	istream_iterator<string> is_string (infile);

    istream_iterator<string> end_of_string;
	vector<string> text;
	copy(is_string, end_of_string, inserter(text, text.begin()));
}


void test_ofstream_iterator() 
{
	// this two lines is irrelevant to our discussion below, but we can still see how to constrct some output stream object
	ofstream outfile("dictionary");
	ostream_iterator<string> os_string(outfile, "\n"); // this is the way how you would provide the necessary sperator in

	// here we are going to read from the standard input and output to the standard output 
	copy(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout, ","));

}


int test_fstream_args() 
{
	string file_name;
	cout << "please enter a file to open:  " ;
	cin >> file_name;

	if (file_name.empty() || !cin) {   // this is the c++ way to check if there is valid input or simply because the std input stream is dead
		cerr << "unable to read file name \n"; 
		return -1;
	}
	ifstream infile(file_name.c_str()) ;

		if (! infile) // it has redefined the bool() operator, so you can check in if statement to see if you can read successfully
		{
			cerr << "unable to open " << file_name << endl;
			return -2;   // normally you will return a non-zero value to indicate error
		}

		istream_iterator<string> ins(infile), eos;
		ostream_iterator<string> outs(cout, " ");

		copy(ins, eos, outs);

		return 0;
}


