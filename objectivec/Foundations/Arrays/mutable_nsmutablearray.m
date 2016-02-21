// mutable_nsmutablearray.m


#import <Foundation/Foundation.h>

int main(int argc, const char *argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	NSMutableArray *numbers = [NSMutableArray array];
	NSNumber *myNumber;
	int i;
	
	// Create n array with the number 0 - 9
	for (i = 0; i < 10; ++i) {
		myNumber = [NSNumber numberWithInteger: i];
		[numbers addObject: myNumber];
	}
	
	// Sequence through the array and display the values 
	for (i = 0; i < 10; ++i) {
		myNumber = [numbers objectAtIndex: i];
		NSLog(@"%@", myNumber);
	}
	
	// Look how NSLog can display it with a single %@ format
	NSLog(@"=== Using a single NSLog");
	NSLog(@"%@", numbers);
	
	[pool drain];
	return 0;
}