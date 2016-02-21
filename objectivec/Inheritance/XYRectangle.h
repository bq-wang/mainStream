// XYRectangle.h

#import <Foundation/Foundation.h>
#import "XYRectangle.h"
#import "XYPoint.h"

@interface XYRectangle : NSObject
{
	int width, height;
	XYPoint *origin;
}

@property int width, height;

// we need to find better way to represent the Inheritance
// ../Inheritance/XYRectangle.h:14:1: warning: object property 'origin' has no 'assign', 'retain' or 'copy' attribute; assuming 'assign' [enabled by default]
//  ../Inheritance/XYRectangle.h:14:1: note: 'assign' can be unsafe for Objective-C objects; please state explicitly if you need it
@property XYPoint *origin;

-(int) area;
-(int) perimeter;
-(void) setWidth: (int) w andHeight : (int) d;

@end


