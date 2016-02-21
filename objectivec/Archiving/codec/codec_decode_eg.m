// addressbook_nscopy_eg.m

#import "AddressBook.h"
int main(int argc, char * argv[])
{
	@autoreleasepool { 
		AddressBook *myBook;
		myBook = [NSKeyedUnarchiver unarchiveObjectWithFile: @"addrbook.arch"];
		
		[myBook list];
	}
	return 0;
}