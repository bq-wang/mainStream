// bitoperation_main.m

/*

this file will shows you some feel of the bit operation that you may use 

*/

#import <Foundation/Foundation.h>

int main(int argc, const char *argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	unsigned int w1 = 0xA0A0A0A0, w2 = 0xFFFF0000,
	w3 = 0x00007777;
	NSLog (@"%x %x %x", w1 & w2, w1 | w2, w1 ^ w2);
	NSLog (@"%x %x %x", ~w1, ~w2, ~w3);
	NSLog (@"%x %x %x", w1 ^ w1, w1 & ~w2, w1 | w2 | w3);
	NSLog (@"%x %x", w1 | w2 & w3, w1 | w2 & ~w3);
	NSLog (@"%x %x", ~(~w1 & ~w2), ~(~w1 | ~w2));

	[pool drain];
	
	return 0;	
	

}