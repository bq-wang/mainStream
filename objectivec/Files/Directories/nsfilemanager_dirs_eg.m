// nsfilemanager_eg.m

/*

the main classes that you will need to deal with files or directories include the following 

*/

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[])
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	NSString *dirName = @"testdir";
	NSString *path;
	NSFileManager *fm;
	
	// Need to create an instance of the file manager
	fm = [NSFileManager defaultManager];
	
	// Get Current directory 
	
	path = [fm currentDirectoryPath];
	NSLog(@"Current directory path is %@", path);
	
	// Create a new directory 
	if ([fm createDirectoryAtPath: dirName withIntermediateDirectories: YES
		attributes: nil error: NULL] == NO) { 
			NSLog (@"Couldn't create directory!");
			return 1;
	}
	
	// Rename the new directory
	if ([fm moveItemAtPath: dirName toPath: @"newdir" error: NULL] == NO) {
		NSLog (@"Directory rename failed!");
		return 2;
	}
	
	// Change directory into the new directory
	if ([fm changeCurrentDirectoryPath: @"newdir"] == NO) {
		NSLog (@"Change directory failed!");
		return 3;
	}
	// Now get and display current working directory 
	path = [fm currentDirectoryPath];
	NSLog (@"Current directory path is %@", path);
	
	NSLog (@"All operations were successful!");
	[pool drain];
	return 0;
}