// append_eg.m
/*

// Append the file "fileA" to the end of "fileB"

the key here is to use the NSFileHandle and navigate to the end of the file 

*/



#import <Foundation/Foundation.h>

int main(int argc, char *argv[])
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	NSFileHandle *inFile, *outFile;
	NSData *buffer;

	// Open the file fileA for reading
	inFile = [NSFileHandle fileHandleForReadingAtPath: @"fileA"];
	if (inFile == nil) {
		NSLog (@"Open of fileA for reading failed");
		return 1;
	}
	// Open the file fileB for updating
	outFile = [NSFileHandle fileHandleForWritingAtPath: @"fileB"];
	if (outFile == nil) {
		NSLog (@"Open of fileB for writing failed");
		return 2;
	}

	// Seek to the end of outFile
	[outFile seekToEndOfFile];
	
	// Read inFile and write its contents to outFile
	buffer = [inFile readDataToEndOfFile];
	[outFile writeData: buffer];
	
	// Close the two files
	[inFile closeFile];
	[outFile closeFile];
	
	// verify its contents
	NSLog(@"%@", [NSString stringWithContentsOfFile: @"fileB"
		encoding: NSUTF8StringEncoding error: NULL]);

	[pool drain];
	return 0;
}