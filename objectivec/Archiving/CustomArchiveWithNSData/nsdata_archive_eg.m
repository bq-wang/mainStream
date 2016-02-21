// nsdata_archive_eg.m

#import "AddressBook.h"
#import "Foo.h"

int main(int argc, char *argv[])
{
	@autoreleasepool { 
	
		NSData *dataArea;
		NSKeyedUnarchiver *unarchiver;
		Foo *myFoo1;
		AddressBook *myBook;
		// Read in the archive and connect an
		// NSKeyedUnarchiver object to it
		dataArea = [NSData dataWithContentsOfFile: @"myArchive"];
		if (! dataArea) {
			NSLog (@"Can't read back archive file!");
			return 1;
		}
		
		/* the key is to create the NSData as the carrier of the data 
		the initialized archiver then is used to archive and unarchive data */
		
		
		unarchiver = [[NSKeyedUnarchiver alloc]
			initForReadingWithData: dataArea];
		// Decode the objects we previously stored in the archive
		myBook = [unarchiver decodeObjectForKey: @"myaddrbook"];
		myFoo1 = [unarchiver decodeObjectForKey: @"myfoo1"];
		[unarchiver finishDecoding];
	
		// Verify that the restore was successful
		[myBook list];
		NSLog (@"%@\n%i\n%g", [myFoo1 strVal],
		[myFoo1 intVal], [myFoo1 floatVal]);
	
	}
	return 0;
}