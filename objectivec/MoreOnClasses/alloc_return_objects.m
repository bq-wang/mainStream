// alloc_return_object.m

// allocate and return new object from methods. 
// check this add method. 
 
#import <Foundation/Foundation.h>

// --- @interface section ---- 
// 
@interface Fraction : NSObject
{
	// in the Xcode, it is sames that you will need to the variable to be declared. 
	int numerator;
	int denominator;
}

@property int numerator, denominator;

-(void)	print;
-(void) setTo: (int) n over: (int) d;
-(double) convertToNum;
-(Fraction *) add: (Fraction *) f;
-(void) reduce;

@end


// --- @implementation section ---- 
static int pageCount;

@implementation Fraction
{
	// in xcode, you can duplciate the definiiotn of the interface variable again? 
	int numerator;
	int denominator;
}

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
	
	// tell itself to reduce when the add value is called.
	[result reduce];
	
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

int main(int argc, const char *argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	Fraction *aFraction = [[Fraction alloc] init];
	Fraction *bFraction = [[Fraction alloc] init];
	
	Fraction *resultFraction;
	
	[aFraction setTo: 1 over: 4];
	[bFraction setTo: 1 over: 2];
	
	[aFraction print];
	NSLog(@"+");
	
	[bFraction print];
	NSLog(@"=");
	
	resultFraction = [aFraction add: bFraction];
	[resultFraction print];
	
	// [aFraction reduce]; // no need to call the reduce method explicitly
	[pool drain];
}


