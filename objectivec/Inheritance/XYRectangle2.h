// XYRectangle.h

#import <Foundation/Foundation.h>
#import "XYRectangle2.h"
#import "XYPoint2.h"

// Using the @class directive is more efficient because the compiler doesn¡¯t need to
//import and therefore process the entire XYPoint.h file (even though it is quite small); it
//just needs to know that XYPoint is the name of a class. If you needed to reference one of
//the XYPoint class¡¯ methods (say in the implementation section), the @class directive
//would not suffice because the compiler would need more information; it would need to
//know how many arguments the method takes, what their types are, and what the method¡¯s
//return type is.

@class XYPoint;

@interface XYRectangle : NSObject
{
	int width, height;
	XYPoint *origin;
}

@property int width, height;

// we need to find better way to represent the Inheritance
// ../Inheritance/XYRectangle.h:14:1: warning: object property 'origin' has no 'assign', 'retain' or 'copy' attribute; assuming 'assign' [enabled by default]
//  ../Inheritance/XYRectangle.h:14:1: note: 'assign' can be unsafe for Objective-C objects; please state explicitly if you need it
// @property XYPoint *origin;

// instead of the property on the origin instance, we use a setter and a getter methods
-(XYPoint *) origin;
-(void) setOrigin: (XYPoint *) pt;
-(int) area;
-(int) perimeter;
-(void) setWidth: (int) w andHeight : (int) d;

@end


