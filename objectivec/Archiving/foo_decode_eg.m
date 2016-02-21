// foo_decode_eg.m

#import <Foundation/Foundation.h>

#import "Foo.h"

int main(int argc, char * argv[])
{

	@autoreleasepool {
		Foo *myFoo1 = [[Foo alloc] init]; 
		Foo *myFoo2;
		
		[myFoo1 setStrVal: @"This is the string"];
		[myFoo1 setIntVal: 12345];
		[myFoo1 setFloatVal: 98.6];
		
		[NSKeyedArchiver archiveRootObject: myFoo1 toFile: @"foo.arch"];
		
		myFoo2 = [NSKeyedUnarchiver unarchiveObjectWithFile: @"foo.arch"];
		NSLog(@"%@\n%i\n%g", [myFoo2 strVal], [myFoo2 intVal], [myFoo2 floatVal]);
	}
	return 0;
}