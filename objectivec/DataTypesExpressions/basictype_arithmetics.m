// basictype_arithmetics.m

#import <Foundation/Foundation.h>

int main(int argc, const char *argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	int a = 25, b = 5, c = 10, d = 7;
	
	NSLog(@"a %% b = %i", a % b);
	NSLog(@"a %% c = %i", a % c);
	NSLog(@"a %% d = %i", a % d);
	NSLog(@"a /d * d + a %% d= %i", a / d * d + a % d); 
	[pool drain]; 
}