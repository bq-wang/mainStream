// #import <Cocoa/Cocoa.h>

/* this is the same as the following 
*/

/*
#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
*/

/* The following line creates the shared application instance */
//[NSApplication sharedApplication];

/* Then, use NSApp to access NSApplication's shared instance  */
/*
@interface MyDelegate: NSObject

-(void) applicationWillFinishLaunching: (NSNotification *) not;
@end

@implementation MyDelegate :NSObject

-(void) applicationWillFinishLaunching: (NSNotification *) not
{
	// TODO: - create the menu here.
	
	NSMenu *menu;
	
	menu = AUTORELEASE([NSMenu new]);
	[menu addItemWithTitle: @"Quit"
		action: @selector (terminate:)
		keyEquivalent: @"q"];
	[NSApp setMainMenu: menu];
	
	
}
@end


int main(int argc, const char **argv)
{
	[NSApplication sharedApplication];
	[NSApp setDelegate: [MyDelegate new]];
	
	return NSApplicationMain (argc, argv);
}

*/

#include <Foundation/Foundation.h>
#include <AppKit/AppKit.h>

@interface MyDelegate : NSObject
- (void) applicationWillFinishLaunching: (NSNotification *)not;
@end

@implementation MyDelegate : NSObject 
- (void) applicationWillFinishLaunching: (NSNotification *)not
{
  NSMenu *menu;
  
  menu = AUTORELEASE ([NSMenu new]);
  [menu addItemWithTitle: @"Quit"  
        action: @selector (terminate:)  
        keyEquivalent: @"q"];
  [NSApp setMainMenu: menu];
}
@end

int main (int argc, const char **argv)
{ 
  [NSApplication sharedApplication];
  [NSApp setDelegate: [MyDelegate new]];

  return NSApplicationMain (argc, argv);
}