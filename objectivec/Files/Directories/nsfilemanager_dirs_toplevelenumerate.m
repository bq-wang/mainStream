// nsfilemanager_dirs_toplevelenumerate.m

/*

To enumerate through a directory, you can either get the contents out as a collection and then iterator through the collection or you should just 
call the enumeratorAtPath to get an enumerator, and then call the while loops on the Enumerator until it drain


Another difference is that the enumeratorAtPath will enumerate as well the sub

this program only enumerate the top level folder.

we need to define a BOOL flag, which we will use to check if a directory is a sub-directory

*/

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[])
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	NSString *path;
	NSFileManager *fm;
	NSDirectoryEnumerator *dirEnum;
	NSArray *dirArray;
	BOOL flag; 
	
	// Need to create an instance of the file manager
	fm = [NSFileManager defaultManager];
	
	// Get current working directory path
	path = [fm currentDirectoryPath];
	// enumerate the directories
	
	dirEnum = [fm enumeratorAtPath: path];
	
	NSLog (@"Contents of %@", path);
	while ((path = [dirEnum nextObject]) != nil){
		
		[fm fileExistsAtPath: path isDirectory: &flag];
		if (flag == YES) 
			[dirEnum skipDescendents];
		
		NSLog (@"%@", path);
		
	}
		
	// Another way to enumerate a directory
	dirArray = [fm contentsOfDirectoryAtPath:
		[fm currentDirectoryPath] error: NULL];

	NSLog (@"Contents using contentsOfDirectoryAtPath:error:");

	for (path in dirArray) 
		NSLog(@"%@", path);
	
	[pool drain];
	return 0;
}