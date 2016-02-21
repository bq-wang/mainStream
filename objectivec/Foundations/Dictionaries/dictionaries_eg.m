// dictionaries_eg2.m

/*

we will show what is a dictionaries by the following rules. 


*/

#import <Foundation/Foundation.h>

int main(int argc, char *argv[])
{
	NSAutoreleasePool *pool  = [[NSAutoreleasePool alloc] init];

	NSDictionary *glossary = 
		[NSDictionary dictionaryWithObjectsAndKeys: 
			@"A class defined so other classes can inherit from it",
			@"abstract class",
			@"To implement all the methods defined in a protocol",
			@"adopt",
			@"Storing an object for later use",
			@"archiving",
			nil
		];
	
	// print all key-value pairs from the dictionary
	
	for (NSString *key in glossary)
		NSLog(@"%@: %@", key, [glossary objectForKey: key]);
		
	[pool drain];
	return 0;


}