// gGlobal_main.m

#import <Foundation/Foundation.h>
#import "Foo.h"

int gGlobalVar = 5;

int main(int argc, const char* argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	Foo *myFoo = [[Foo alloc] init];
	NSLog(@"%i ", gGlobalVar);
	
	[myFoo setgGlobalVar: 100];
	NSLog(@"%i ", gGlobalVar);

	[pool drain];
	
	return 0;	
}