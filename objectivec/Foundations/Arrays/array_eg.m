#import <Foundation/Foundation.h>

/*

NSArray:
A Foundation array is an ordered collection of objects. Most often, elements in an array are of one particular type, but that’s not required. 

Immutable Array: NSArray class
Mutable Array: NSMutableArray class


*/
int main(int argc, const char *argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	int i;
	
	/* 
	
	Why we need to insert a 
	'nil' object into the NSArray object?
	
	
	as it is has been told, to mark the end of the list, nil must be specified as the last value in the list - it isn't actually stored inside the array..
	*/
	
	NSArray *monthNames = [NSArray arrayWithObjects:
	 	@"January", @"February", @"March", @"April",
		@"May", @"June", @"July", @"August", @"September",
		@"October", @"November", @"December", nil];
	
	// now list all the elements in the array 
	
	NSLog(@"Month    Name");
	NSLog(@"=====    ====");
	
	for (i = 0; i < 12; ++i)
	{
		NSLog(@" %2i    %@", i + 1, [monthNames objectAtIndex: i]);
	}
	
	[pool drain];
	return 0;
}