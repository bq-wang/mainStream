#include <Foundation/Foundation.h>
#include <AppKit/AppKit.h>


int main (int argc, const char **argv)
{ 
	@autoreleasepool {
  		NSView *myView = [[[NSView alloc] initWithFrame: NSMakeRect(10, 10, 10, 10)] autorelease];
    }
  
  return 0;
}