// multi_arguments_withoutname.m

// when creating names for methods, the arguments name is actually optioanl, for examples, the set mehtod we defined before
// setTo :(int) n: over (int) d
// you can also use the following
// setTO: (int) n: (int) d


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
-(void) setTo: (int) n : (int) d;
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

-(void) setTo: (int) n : (int) d
{
	numerator = n;
	denominator = d;

}

@end

int main(int argc, const char *argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	Fraction * myFraction = [[Fraction alloc] init];
	
	//[myFraction setTo: 100 over: 200];
	[myFraction setTo: 100 : 200];
	[myFraction print];
	
	// careful how it differs before 
	// the code before is like this:  
	// [myFraction setTo: 1 over : 3];
	[myFraction setTo: 1 :3];
	[myFraction print];
	[pool drain];
}

