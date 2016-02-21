#import "Fraction.h"

// Define the Fraction class
// you don't need to have the redefine the base classes
//
@interface Fraction (MathOps)

-(Fraction *) add: (Fraction *) f;
-(Fraction *) mul: (Fraction *) f;
-(Fraction *) sub: (Fraction *) f;
-(Fraction *) div: (Fraction *) f;

@end


