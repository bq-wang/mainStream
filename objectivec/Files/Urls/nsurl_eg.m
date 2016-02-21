// append_eg.m
/*

// Append the file "fileA" to the end of "fileB"

the key here is to use the NSFileHandle and navigate to the end of the file 


you can convert a string representation of a URL to a URL itself and besides you are allowed to retrieve the content from that URL and get string contents back
*/

#import <Foundation/Foundation.h>

int main(int argc, char *argv[])
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	NSURL *myURL = [NSURL URLWithString: @"http://classroomM.com"];
	
	NSString * myHomePage = [NSString stringWithContentsOfURL: myURL
		encoding: NSASCIIStringEncoding error: NULL];
		
	NSLog(@"%@", myHomePage);
	[pool drain];
	return 0;
}