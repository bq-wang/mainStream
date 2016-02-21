// paths_eg.m

/*

the main classes that you will need to deal with files or directories include the following 

*/

#import <Foundation/Foundation.h>

NSString *saveFilePath()
{
	NSArray *dirList = NSSearchPathForDirectoriesInDomains
		(NSDocumentDirectory, NSUserDomainMask, YES);
		
	NSString * docDir = [dirList objectAtIndex: 0];
	
	return [docDir stringByAppendingPathComponent: @"saveFile"];
  
}

int main(int argc, const char * argv[])
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	NSString *path = saveFilePath();
	NSLog(@"%@", path);
	[pool drain];
	return 0;
}