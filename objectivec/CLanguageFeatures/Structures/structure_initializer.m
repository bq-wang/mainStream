#import <Foundation/Foundation.h>

int main (int argc, char * argv[])
{
   NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	struct date
	{
		int month;
		int day;
		int year;
	};
	
	/*
	Specific members can be designated for initialization in any order with the notation
	
		.member = value
		
	in the initialization list, as in

	*/
	struct date today = { .month = 7, .day = 2, .year = 2011 };
	
	struct date today1 = { 7, 2, 2011 } ;
	
	struct date today2 = { 7 };
	
	NSLog(@"Today's date is %i/%i/%.2i.", today.month, today.day, today.year % 100);

	[pool drain];
	return 0;
}