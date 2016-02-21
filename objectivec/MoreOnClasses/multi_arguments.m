// multi-arguments.m

// in objective-c , if you want to define multiple method,  you can simply
// defines methods that take multiple arguments simply by listing each  successively argumetn by a colon.

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


@end


// --- @implementation section ---- 
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

-(void) setTo: (int) n over: (int) d
{
	numerator = n;
	denominator = d;

}

@end

int main(int argc, const char *argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	Fraction * myFraction = [[Fraction alloc] init];
	
	[myFraction setTo: 100 over: 200];
	[myFraction print];
	
	[myFraction setTo: 1 over :3];
	[myFraction print];
	[pool drain];
}

