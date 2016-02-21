// XYPoint.h

#import <Foundation/Foundation.h>

@interface XYPoint : NSObject
{
	int x, y;
}

@property int x, y ;

-(void) setX: (int) xVal andY: (int) yVal;

@end
