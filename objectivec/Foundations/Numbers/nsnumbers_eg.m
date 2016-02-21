#import <Foundation/Foundation.h>

/*

NSNumber - the Foundations's Number Class

To store any of the basic numeric data types (including the char data type), you can use the NSNumber
class to create objects from these data types


NOTE:
types such as NSInteger is not a type, but instead a typedef.

CAVEAT:

be careful to take notice of the difference between the numberWithInteger and numberWithInt



*/
int main(int argc, const char *argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	NSNumber *myNumber,  *floatNumber, *intNumber;
	
	NSInteger myInt;
		
	// Integer value
	intNumber = [NSNumber numberWithInteger: 100];
	myInt = [intNumber integerValue];
	NSLog(@"%li", (long) myInt);
	
	// long value
	myNumber = [NSNumber numberWithLong: 0xabcdef];
	NSLog (@"%lx", [myNumber longValue]);
	
	// char value
	myNumber = [NSNumber numberWithChar: 'X'];
	NSLog (@"%c", [myNumber charValue]);
	
	// float value
	floatNumber = [NSNumber numberWithFloat: 100.00];
	NSLog (@"%g", [floatNumber floatValue]);
	
	// double
	myNumber = [NSNumber numberWithDouble: 12345e+15];
	NSLog (@"%lg", [myNumber doubleValue]);
	
	// Wrong access here
	NSLog (@"%li", (long) [myNumber integerValue]);
	
	// Test two Numbers for equality
	if ([intNumber isEqualToNumber: floatNumber] == YES)
		NSLog (@"Numbers are equal");
	else
		NSLog (@"Numbers are not equal");
		
	// Test if one Number is <, ==, or > second Number
	if ([intNumber compare: myNumber] == NSOrderedAscending)
		NSLog (@"First number is less than second");

	[pool drain];
	return 0;
}