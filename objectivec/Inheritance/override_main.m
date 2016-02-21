// override_main.m

// Override that shows how the override works in Objective-C , however, we don't introduce the polymorphism
// which underpinning the modern technology 

#import <Foundation/Foundation.h>

@interface ClassA : NSObject
{

	int x; // will be inherited by subclasses
}

-(void) initVar;
@end

// implementation ClassA
 
@implementation ClassA
-(void) initVar
{
    x = 100;
}

// though printVar is not declared in the interface ClassA, but you can use it in some scope that reachable to the implementation to ClassA..
-(void) printVar
{
	NSLog(@"x = %i", x);
}


@end

// ClassB declaration and definition 

@interface ClassB : ClassA
-(void) initVar;

-(void) printVar;

@end

//////////////////////////////////
@implementation ClassB
-(void) initVar 
{
	x = 200;
}

-(void) printVar
{
	NSLog(@"x = %i", x);
}

@end

int main(int argc, const char* argv [])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	ClassA *a = [[ClassA alloc] init];
	ClassB *b = [[ClassB alloc] init];
	
	[a initVar]; // uses ClassA method 
	[a printVar]; // reveal value of x;
	
	
	[b initVar]; // uses overriding method in B
	[b printVar]; // reveal value of x;
	[pool drain];
	
	return 0;
}
