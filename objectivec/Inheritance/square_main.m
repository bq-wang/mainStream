// square_main.m


// this file is the main method that uses square and others. 

#import <Foundation/Foundation.h>
#import "Square.h"

int main(int argc, const char *argv[])
{

	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	Square *mySquare = [[Square alloc] init];
	
	[mySquare setSide: 5];
	
	NSLog(@"Square s = %i", [mySquare side]);
	NSLog(@"Area = %i, Perimeter = %i", [mySquare area], [mySquare perimeter]);
	
	[pool drain];
	
	return 0;
}
