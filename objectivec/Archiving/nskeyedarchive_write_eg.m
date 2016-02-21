// nskeyedarchive_write_eg.m

#import <Foundation/Foundation.h>

/*

A more flexible approach enables you to save any type of objects to a file, not just strings, arrays, and dictionaries. This is done by creating a keyed
archive using the NSKeyedArchiver class.

the upside about the NSKeyedArchiver is that if there is new instance variables added or removed to a class, your program can accounts for it.
*/

int main(int argc, char * argv[])
{
	@autoreleasepool { 
		NSDictionary *glossary = 
			[NSDictionary dictionaryWithObjectsAndKeys: 
				@"A class defined so other classes can inherit from it.",
				@"abstract class",
				@"To implement all the methods defined in a protocol",
				@"adopt",
				@"Storing an object for later use. ",
				@"archiving",
				nil
				];
				
		[NSKeyedArchiver archiveRootObject: glossary toFile: @"glossary.archive"];
	}

	return 0;
}