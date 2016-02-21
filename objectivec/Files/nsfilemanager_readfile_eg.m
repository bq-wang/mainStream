// nsfilemanager_nspathutilities.m

/*

This file will shows you how to read contents of files into the memory buffers.
*/

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[])
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	NSFileManager *fm;
	
	NSData *fileData;
	
	
	fm = [NSFileManager defaultManager];
	
	// Read the file newfile2
	fileData = [fm contentsAtPath: @"newfile2"];
	
	if (fileData == nil) { 
		NSLog(@"File read failed!");
		return 1;
	}
		
	// Write the Data to newfile3
	if ([fm createFileAtPath: @"newfile3" contents: fileData attributes: nil] == NO) { 
		NSLog(@"Could not create the copy!");
		return 2;  
	}
	[pool drain];
	return 0; 
}