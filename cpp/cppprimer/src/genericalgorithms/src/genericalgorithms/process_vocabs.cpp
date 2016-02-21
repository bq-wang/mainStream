/**
* file
*  process_vocabs.cpp
* this is a source file for a text processing application.
* 
* the general steps is as follow.
*  
*/


#include "stdafx.h"
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <list>
#include <allocators>
#include <fstream>

using std::cout;
using std::cerr;
using std::endl;
using std::cin;

using std::sort;
using std::stable_sort; // stable_sort will preserve the order of elements
using std::remove;
using std::copy;
using std::unique;
using std::count_if;

using std::string;
using std::vector;
using std::list;

using std::back_inserter;

using std::fstream;
using std::ifstream;
using std::istream_iterator; // the iterator to visit the istream object

//? 
// what is the allocator used for?
using std::allocator;

/**
* GreaterThan: function object class to filter word that is less than 6 length long
*/
class GreaterThan {
public :
	GreaterThan(int sz = 6) : _size(sz) { }
	bool operator ()( const string &s1) { return s1.size() > _size; } 
private:
	int _size;
};

/**
* PrintElem:
*  function object class to print element according to print format
*/
class PrintElem {
public:
	PrintElem(int lineLen = 8) : _line_length(lineLen), _cnt(0) {}
	void operator() ( const string &elem) {
		++_cnt;
		if (_cnt % _line_length == 0) { cout << "\n"; }

		cout << elem << " " ;
	}
private:

	int _line_length;
	int _cnt;
};

class LessThan
{
public:
	bool operator() (const string &s1, 
					 const string &s2) 
	{
		return s1.size() < s2.size(); 
	}
};

// the original text has the following declaration
// typedef vector<string, allocator> textword;
//
typedef vector<string> textwords;

// the original program has the following signature
// void process_vocab(vector<textwords, allocator>*pvec) 
//
void process_vocab(vector<textwords> *pvec)
{
	if (!pvec) { 
		return;
	}

	vector <string> texts;
	vector<textwords>::iterator iter;
	for (iter = pvec->begin(); iter != pvec->end(); ++iter) {
		copy(iter->begin(), (*iter).end(), back_inserter(texts));
	}

	// sort the element of the texts
	sort(texts.begin(), texts.end());

	// let's see what we have 
	for_each(texts.begin(), texts.end(), PrintElem());

	cout << "\n\n";

	// delete all duplicate elements
	vector<string>::iterator it;
	it = unique(texts.begin(), texts.end());
	texts.erase(it, texts.end());
	// ok, let's see what we have now
	for_each( texts.begin(), texts.end(), PrintElem() );
	cout << "\n\n";

	// ok, sort elements based on default length of 6
	// stable_sort will preserve the order of equal elements
	stable_sort(texts.begin(),  texts.end(), LessThan() );
	for_each(texts.begin(), texts.end(), PrintElem() );

	cout << "\n\n"; 
	// count number of string greater than length 6
	int cnt = 0;
	// obsolte form of count -- standard change this 
	cnt = count_if(texts.begin(), texts.end(), GreaterThan());

	cout << "Number of words greater than length six are " << cnt << endl;


	static string rw[] = {"and", "if", "or", "but", "the" };
	vector<string, allocator<string> > remove_words(rw, rw + 5);

	vector<string, allocator<string> >::iterator it2 = remove_words.begin();
	for (; it2 != remove_words.end(); ++it2) 
	{
		int cnt = 0;
		// obsolte form of count -- standard change this
		cnt = count(texts.begin(), texts.end(), *it2);

		cout << cnt << " instances removed: " << (*it2) << endl;
		texts.erase( remove(texts.begin(), texts.end(), *it2), // remove does not change the size of the container, but it 
			                                                   // moves the elements to rmeoved to the end of the vector
			texts.end() );

		cout << "\n\n";

		for_each( texts.begin(), texts.end(), PrintElem());
	}

}
// difference type is the type capable of holding the result 
// of subtracting two iterator of a container
// -- in this case, of a string vector ...
// ordinarily, this is handled by default 
typedef vector<string, allocator<string> >::difference_type diff_type;

// prestandard header syntax for <fstream>

int prcess_vocab_main()
{
	vector<textwords> sample;

	vector<string, allocator<string> > t1, t2;
	string t1fn, t2fn;
	// request input files from user ...
	// should so some error checking in real-world program
	cout << "text file #1 : " ; cin >> t1fn;
	cout << "text file #2 : " ; cin >> t2fn;

	// open the files
	ifstream infile1 (t1fn.c_str() );
	ifstream infile2 (t2fn.c_str() );

	// special form of iterator
	// ordinarily, diff_type is provided by default...
	// the obsolte form of the istream_iterator is as 
	//   istream _iterator<string, diff_type> .... 
	istream_iterator<string> input_set1(infile1), eos; // eos is the conierge that keep the door of something
	istream_iterator<string> input_set2(infile2);

	// special form of iterator
	copy(input_set1, eos, back_inserter(t1) );
	copy(input_set2, eos, back_inserter(t2) );
	

	// 
	sample.push_back(t1); sample.push_back(t2);
	process_vocab(&sample);


	return 0;

}