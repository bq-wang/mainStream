// nsfilemanager_eg.m

/*

To enumerate through a directory, you can either get the contents out as a collection and then iterator through the collection or you should just 
call the enumeratorAtPath to get an enumerator, and then call the while loops on the Enumerator until it drain


Another difference is that the enumeratorAtPath will enumerate as well the sub
*/

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[])
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	NSString *path;
	NSFileManager *fm;
	NSDirectoryEnumerator *dirEnum;
	NSArray *dirArray;
	
	// Need to create an instance of the file manager
	fm = [NSFileManager defaultManager];
	
	// Get current working directory path
	path = [fm currentDirectoryPath];
	// enumerate the directories
	
	dirEnum = [fm enumeratorAtPath: path];
	
	NSLog (@"Contents of %@", path);
	while ((path = [dirEnum nextObject]) != nil)
		NSLog (@"%@", path);
		
	// Another way to enumerate a directory
	dirArray = [fm contentsOfDirectoryAtPath:
		[fm currentDirectoryPath] error: NULL];

	NSLog (@"Contents using contentsOfDirectoryAtPath:error:");

	for (path in dirArray) 
		NSLog(@"%@", path);
	
	[pool drain];
	return 0;
}