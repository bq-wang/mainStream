// xmlproplists_eg.m

#import <Foundation/Foundation.h>

/*

the generated files is like this: 

glossary


{
    "abstract class" = "A class defined so other classes can inherit from it.";
    adopt = "To implement all the methods defined in a protocol";
    archiving = "Storing an object for later use. ";
}

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
		
		/* Check for the user default */ 
		NSLog( @"%i, %i\n",
                                [[NSUserDefaults standardUserDefaults] 
boolForKey: @"GSMacOSXCompatible"],
                                [[NSUserDefaults standardUserDefaults] 
boolForKey:
@"NSWriteOldStylePropertyLists"] );

/*
 [[NSUserDefaults standardUserDefaults] setObject: @"YES" forKey:
@"GSMacOSXCompatible"];
                [[NSUserDefaults standardUserDefaults] setObject: @"NO" forKey:
@"NSWriteOldStylePropertyLists"];



		if ([glossary writeToFile: @"glossary" atomically: YES] == NO) 
			NSLog(@"Save to file failed!");
			
*/

/*

check this link: http://lists.gnu.org/archive/html/discuss-gnustep/2009-04/msg00158.html


AFAIK, [dict writeToFile: @"./opts.out.plist" atomically: YES]; writes
always in NSPropertyListOpenStepFormat while dictionaryWithContentsOfFile: tries all formats it knows. 
So you have written a plist format converter.

[[NSProperyListSerialization dataFromPropertyList:dict
	format:NSPropertyListXMLFormat_v1_0 errorDescription:&err]
	writeToFile: @"./opts.out.plist" atomically: YES];


*/
	NSString *err;
	[[NSPropertyListSerialization dataFromPropertyList: glossary format: NSPropertyListXMLFormat_v1_0 errorDescription: &err]
		writeToFile: @"glossary" atomically: YES];			
			
	}

	return 0;
}