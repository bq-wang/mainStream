// nsfilemanager_eg.m

/*

the main classes that you will need to deal with files or directories include the following 

*/

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[])
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	NSString *fName = @"testfile";
	NSFileManager *fm;
	NSDictionary *attr;
	
	// Need to create an instance of the file manager
	
	fm = [NSFileManager defaultManager];
	
	// let's make sure our teset file exists first
	if ([fm fileExistsAtPath: fName] == NO) { 
		NSLog(@"File doesn't exist!");
		return 1;
	}
	
	//now lets make a copy
	if ([fm copyItemAtPath: fName toPath: @"newfile" error: NULL] == NO) {
		NSLog(@"File Copy failed!");
		return 2;
	}

	// Now let's test to see if the two files are equal
	if ([fm contentsEqualAtPath: fName andPath: @"newfile"] == NO)
	{
		NSLog(@"Files are Not Equal!");
		return 3;
	}
	
	// Now lets rename the copy
	if ([fm moveItemAtPath: @"newfile" toPath: @"newfile2" error: NULL] == NO){
		NSLog(@"File rename Failed");
		return 4;
	}
	
	// get the size of the newfile2
	if ((attr = [fm attributesOfItemAtPath: @"newfile2" error: NULL]) == nil) 
	{
		NSLog(@"Couldn't get file attributes!");
		return 5;
	}
	
	NSLog(@"File size is %llu bytes",
		[[attr objectForKey: NSFileSize] unsignedLongLongValue]);
	
	// And finally, let's delete the original file
	if ([fm removeItemAtPath: fName error: NULL] == NO) {
		NSLog(@"file removal failed");
		return 6;
	}
	
	NSLog(@"All operations were successful");
	
	// Display the contents oft he newly-created file 
	
	NSLog(@"%@", [NSString stringWithContentsOfFile: @"newfile2" encoding: NSUTF8StringEncoding error: NULL]);
	
	[pool drain];
	return 0;
}