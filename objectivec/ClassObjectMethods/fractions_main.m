#import <Foundation/Foundation.h>
#import "fractions.h"

int main(int argc, const char *argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	NSLog(@"hello");
	
	Fraction *myFraction = [Fraction alloc];
	myFraction = [myFraction init];
	
	[myFraction setNumerator: 1];
	[myFraction setDenominator: 3];
	
	[myFraction print];
	[pool drain];
}