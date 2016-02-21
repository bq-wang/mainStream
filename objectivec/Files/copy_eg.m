// copy_eg.m

#import <Foundation/Foundation.h>

int main(int argc, char *argv[])
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	NSFileManager *fm;
	NSString *source, *dest;
	BOOL isDir;
	NSProcessInfo *proc = [NSProcessInfo processInfo];
	NSArray *args = [proc arguments];
	fm = [NSFileManager defaultManager];
	
	// Check for two arguments on the command line
	if ([args count] != 3) {
		NSLog (@"Usage: %@ src dest", [proc processName]);
		return 1;
	}
	source = [args objectAtIndex: 1];
	dest = [args objectAtIndex: 2];
	
	// Make sure the source file can be read
	if ([fm isReadableFileAtPath: source] == NO) {
		NSLog (@"Can't read %@", source);
		return 2;
	}
	// See if the destination file is a directory
	// if it is, add the source to the end of the destination
	[fm fileExistsAtPath: dest isDirectory: &isDir];
	if (isDir == YES)
		dest = [dest stringByAppendingPathComponent:
			[source lastPathComponent]];
	
	// Remove the destination file if it already exists
	[fm removeItemAtPath: dest error: NULL];
	
	// Okay, time to perform the copy
	if ([fm copyItemAtPath: source toPath: dest error: NULL] == NO) {
		NSLog (@"Copy failed!");
		return 3;
	}
	
	NSLog (@"Copy of %@ to %@ succeeded!", source, dest);

	[pool drain];
	return 0;
}