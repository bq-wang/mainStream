// AddressBook.h


#import <Foundation/Foundation.h>
#import "AddressCard_SynthProps.h"

@interface AddressBook: NSObject
//*/
{
	NSString *bookName;
	NSMutableArray *book;
}
//*/

/*
The strong attribute for a property It is described in more detail in Chapter 17,
¡°Memory Management and Automatic Reference Counting.¡±

 */
@property (nonatomic, copy) NSString *bookName;
@property (nonatomic, strong) NSMutableArray *book;
-(id) initWithName: (NSString *) name;
-(void) addCard: (AddressCard *) theCard;
-(NSUInteger) entries;
-(void) list;

/* Section Sorting */
-(void) sort;
/* - End Section */
@end
