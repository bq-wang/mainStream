#import "AddressCard_SynProps.h"

@implementation AddressCard
/*
{
	NSString *name;
	NSString *email;
}
//*/

@synthesize name = _name;
@synthesize email = _email;

/*@synthesize name, email; */

-(void) print
{

/* 
wonder why you have to name it self.name, other than just the 

	name

*/

	NSLog (@"====================================");
	NSLog (@"|                                 |");
	NSLog (@"| %-31s |", [self.name UTF8String]);
	NSLog (@"| %-31s |", [self.email UTF8String]);
	NSLog (@"|                                 |");
	NSLog (@"|                                 |");
	NSLog (@"|                                 |");
	NSLog (@"|       O               O         |");
	NSLog (@"====================================");
}

/* why we have this

	self.name = theName

instead of 
	
	name = theName;

which instead bypasses the setter and assigns the argument’s value directly to the instance variable.

*/

-(void) setName: (NSString *) theName andEmail: (NSString *) theEmail
{
	self.name = theName;
	self.email = theEmail;
}

-(NSComparisonResult) compareNames: (id) element
{
	return [self.name compare: [element name]];
}
@end