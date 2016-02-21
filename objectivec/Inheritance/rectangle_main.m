// square_main.m

// this is the main methods that drives the rectangle's methods. 
#import "Rectangle.h"

int main(int argc, const char* argv[])
{

	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	MyRectangle *myRect = [[MyRectangle alloc] init];
	
	[myRect setWidth : 5 andHeight : 8];
	
	NSLog(@"Rectangle: w = %i, h = %i", myRect.width, myRect.height);
	NSLog(@"Area = %i, perimeter = %i", [myRect area], [myRect perimeter]);

	[pool drain];
	
	return 0;
}

