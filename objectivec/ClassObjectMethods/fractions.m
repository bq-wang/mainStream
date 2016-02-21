// Program to work with fractions – class version

#import <Foundation/Foundation.h>

//-------- @interface section ------------


@interface Fraction: NSObject
{
	int numerator;
	int denominator;
}


-(void)   print;
-(void)   setNumerator: (int) n;
-(void)   setDenominator: (int) d;

@end

//---- @implementation section ----
@implementation Fraction

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

@end

int main(int argc, const char *argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	NSLog(@"hello");
	
	Fraction *myFraction = [Fraction alloc];
	myFraction = [myFraction init]; // you cannot run this [myFraction init]; then you will get errors: , much like the non-initialized instance
									// calling methods, which of-course yield unwanted results.
	
	[myFraction setNumerator: 1];
	[myFraction setDenominator: 3];
	
	[myFraction print];
	[pool drain];
}
