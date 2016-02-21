// dictionaries_eg.m

#import <Foundation/Foundation.h>

int main(int argc, char *argv[])
{
	NSAutoreleasePool *pool  = [[NSAutoreleasePool alloc] init];
	NSMutableDictionary *glossary = [NSMutableDictionary dictionary];
	
	[glossary setObject: @"A class defined so other classes can inherit from it"
		forKey: @"abstract class"];
	[glossary setObject: @"To implement all the methods defined in a protocol"
		forKey: @"adopt"];
	[glossary setObject: @"Storing an object for later use"
		forKey: @"archiving"];
	
	
	// Retrieve and display them.
	NSLog (@"abstract class: %@", [glossary objectForKey: @"abstract class"]);
	NSLog (@"adopt: %@", [glossary objectForKey: @"adopt"]);
	NSLog (@"archiving: %@", [glossary objectForKey: @"archiving"]);

	[pool drain];  
	return 0;
}