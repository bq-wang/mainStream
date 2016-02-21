// nsvalue_eg.m


/**

the NSValue class provides you means to create wrapper to objects of other types. 

*/

#import <Foundation/Foundation.h>
// #import <UIKit/UIKit.h>

/*
please check out the code belowe.

http://svn.gna.org/svn/gnustep/libs/quartzcore/trunk/Demo/DemoOpenGLView.m

*/

#if !(__APPLE__)
#import <GL/gl.h>
#import <GL/glu.h>
#else
#import <OpenGL/gl.h>
#endif
#import <CoreGraphics/CoreGraphics.h>

int main(int argc, char *argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	CGPoint myPoint;	
	NSvalue * pointObj;
	
	NSMutableArray *touchPoints = [NSMutableArray array];
	
	
	myPoint.x = 100;
	myPoint.y = 200;
	
	pointObj = [NSValue valueWithPoint: myPoint]; // make it an object
	
	[touchPoints addObject: pointObj];
	
	[NSValue valueWithPoints: myPoint];
	
	[pool drain];
	return 0;
}