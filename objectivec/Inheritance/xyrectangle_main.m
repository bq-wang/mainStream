// xyrectangle_main.m

#import "XYRectangle.h"

int main(int argc, const char* argv [])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	XYRectangle *rectangle = [[XYRectangle alloc] init];
	
	rectangle.origin = [[XYPoint alloc] init];
	rectangle.origin.x = 5;
	rectangle.origin.y = 6;
	
	rectangle.width = 4;
	rectangle.height = 5;
	
	NSLog(@"rectangle.area = %i", [rectangle area], [rectangle perimeter]);
	NSLog(@"the origin is (%i/%i)", rectangle.origin.x, rectangle.origin.y);

	[pool drain];
	
	return 0;
}