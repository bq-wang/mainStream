// class_self.m

// self will identity the object that has the receiver of the caller's 


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
-(void) add: (Fraction *) f;
-(void) reduce;

@end


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

-(void) add: (Fraction *) f
{
	// To add two fractions:
	// a/b + c/d = ((a*d) + (b*c)) / (b * d)
	
	numerator = numerator * f.denominator + denominator * f.numerator;
	denominator = denominator * f.denominator;
	
	// tell itself to reduce when the add value is called.
	[self reduce];
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
	
	[aFraction add: bFraction];
	[aFraction print];
	
	// [aFraction reduce]; // no need to call the reduce method explicitly
	[pool drain];
}
