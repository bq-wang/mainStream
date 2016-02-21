// designatedInitialized_main.m

// this file shows you some tips that how  you can use the initialized

/*

an example of the initialized pattern is the NSArray class contains the following six initialization methods. 

initWithArray:
initWithArray:copyItems:
initWithContentsOfFile:
initWithContentsOfURL:
initWithObjects:
initWithObjects:count:

*/

#import <Foundation/Foundation.h>
#import "Fraction.h"

int main(int argc, const char* argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	Fraction *a, *b;
	
	a = [[Fraction alloc] initWidth: 1 over: 3];
	b = [[Fraction alloc] initWidth: 3 over: 7];
	
	[a print];
	[b print];

	[pool drain];
	
	return 0;	
}