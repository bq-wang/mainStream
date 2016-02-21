// Fraction.m
// the implementation of the classs Fraction.m

#import "Fraction.h"

// --- @implementation section ---- 
static int pageCount;

@implementation Fraction

@synthesize numerator, denominator;

-(void) print
{
	NSLog(@"%i/%i", numerator, denominator);
}

-(double) convertToNum
{
	if (denominator != 0) 
		return (double) numerator / denominator;
	else 
		return NAN;
}

-(void) setTo: (int) n  over: (int) d
{
	numerator = n;
	denominator = d;
}

-(Fraction *) add: (Fraction *) f
{
	// To add two fractions:
	// a/b + c/d = ((a*d) + (b*c)) / (b * d)
	Fraction *result = [[Fraction alloc] init];
	
	result.numerator = numerator * f.denominator + denominator * f.numerator;
	result.denominator = denominator * f.denominator;
	
	
	return result;
}

-(void) reduce
{
	int u = numerator;
	int v = denominator;
	int temp; 
	
	while (v != 0)
	{
		// by deliberation we increase the count of the 'showCount'
		pageCount++;
		temp = u % v;
		u = v;
		v = temp;
	}
	
	numerator /= u;
	denominator /= u;
}

@end
