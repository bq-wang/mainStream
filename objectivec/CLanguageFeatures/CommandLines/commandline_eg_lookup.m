#import <Foundation/Foundation.h>


struct entry
{
	char *word;
	char *definition;
};

int lookup(struct entry dictionary [], char search[], int entries)
{
	char *p, *q;
	int i = 0;
	for (;entries--; ++i, ++dictionary)
	{
		p = dictionary->word;
		q = search;
		
		/*
		while (*p != 0)
		{
			if (*p++ != *q++)
				return false;
		}
		return *q == 0;
		
		*/
		
		/*
		while (*p != 0 && *p++ == *q++);
		
		return *p == 0 && *q == 0;
		
		*/
		
		while (*p != 0 && *q != 0 && *p++ == *q++)
			;
		
		if (*p == 0 && *q == 0)
		{
			// found match 
			return i;
		}
	}
	return -1;
	
}

int main (int argc, char * argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	struct entry dictionary[100] = 
	{
		{ "aardvark", "A burrowing African mammal" },
		{ "abyss", "a bottomless pit" } ,
		{ "acumen", "mentally sharp; keen" } ,
		{ "addle", "to become confused" } ,
		{ "aerie", "a high nest" } ,
		{ "affix", "to append; attach" } ,
		{ "agar", "a jelly made from seaweed" } ,
		{ "ahoy", "a nautical call of greeting" } ,
		{ "aigrette", "an ornamental cluster of feathers" } ,
		{ "ajar", "partially opened" } } ;

	int entries = 10;
	int entryNumber; 
	int lookup(struct entry dictionary [], char search[], int entries);
	
	if (argc != 2)
	{
		NSLog(@"No word typed on the command line.");
		return (1);
	}
	
	entryNumber = lookup(dictionary, argv[1], entries);
	
	NSLog(@"returned entryNumber = %i", entryNumber);
	
	if (entryNumber != -1) 
		NSLog(@"%s", dictionary[entryNumber].definition);
	else
		NSLog(@"Sorry, %s is not in my dictionary.", argv[1]);
	
	[pool drain];
	return 0;
}