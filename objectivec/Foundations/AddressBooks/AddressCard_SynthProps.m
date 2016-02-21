// addressCard.m


#import "AddressCard_SynthProps.h"
@implementation AddressCard
/*
{
	NSString *name;
	NSString *email;
}
//*/

@synthesize name, email;

-(void) print
{
	NSLog (@"====================================");
	NSLog (@"|                                 |");
	NSLog (@"| %-31s |", [name UTF8String]);
	NSLog (@"| %-31s |", [email UTF8String]);
	NSLog (@"|                                 |");
	NSLog (@"|                                 |");
	NSLog (@"|                                 |");
	NSLog (@"|      O           O              |");
	NSLog (@"====================================");
}

-(void) setName: (NSString *) theName andEmail: (NSString *) theEmail
{
	self.name = theName;
	self.email = theEmail;
}
@end