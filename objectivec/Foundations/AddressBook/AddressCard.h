#import <Foundation/Foundation.h>

@interface AddressCard: NSObject
//*/
{
	NSString *name;
	NSString *email;
}
//*/

-(void) setName: (NSString *) theName;
-(void) setEmail: (NSString *) theEmail;
-(NSString *) name;
-(NSString *) email;
-(void) print;

@end
