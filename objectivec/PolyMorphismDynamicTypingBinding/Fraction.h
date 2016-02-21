// --- @interface section ----
//

#import <Foundation/Foundation.h>

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

