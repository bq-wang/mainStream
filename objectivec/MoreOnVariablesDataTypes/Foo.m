// @implementation Foo


#import "Foo.h"

// extern int gGlobalVar = 5;
@implementation Foo
{

}

-(void) setgGlobalVar: (int) val
{
	extern int gGlobalVar;
	gGlobalVar = val;
}

@end