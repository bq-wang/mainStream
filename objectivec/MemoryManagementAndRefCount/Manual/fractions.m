// Program to work with fractions – class version

#import <Foundation/Foundation.h>

//-------- @interface section ------------

/*
@interface Fraction: NSObject
{
	int numerator;
	int denominator;
}

-(void)   print;
-(void)   setNumerator: (int) n;
-(void)   setDenominator: (int) d;

@end
//*/

#import "fractions.h"

//---- @implementation section ----
@implementation Fraction
@synthesize numerator, denominator;

-(void) print 
{
	NSLog(@"%i/%i", numerator, denominator);
}

-(void) setNumerator: (int) n
{
	numerator = n;
}

-(void) setDenominator: (int) d
{	
	denominator = d;
}

/*

we want the returned result to be cleaned by the AutoreleasePool, so 
you either.

	Fraction *result = [[[Fraction alloc] init] autorelease];

or

	return [result autorelease];
*/
-(Fraction *) add: (Fraction *) f
{
	// To add two fractions:
	// a/b + c/d = ((a*d) + (b*c)) / (b * d)
	// result will store the result of the addition
	
	/*Fraction *result = [[Fraction alloc] init]; */
	Fraction *result = [[[Fraction alloc] init] autorelease];
	
	result.numerator = numerator * f.denominator + denominator * f.numerator;
	
	result.denominator = denominator * f.denominator;
	
	[result reduce];
	
	/* return result; */
	return [result autorelease];
	
}

-(void) reduce
{

	int u = numerator;
	int v = denominator;
	int temp;
	
	while (v != 0)
	{
		temp = u % v;
		u = v;
		v = temp;
	}
	
	numerator /= u;
	denominator /= u;
}

@end
