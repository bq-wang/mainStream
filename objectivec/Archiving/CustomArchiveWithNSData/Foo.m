#import "Foo.h"

@implementation Foo
@synthesize strVal, intVal, floatVal;
-(void) encodeWithCoder: (NSCoder *) encoder
{
	[encoder encodeObject: strVal forKey: @"FoostrVal"];
	[encoder encodeInt: intVal forKey: @"FoointVal"];
	[encoder encodeFloat: floatVal forKey: @"FoofloatVal"];
}
-(id) initWithCoder: (NSCoder *) decoder
{
	strVal = [decoder decodeObjectForKey: @"FoostrVal"];
	intVal = [decoder decodeIntForKey: @"FoointVal"];
	floatVal = [decoder decodeFloatForKey: @"FoofloatVal"];
	return self;
}
@end