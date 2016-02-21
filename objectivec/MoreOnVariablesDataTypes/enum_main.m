// enum_main.m


// this file will show you the enumeration type in Objective-C

/*

enum flag { false, true };

In theory, this data type can be assigned the values true and false inside the program, and no other values. Unfortunately, the Objective-C compiler does not generate warning messages if this rule is violated.

To declare a variable to be of type enum flag, you again use the keyword enum, followed by the enumerated type name, followed by the variable list. e.g. 

enum flag endOfData, matchFound;

the only values (in theory, that is ) that can be assigned to these variables are the names true and false, thuse statement like this:  

endOfData = true;

and


if (matchFound == false) 
 ...
 
The Objective-C compiler actually treats enumeration identifiers as integer constants.  If your program contains these two lines, the value 2 would be assigned to thisMonth (and not the name february):

enum month thisMonth;
	...
thisMonth = february;


Some variations are permitted when defining an enumerated data type: The name of the data type can be omitted, and variables can be declared to be of hte4 particular enumerated data type when the type is defined. As an examples showing both of these options, the statement 


enum { east, west, south, north } direction; 

defines an (unnamed) data types with values east, west, south or noth and declares a variables (direction) to be of that type. 

*/ 

#import <Foundation/Foundation.h>
// print the number of days in a month
int main(int argc, const char * argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	enum month { january = 1, february, march, april, may, june, july, august, september, october, november, december };
	
	enum month amonth;
	
	int days; 
	
	NSLog(@"Enter month number: ");
	scanf("%i", &amonth);
	
	switch (amonth) 
	{
		case january:
		case march:
		case may:
		case july:
		case august:
		case october:
		case december:
			days = 31;
			break;
		case april:
		case june:
		case september:
			days = 30;
			break;
		case february:
			days = 28;
			break;
		default:
			NSLog(@"Bad month number");
			days = 0;
			break;
	}
	if (days != 0)
		NSLog(@"Number of days is %i: ", days);
	if (amonth == february)
		NSLog(@".. or 29 if it's a leap year: ");
		
	
	[pool drain];
	return 0;	
}



