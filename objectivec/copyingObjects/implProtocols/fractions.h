// Program to work with fractions – class version

#import <Foundation/Foundation.h>

//-------- @interface section ------------

// to implements the protocol <NSCopying> ...
@interface Fraction: NSObject <NSCopying>
{
	int numerator;
	int denominator;
}

@property (nonatomic, assign) int numerator, denominator;
-(void)   print;
-(void)   setNumerator: (int) n;
-(void)   setDenominator: (int) d;
-(void)   setTo: (int) theNumerator over: (int) theDenominator;
/* add fraction returns a new Fraction object, and that object should
 * 1. claimed when the pool drain
 * 2. not dispose because its result should return to the caller
 */
-(Fraction *) add: (Fraction *) f;
-(void) reduce;

-(id) copyWithZone: (NSZone *) zone;
@end
