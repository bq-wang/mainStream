#import <Foundation/Foundation.h>

// Define the Fraction class

@interface Fraction : NSObject
//*
{
	int numerator, denominator;
}
//*/
@property int numerator, denominator;

-(void) setTo: (int) n over: (int) d;
// -(Fraction *) add : (Fraction *) f;
-(void) reduce;
-(double) convertToNum;
-(void) print;
@end


