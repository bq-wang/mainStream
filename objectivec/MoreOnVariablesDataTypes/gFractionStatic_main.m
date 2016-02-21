// gGlobal_main.m

#import <Foundation/Foundation.h>
#import "Fraction_staticv.h"

int main(int argc, const char* argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	Fraction *a, *b, *c;
	NSLog(@"Fractions allocated: %i", [Fraction count]);
	
	a = [[Fraction allocF] init];
	b = [[Fraction allocF] init];
	c = [[Fraction allocF] init];

	NSLog(@"Fractions allocated: %i", [Fraction count]);

	[pool drain];
	return 0;	
}
