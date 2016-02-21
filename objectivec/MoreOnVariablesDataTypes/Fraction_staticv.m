// @implementation Foo

#import "Fraction_staticv.h"

// --- @implementation section ---- 

static int gCounter;

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

-(void) setTo: (int) n  over: (int) d
{
	numerator = n;
	denominator = d;
}

-(Fraction *) add: (Fraction *) f
{
	// To add two fractions:
	// a/b + c/d = ((a*d) + (b*c)) / (b * d)
	Fraction *result = [[Fraction alloc] init];
	
	result.numerator = numerator * f.denominator + denominator * f.numerator;
	result.denominator = denominator * f.denominator;
	
	
	return result;
}

-(void) reduce
{
	int u = numerator;
	int v = denominator;
	int temp; 
	
	while (v != 0)
	{
		// by deliberation we increase the count of the 'showCount'
		temp = u % v;
		u = v;
		v = temp;
	}
	
	numerator /= u;
	denominator /= u;
}

-(Fraction *) initWidth: (int) n over: (int) d
{
	// NOTE: the super is a keyword that delegate work to the parent job. 
	// 
	self = [super init];
	
	// the template for initializing the code from the sub-classes code. 
	// why we should reassign the value of the self to returned value of the [super init];
	//
	// You must assign the result of executing the parent¡¯s init method back to self
	// because an initializer has the right to change the location of the object in memory
	// (meaning its reference will change).

	if (self)
	{
		[self setTo: n over: d];
	}
	
	return self;
}

-(Fraction *) init
{
	//
	// Note that init is defined to return an id type.That¡¯s the general rule for writing init
	// methods for a class that might be subclassed.You don¡¯t want to hardcode a class name in
	// such cases, as the subclass will not be an object from the same class as the parent.To be
	// consistent here you should go back to the initWith:over: method and change its return
	// type to id.
	//
	return [self initWidth: 0 over: 0];
}

+(Fraction *) allocF
{
	extern int gCounter;
	++gCounter;
	
	return [Fraction alloc];
}

+(int) count
{
	extern int gCounter;
	
	return gCounter;

}

// other methods from Fraction class go here. 
// ...

@end