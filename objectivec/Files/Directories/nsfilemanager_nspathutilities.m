// nsfilemanager_eg.m

/*

NSPathUtilities.h includes functions and category extensions to NSString to enable you to manipulate pathnames. You should use these
whenever possible to make your program more independent of the structure of the file system and locations of particular files and directories. Program
16.5 shows how to use several of the functions and methods provided by NSPathUtilities.h.


*/

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[])
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	NSString *fName = @"path.m";
	NSFileManager *fm;
	NSString *path, *tempdir, *extension, *homedir, *fullpath;
	NSArray *components;
	fm = [NSFileManager defaultManager];
	
	// Get the temporary working directory
	tempdir = NSTemporaryDirectory ();
	NSLog (@"Temporary Directory is %@", tempdir);
	
	// Extract the base directory from current directory
	path = [fm currentDirectoryPath];
	NSLog (@"Base dir is %@", [path lastPathComponent]);
	
	// Create a full path to the file fName in current directory
	fullpath = [path stringByAppendingPathComponent: fName];
	NSLog (@"fullpath to %@ is %@", fName, fullpath);
	
	// Get the file name extension
	extension = [fullpath pathExtension];
	NSLog (@"extension for %@ is %@", fullpath, extension);
	
	// Get user's home directory
	homedir = NSHomeDirectory ();
	NSLog (@"Your home directory is %@", homedir);
	
	// Divide a path into its components
	components = [homedir pathComponents];
	for ( path in components )
		NSLog (@"%@", path);
	[pool drain];
	return 0;
}