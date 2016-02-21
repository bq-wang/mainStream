// manual_release_eg.m

#import "fractions.h"

/* 

the core part here is to send the release message to the object once done with it.


the core is the release message sent to it, when you are done with the object, you should send a release messgae to it and let the 

system to take care of it (when reference counting goes down to zero..)
*/

int main(int argc, char *argv[] )
{
	NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
	
	Fraction *frac1 = [[Fraction alloc] init];
	Fraction *frac2 = [[Fraction alloc] init];
	
	// Set 1st fraction to 2/3
	[frac1 setNumerator: 2];
	[frac1 setDenominator: 3];
	
	// Set 2nd fraction to 3/7
	[frac2 setNumerator: 3];
	[frac2 setDenominator: 7];
	
	// Display the fractions
	NSLog (@"First fraction is:");
	[frac1 print];
	NSLog (@"Second fraction is:");
	[frac2 print];
	
	
	[frac1 release];
	[frac2 release];
	[pool drain];
	
	return 0;
}
