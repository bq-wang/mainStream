// AddressBook.m

#import "AddressBook.h"

@implementation AddressBook
@synthesize bookName = _bookName;
@synthesize book = _book;

// set up the AddressBook's name and an empty book

-(id) initWithName: (NSString *) name
{
	self = [super init];
	
	if (self) { 
		self.bookName = [NSString stringWithString: name];
		self.book = [NSMutableArray array];
	}
	
	return self;
}

-(id) init
{
	return [self initWithName: @"NoName"];
}

-(void) addCard: (AddressCard *) theCard
{
	[self.book addObject: theCard];
}

-(int) entries
{
	return [self.book count];

}

-(void) list
{
	NSLog(@"======= Contents of :%@ =============", self.bookName);
	/* this is so called fast enumeration */
	for ( AddressCard *theCard in self.book )
		NSLog (@"%-20s %-32s", [theCard.name UTF8String],
			[theCard.email UTF8String]);
	
	NSLog(@"========================================");
}

// lookup address card by name -- assumes an exact match 
-(AddressCard *) lookup : (NSString *) theName
{
	for (AddressCard *nextCard in self.book)  {
		if ([nextCard.name caseInsensitiveCompare : theName] == NSOrderedSame) 
			return nextCard;
	}
	return nil;
}

-(void) sort
{
	/* the selector is on the address card object */
	// [self.book sortUsingSelector: @selector(compareNames:)];
	
	/* 
	
	we can as well use the comparator syntax, it is like this:
	
	
	why it complains that the sortUsingComparator is not part of hte NSMutableArray??
	 
	.\addressbook_test1.exe: Uncaught exception NSInvalidArgumentException, reason: -[GSMutableArray sortUsingComparator:]: unrecognized selector sent to instance 0x54a5a0
	
	*/
	/*
	[self.book sortUsingComparator: 
		^(id obj1, id obj2) { 
			return [obj1 compareNames: obj2];
		}];
	*/
	
	/* while sorting with sort descriptor works , check how to sort with descriptor here: 
	
		How to sort a NSMutableArray using NSSortDescriptor: http://stackoverflow.com/questions/15027377/how-to-sort-a-nsmutablearray-using-nssortdescriptor?rq=1
	*/
	
	/*
	NSSortDescriptor *sortDescriptor = [[NSSortDescriptor alloc] initWithKey: @"name" ascending: YES];
	self.book = (NSMutableArray *) [self.book sortedArrayUsingDescriptors: [NSArray arrayWithObject: sortDescriptor]];
	*/
	
	/* 
	
	NSArray class reference: http://www.gnustep.org/resources/documentation/Developer/Base/Reference/NSArray.html#method$NSMutableArray-sortUsingComparator$ 
	
	it seems that the sortUsingComparator: is part of the NSArray class references. 
	
	*/
	 
	/*
	
	if you check the header files, you will find that there is no such definitions as sortUsingComparator: instead, it has a 
		sortUsingFunction
	
	[self.book sortUsingComparator: ^(id obj1, id obj2) { 
		return [[obj1 name] compare: [obj2 name]];
	}];
	
	This makes sense, because the GNUStep does not support blocks by default.
	*/
	
	NSComparisonResult (* comparator)(id obj1, id obj2, void * context) = _anonymouse_comparefunction;
	[self.book sortUsingFunction: comparator context: NULL];
}

NSComparisonResult _anonymouse_comparefunction(id obj1, id obj2, void * context)
{
	return [[obj1 name] compare: [obj2 name]];
}


-(void) encodeWithCoder: (NSCoder *) encoder
{
	[encoder encodeObject: self.bookName forKey: @"AddessBookBookName"];
	[encoder encodeObject: self.book forKey: @"AddessBookBook"];
}

-(id) initWithCoder: (NSCoder *) decoder
{
	self.bookName = [decoder decodeObjectForKey: @"AddessBookBookName"];
	self.book = [decoder decodeObjectForKey: @"AddessBookBook"];
	
	return self;
}

@end