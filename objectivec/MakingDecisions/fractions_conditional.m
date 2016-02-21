// fractions_conditional.m

#import <Foundation/Foundation.h>
@interface Fraction: NSObject
{
	int numerator;
	int denominator;
}

-(void) print;
-(void) setNumerator: (int) n;
-(void) setDenominator: (int) d;
-(int) numerator;
-(int) denominator;
-(double) convertToNum;
@end

@implementation Fraction

-(void) print
{
	NSLog (@" %i/%i ", numerator, denominator);
}
-(void) setNumerator: (int) n
{
	numerator = n;
}
-(void) setDenominator: (int) d
{
	denominator = d;
}
-(int) numerator
{
	return numerator;
}
-(int) denominator
{
	return denominator;
}

// the NAN is included in the header "math.h", this is called the Not a Number.  
-(double) convertToNum
{
	if (denominator != 0)
		return (double) numerator / denominator;
	else
		return NAN;
}
@end

int main (int argc, char * argv[])
{

	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	Fraction *aFraction = [[Fraction alloc] init];
	Fraction *bFraction = [[Fraction alloc] init];
	[aFraction setNumerator: 1]; // 1st fraction is 1/4
	[aFraction setDenominator: 4];
	[aFraction print];
	NSLog (@" =");
	NSLog (@"%g", [aFraction convertToNum]);
	[bFraction print]; // never assigned a value
	NSLog (@" =");
	NSLog (@"%g", [bFraction convertToNum]);


	[pool drain];
	return 0;
}