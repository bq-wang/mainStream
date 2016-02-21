// addressCard.m


#import "AddressCard_SynthProps.h"
@implementation AddressCard
/*
{
	NSString *name;
	NSString *email;
}
//*/

/*
since we have the @property and the @synthesize methosd, what the compiler generate is like this:  
(let's take the name for example )

-(void) setName: (NSString *) theName
{
	if (theName != name)
		name = [theName copy];
} 

*/

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

/*
following method
	copyWithZone
	assignName
are implementation to the NSCopying protocol

*/
-(void) setName: (NSString *) theName andEmail: (NSString *) theEmail
{
	self.name = theName;
	self.email = theEmail;
}

-(AddressCard *) copyWithZone: (NSZone *) zone
{
	AddressCard *newCard = [[AddressCard allocWithZone: zone] init];
	
	[newCard assignName: self.name andEmail: self.email];
	return newCard;
}


-(void) assignName: (NSString *) theName andEmail: (NSString *) theEmail
{
	self.name = theName;
	self.email = theEmail;
}

/*
	Section Sorting
*/

-(NSComparisonResult) compareNames: (id) element
{
	return [name compare: [element name]];
}
/*
	- End section 
*/

/*
	Section NSCoding 
*/

-(void) encodeWithCoder: (NSCoder *) encoder
{
	[encoder encodeObject: self.name forKey: @"AddressCardName"];
	[encoder encodeObject: self.email forKey: @"AddressCardEmail"];
}

-(id) initWithCoder: (NSCoder *) decoder
{
	self.name = [decoder decodeObjectForKey: @"AddressCardName"];
	self.email = [decoder decodeObjectForKey: @"AddressCardEmail"];
	return self;
}

/*
	- End section 
*/
@end