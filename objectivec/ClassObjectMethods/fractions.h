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
