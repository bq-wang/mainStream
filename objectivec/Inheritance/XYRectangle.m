// "XYRectangle.m"

#import "XYRectangle.h"

@implementation XYRectangle

@synthesize width, height;
@synthesize origin;

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