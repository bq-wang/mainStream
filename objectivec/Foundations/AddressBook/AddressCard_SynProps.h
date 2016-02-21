#import <Foundation/Foundation.h>

@interface AddressCard: NSObject
//*/
{
	NSString *_name;
	NSString *_email;

	//NSString *name;
	//NSString *email;
}
//*/
/*

Actually it has been  argued here : Synthesized Properties and ivar error - http://stackoverflow.com/questions/10476385/synthesized-properties-and-ivar-error

it is advised to set

	NSString *_name;
	NSString *_email;

and in the implementaion partts, you should just do this:

	@synthesize name = _name;
	@synthesize email = _email;

and when you use it, you will need to qualify the call to name and email with 'self'

such as

	NSLog (@"| %-31s |", [self.name UTF8String]);
	NSLog (@"| %-31s |", [self.email UTF8String]);
 */

@property (copy, nonatomic) NSString *name, *email;
-(void) print;
-(void) setName: (NSString *) theName andEmail: (NSString *) theEmail;

// compare the two names from teh specified address code
-(NSComparisonResult) compareNames: (id) element;
@end
