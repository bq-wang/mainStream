// dictionaries_eg3.m
/*

we will try to sort the dictionary keys by the alphabetic orders. 


*/
#import <Foundation/Foundation.h>

int main(int argc, char *argv[])
{
	NSAutoreleasePool *pool  = [[NSAutoreleasePool alloc] init];

	NSArray *keys = [states allKeys];
	keys = [keys sortedArrayUsingComparator: 
		^(id obj1, id obj2) { 
			return [obj1 compare: obj2];
		}];

	for (NSString *aState  in keys) 
		NSLog(@"
	[pool drain];
	return 0;  
}