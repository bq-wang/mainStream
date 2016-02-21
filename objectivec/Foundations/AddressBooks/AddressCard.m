// addressCard.m


#import "AddressCard.h"
@implementation AddressCard
/*
{
	NSString *name;
	NSString *email;
}
//*/

-(void) setName: (NSString *) theName
{
	name = [NSString stringWithString: theName];
}
-(void) setEmail: (NSString *) theEmail
{
	email = [NSString stringWithString: theEmail];
}
-(NSString *) name
{
	return name;
}
-(NSString *) email
{
	return email;
}
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
@end