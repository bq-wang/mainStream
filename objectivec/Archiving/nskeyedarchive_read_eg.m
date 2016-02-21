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
		NSDictionary *glossary;
		
		glossary = [NSKeyedUnarchiver unarchiveObjectWithFile: 
			@"glossary.archive"];
			//@"C:/dev/workspaces/Java/objectivec/glossary.archive"];
		
		for (NSString *key in glossary)
			NSLog(@"%@: %@", key, [glossary objectForKey: key]);
		
	}

	return 0;
}