// AddressCard.h

#import <Foundation/Foundation.h>
@interface AddressCard: NSObject
//*/
{
	NSString *name;
	NSString *email;
}
//*/


/*
lists the attributes copy and nonatomic for the properties.The copy attribute says to
make a copy of the instance variable in its setter method, as you did in the version you
wrote.The default action is to not make a copy, but to instead perform a simple assignment
(that¡¯s the default attribute assign), an incorrect approach in this case, as we recently
discussed.

The nonatomic attribute says that you don¡¯t need to worry about race conditions that
could occur from multiple threads trying to access the instance variable at the same time.

*/
@property (copy, nonatomic) NSString *name, *email;

-(void) print;
-(void) setName: (NSString *) theName andEmail: (NSString *) theEmail;
@end
