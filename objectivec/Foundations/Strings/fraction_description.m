// Fraction_description.m
//   this file will override the description method to the Fraction object so that it can be used as the "toString" method in Java.
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
/*

the description method is inherited from the NSObject clas, and is is the method 
*/
-(NSString *) description;

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

-(NSString *) description
{
	return [NSString stringWithFormat: @"%i/%i", numerator, denominator];
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
	
	/* now instead of the Print method, you can as well directly put thye fractoin object as argument to the NSLog format method */
	
	NSLog(@"the value of the Fraction is %@", myFraction);
	
	[pool drain];
}
