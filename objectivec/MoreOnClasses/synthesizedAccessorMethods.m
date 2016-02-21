// synthesizedAccessorMethods.m


// fraction.m
//  a class to show how the objective-c class/file/method are layouted and organized 

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

@end

int main(int argc, const char *argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	Fraction * myFraction = [[Fraction alloc] init];
	
	// to access, inspect its state, you don't need to the [] notation, which is the sending message meaning 
	// you can use the '.' dot notation 
	myFraction.numerator = 1;
	myFraction.denominator = 3;
	// you can still use the [] notation as the following 
	[myFraction numerator];

	double value = [myFraction convertToNum];
	NSLog(@" the value of the fraction is %lf", value);
	
	[myFraction print];
	[pool drain];
}