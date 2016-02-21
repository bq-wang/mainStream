#import <Foundation/Foundation.h>

	struct date
	{
		int month;
		int day;
		int year;
	};


static struct date g_globalDate;

void setStartDate(
 struct date date
)
{
	g_globalDate.month = date.month;
	g_globalDate.day = date.day;
	g_globalDate.year = date.year;

}

int main (int argc, char * argv[])
{
   NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	/* struct date
	{
		int month;
		int day;
		int year;
	};
	*/
	
	/*
	
	A compound literal is a type name enclosed in parentheses followed by an initialization list. It creates an unnamed value of the specified type, which has
scope limited to the block in which it is created or global scope if defined outside any block. In the latter case, the initializers must all be constant
expressions.

   Consider this examples:
   
   (struct date) { .month = 7, .day = 2, .year = 2011 } ;
   
   theDate = (struct date) { .month = 7, .day = 2, .year = 2011 } ;
   
   
   */
   
   struct date theDate;
   int * intPtr;
   
   theDate = (struct date) { .month = 7, .day = 2, .year = 2011} ;
	
	setStartDate((struct date) { .month = 7, .day = 2, .year = 2011 } );
	
	/* you can define types other than structures */
	intPtr = (int [100]) { [0] = 1, [50] = 50, [99] = 99 } ;
	
	[pool drain];
	return 0;
}
