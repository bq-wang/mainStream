// Square.m

#import "Square.h"

@implementation Square : MyRectangle 
-(void) setSide: (int) s
{
	[self setWidth: s andHeight: s];
}

-(int) side
{
	return self.width;
}
@end

