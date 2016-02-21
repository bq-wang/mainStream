// AddressBook.m

#import "AddressBook.h"

@implementation AddressBook 

@synthesize bookName, book;


// set up the AddressBook¡¯s name and an empty book
-(id) initWithName: (NSString *) name
{
	self = [super init];
	if (self) {
		bookName = [NSString stringWithString: name];
		book = [NSMutableArray array];
	}
	return self;
}

-(id) init
{
	return [self initWithName: @"NoName"];
}

-(void) addCard: (AddressCard *) theCard 
{
	[book addObject: theCard];
}

-(NSUInteger) entries
{
	return [book count];
}

-(void) list 
{
	NSLog(@"======  Contents of : %@ =========", bookName);

/*
Fast enumeration: 

the list methods 'for' loop shows a construct which is called the Fast Enumeration  

for (AddressCard *theCard in book) 
	NSLog(@"%-20s    %-32s", [theCard.name UTF8String], [theCard.emaiol UTF8String]);


things that we may want to discover is what we need to do if we want to make our classes that support the Fast Enumeration  . 




*/	
	for ( AddressCard *theCard in book )
		NSLog (@"%-20s %-32s", [theCard.name UTF8String],
			[theCard.email UTF8String]);
			
	NSLog (@"==================================================");
}

/*
	Section Sorting
*/

-(void) sort
{
	/* however, this is not supported by the GNUstep libaries */
	
	//[book sortUsingComparator: 
	//	^(id obj1, id obj2) { 
	//		return [obj1 compareNames: obj2];
	//	}];
	
	
	[book sortedArrayUsingFunction: _compare_func 
		context: nil];
}

NSComparisonResult _compare_func (id obj1, id obj2, void *context) {
	return [(AddressCard *) obj1 compareNames: (AddressCard *) obj2];
}
/*
	- End section 
*/


/*
	Section Encoding
*/

-(void) encodeWithCoder: (NSCoder *) encoder
{
	[encoder encodeObject: bookName forKey: @"AddressBookBookName"];
	[encoder encodeObject: book forKey: @"AddressBookBook"];
}

-(id) initWithCoder: (NSCoder *) decoder
{
	bookName = [decoder decodeObjectForKey: @"AddressBookBookName"];
	book = [decoder decodeObjectForKey: @"AddressBookBook"];
	
	return self;
}

/*
	- End section 
*/



@end