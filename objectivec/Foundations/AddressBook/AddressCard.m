#import "AddressCard.h"

@implementation AddressCard
{
/*
	NSString *name;
	NSString *email;
//*/	
}


/* 
think of why we don't directly set the name = theName ?

that is because we want to AddressCard class to own the members instead of just storing a reference to the methods 
*/

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
	NSLog (@"|       O               O         |");
	NSLog (@"====================================");
}

@end