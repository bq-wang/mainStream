// Rectangle.h
#import <Foundation/Foundation.h>

@interface MyRectangle : NSObject
{
	int width, height;
}
@property int width, height;

-(int) area;
-(int) perimeter;
-(void) setWidth: (int) w andHeight : (int) d;

@end

