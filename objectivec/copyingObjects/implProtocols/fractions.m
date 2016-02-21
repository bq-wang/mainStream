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

*/

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
-(void) setTo: (int) theNumerator over: (int) theDenominator
{
	numerator = theNumerator;
	denominator = theDenominator;
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

-(id) copyWithZone: (NSZone *) zone
{
	/* you might as well change the line as read 
	
	Fraction *newFract = [[Fraction allocWithZone: zone] init];

	*/
	
	/* to the following reading as follow */
	
	id newFract = [[[self class] allocWithZone: zone] init];

	
	[(Fraction *) newFract setTo: numerator over: denominator];
	
	return newFract;
}

@end
