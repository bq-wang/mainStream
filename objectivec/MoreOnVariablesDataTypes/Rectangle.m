// Rectangle.m

#import "Rectangle.h"

@implementation XYRectangle

@synthesize width, height;

-(XYPoint *) origin
{
	return origin;
}

-(void) setOrigin: (XYPoint *) pt
{
	// it is not that safe to directly se the value of origin to the references to the pt;
	// Classes Owning Theirs Objects. 
	// 
	
	// origin = pt;
	
	if (! origin)
		origin = [[XYPoint alloc] init];
		
	origin.x = pt.x;
	origin.y = pt.y;
}

-(void) setWidth: (int) w andHeight : (int) h
{
	width = w;
	height = h;
}

-(int) area
{
	return width * height;
}

-(int) perimeter
{
	return (width + height) * 2;
}

@end