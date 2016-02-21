// xmlproplists_eg.m

#import <Foundation/Foundation.h>

/*

[NSDictionary dictionaryWithContentsOfFile: @"glossary"];

can read content with format that it understands, so that it can understand the plists format, as well as the XML format.
*/

int main(int argc, char * argv[])
{
	@autoreleasepool {
		NSDictionary *glossary;
		
		glossary = [NSDictionary dictionaryWithContentsOfFile: @"glossary"];
		for (NSString * key in glossary) {
			NSLog (@"%@: %@", key, [glossary objectForKey: key]);
		}
		 
	}

	return 0;
}