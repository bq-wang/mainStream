// simple_loop.m

#import <Foundation/Foundation.h>

int main
(int argc, const char *argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	int n, triangularNumber;
	
	
	NSLog(@"TABLE OF TRIANGULAR NUMBER");
	NSLog(@"n Sum from 1 tyo n");
	
	NSLog(@"-- --------------");
	
	
	triangularNumber = 0;
	
	for (n = 0; n <= 10; ++n) 
	{
		triangularNumber += n;
		NSLog(@"  %i                %i", n, triangularNumber);
	}
	
	[pool drain];

}