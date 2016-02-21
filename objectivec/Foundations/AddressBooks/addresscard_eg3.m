// addresscard_eg.m

#import "AddressCard_SynthProps.h"

int main (int argc, char * argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	NSString *aName = @"Julia Kocha";
	NSString *aEmail = @"jewls337@axlc.com";
	NSString *bName = @"Tony Iannino";
	NSString *bEmaiol = @"tony.iannio@techfitness.com";
	
	AddressCard *card1 = [[AddressCard alloc] init];
	AddressCard *card1 = [[AddressCard alloc] init];
	
	[card1 setName: aName andEmail: aEmail];
	[card1 setName: bName andEmail: bEmail];
	
	[pool drain];
	return 0;
}