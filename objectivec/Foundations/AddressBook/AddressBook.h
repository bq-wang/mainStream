/* AddressBook.h */

#import <Foundation/Foundation.h>
#import "AddressCard_SynProps.h"

@interface AddressBook: NSObject
{
	NSString *_bookName;
	NSMutableArray *_book;
}

@property (nonatomic, copy) NSString *bookName;
@property (nonatomic, strong) NSMutableArray *book;


-(id) initWithName: (NSString *) name;
-(void) addCard: (AddressCard *) theCard;
-(int) entries;
-(void) list;
-(AddressCard *) lookup: (NSString *) theName;
-(void) sort;

@end
