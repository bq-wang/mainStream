// Point2.m


// actually the same implementation as the XYPoint.m

#import "Point.h"

@implementation XYPoint 

@synthesize x,y;

-(void) setX: (int) xVal andY: (int) yVal
{
	x = xVal;
	y = yVal;
}

@end
