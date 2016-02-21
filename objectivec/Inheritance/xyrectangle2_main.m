// xyrectangle2_main.m


#import "XYRectangle2.h"

int main(int argc, const char* argv [])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	XYRectangle *myRect = [[XYRectangle alloc] init];
	XYPoint *myPoint = [[XYPoint alloc] init];
	
	[myPoint setX: 100 andY: 8];
	
	// we might not be able to directly assign the following. 
	//myRect.orgin = myPoint;
	[myRect setWidth :5 andHeight :8];
	// [myRect setOrigin: myPoint];
	myRect.origin = myPoint;
	
	NSLog(@"Rectangle w = %i, h = %i", myRect.width, myRect.height);
	// NSLog(@"Origin at (%i, %i)", [myRect origin].x, [myRect origin].y);
	NSLog(@"Origin at (%i, %i)", myRect.origin.x, myRect.origin.y);

	NSLog(@"Area = %i, Perimeter = %i", [myRect area], [myRect perimeter]);

	[pool drain];
	
	return 0;
}