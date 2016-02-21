// genericalgorithms.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

extern int arrayIteratorDemo1();
extern int containerIteratorDemo1();

extern int prcess_vocab_main();



extern int test_back_inserter();
extern int test_front_inserter();
extern int test_inserter();
extern int do_not_trust_this_code();
extern void reverse_iterator();

extern void iostream_iterator();
extern void test_ifstream_iterator();
extern void test_ofstream_iterator();

extern int test_fstream_args();

int insert_iterator();
void reverse_iterator_demo();
void test_exception_to_return_match();


int _tmain(int argc, _TCHAR* argv[])
{
	//prcess_vocab_main(); // normaly you will input two tyupe coaieh 
	//insert_iterator();
	//reverse_iterator_demo();
	//iostream_iterator();
	//test_ifstream_iterator();
	//test_ofstream_iterator();
	//test_fstream_args();
	test_exception_to_return_match();

	return 0;
}


int commonIteratorExample1()
{
	arrayIteratorDemo1();
	containerIteratorDemo1();
	return 0;
}


int insert_iterator() 
{
	test_back_inserter();
	test_front_inserter();
	test_inserter();
	do_not_trust_this_code();

	return 0;
}


void reverse_iterator_demo()
{
	reverse_iterator();
}