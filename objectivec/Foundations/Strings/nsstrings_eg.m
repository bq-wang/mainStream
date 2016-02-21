// nsstrings_eg.m

#import <Foundation/Foundation.h>

int main(int argc, char *argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	NSString *str = @"Programming is fun";
	NSConstantString *str2 = @"Programming is also fun";
	NSLog (@"%@", str);
	NSLog(@"%@", str2);
	
	[pool drain];

	return 0;

}