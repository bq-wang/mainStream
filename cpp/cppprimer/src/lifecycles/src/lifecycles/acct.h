#include <vector>
#include <cstddef> // you will find the pair type from this header files. 
using std::vector;
using std::pair;

typedef pair<char *, double > value_pair;

/**
* file
*  acct.h
* description: 
*   the class definition of the Account class
*
*/
class Account {

public:

/* =================
* ctor and dtors
========================*/
	Account();
	// since a constructor that takes only a single parameter can serves as a conversion operator
	// we don't want tripwire people into the trap of 
	//  Account acct = "new user";
	// to help curb/reign this kind of unwantted/unwelcome compiler aid, the explicit keyword is introduced 
	//  
	//explicit
	//Account(const char *, double = 0.0);
	
	// for the purpose of demo the use of the array initalizer, we decide to use the implicit constructor approach
	Account(const char *, double = 0.0);

	// the copy constructor 
	// the most important thing about the copy constructor is to decide whether or not to provide the copy constructor
	// the how as to implements the copy constructor comes seconds
	Account(const Account & );


	~Account();

	const char * name();
	Account * init_heap_array(vector<value_pair> &init_values, 	vector<value_pair>::size_type elem_count = 0) ;

private:
	char * _name;
	unsigned int _acct_nmbr;
	double _balance;
	
	static unsigned int _unique_acct_nmbr;
	static unsigned int get_unique_acct_nmbr();
	static void return_acct_nmbr(unsigned int acct_nmbr);
	
protected:
};

