// blocks_main.m

#import <Foundation/Foundation.h>

int main (int argc, char * argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	void (^printMessage) (void) = 
		^(void) { 
			NSLog(@"Programming is fun!");
		};
		
	printMessage();
	
	[pool drain];
	return 0;
}