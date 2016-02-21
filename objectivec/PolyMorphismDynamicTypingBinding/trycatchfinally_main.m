// trycatchfinally_main.m

// Good programming practice dictates that you try to anticipate problems that can occur in
// your program.You can do this by testing for conditions that could cause a program to terminate
// abnormally and handling these situations, perhaps by logging a message and gracefully
// terminating the program or taking some other corrective action.


#import "Fraction.h"

/*
int main(int argc, char * argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	Fraction *f = [[Fraction alloc] init];
	
	// despite the warnings, you can still compile the code but you may get runtime error when you run it. 
	// the exception that you get is like this: 
	//   : Uncaught exception NSInvalidArgumentException, reason: -[Fraction noSuchMehod]: unrecognized selector sent to instance 0x6bd588
	[f noSuchMehod];
	NSLog(@"Execution continues!");
	
	[pool drain];
	
	return 0;

}
*/

int main(int argc, char * argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	NSArray *myArray = [NSArray array];
	
	@try { 
		[myArray objectAtIndex: 2];
	}
	@catch (NSException *exception)	{
		NSLog(@"Caught %@%@", exception.name, exception.reason);
	}
	
	NSLog(@"Execution continues");
	
	[pool drain];
	
	return 0;

}