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
	
	struct date today;
	
	today.month = 9;
	today.day = 25;
	today.year = 2011;
	
	NSLog(@"Today's date is %i/%i/%.2i.", today.month, today.day, today.year % 100);

	[pool drain];
	return 0;
}