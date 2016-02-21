// askQuestionAboutClasses_main.m

/*
you might ask question about classes. 

	1. Is this object a rectangle
	2. Does this object support a print methods?
	3. Is this a mmeber of the Graphics class or one of its descendants?

Table 9.1 Methods for Working with Dynamic Types

Method Question or Action
-(BOOL) isKindOfClass: class-object 										Is the object a member of class-object or a descendant?
-(BOOL) isMemberOfClass: class-object 										Is the object a member of class-object?
-(BOOL) respondsToSelector: selector 										Can the object respond to the method specified by selector?
+(BOOL) instancesRespondToSelector:selector 								Can instances of the specified class respond to selector?
+(BOOL)isSubclassOfClass:class-object										Is the object a subclass of the specified class?
-(id) performSelector: selector 											Apply the method specified by selector.
-(id) performSelector: selector	withObject: object							Apply the method specified by selector passing the argument object.
-(id) performSelector: selector withObject: object1 withObject: object2		Apply the method specified by selector with the arguments object1 and object2


Other methods are not covered here. One enables you to ask whether an object conforms to a protocol (see Chapter 11,¡°Categories and Protocols¡±). Others enable you to 
ask about dynamically resolving methods (not covered in this text).



NOTE: a class-object is a class object (typically generated with the class method), and selector is a value of type SEL (typically created with the @selector directive).
*/

/*

to generate a class object from a classs or another object, you send it the class message, so to get a class from a classs named Square, you write the following:

[Square class];

if ([obj1 class] == [obj2 class]) 
...


To seee if the variable myFract is a Fraction class object, you teswt result from the expression, like this: 

[myFrac isMemberOfClass: [Fraction class]]

*/


/*

to generate a class object from a classs or another object, you send it the class message, so to get a class from a classs named Square, you write the following:

[Square class];

*/


/*

To generate one of the so-called selectors

For example, the following produces a value of type SEL for
the method named alloc, which you know is a method inherited from the NSObject class:

@selector (alloc)

or you can setTo:over: method that you implemented in your Fraction class (remember those colon characters in the method names):

@selector (setTo:over:)

to see whether  an instance of the Fraction class responds to the setTo:over: method, you can test the return value from the expression, like this: 

[Fraction instancesRespondToSelector: @selector (setTo:over:)]

Remember, the test covers inherited methods, not just one that is directly defined in the class definition.


the performSelector: method and its variants (not shown in Table 9.1) enable you to send a message to an object, where the message can be a selector inside a variable., e.g. 
SEL action;
id   graphicObject; 
...
action = @selector(draw);
...
[graphicObject performSelector: action];

if ([grahicObject repondsToSelector: action] == YES)
	[graphicObject performSelector: action]
else 
	// error handling code here.

*/


#import "Square.h"

int main(int argc, char* argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	Square *mySquare = [[Square alloc] init];
	
	// is member of 
	if ( [mySquare isMemberOfClass: [Square class]] == YES )
		NSLog (@"mySquare is a member of Square class");
	if ( [mySquare isMemberOfClass: [MyRectangle class]] == YES )
		NSLog (@"mySquare is a member of Rectangle class");
	if ( [mySquare isMemberOfClass: [NSObject class]] == YES )
		NSLog (@"mySquare is a member of NSObject class");

	// isKindOf:
	
	if ( [mySquare isKindOfClass: [Square class]] == YES )
		NSLog (@"mySquare is a kind of Square");
	if ( [mySquare isKindOfClass: [MyRectangle class]] == YES )
		NSLog (@"mySquare is a kind of Rectangle");
	if ( [mySquare isKindOfClass: [NSObject class]] == YES )
		NSLog (@"mySquare is a kind of NSObject");


	// a NOTE; you can always use the class name directly as the receiver in a message expression, and you don't have to write 
	// this in the expression "[Square class].
	// NOTE: only when the class name is used as the Receiver of the message, not when it is used as message.. 
	if ( [ Square respondsToSelector: @selector(alloc)] == YES)
	{
		NSLog (@"Square has the class method 'alloc'");
	}
	
	if ( [[Square class] respondsToSelector: @selector(alloc)] == YES)
	{
		NSLog(@"Square has the class method 'alloc'");
	}



	// respondsTo:
	if ( [mySquare respondsToSelector: @selector (setSide:)] == YES )
		NSLog (@"mySquare responds to setSide: method");
	if ( [mySquare respondsToSelector: @selector (setWidth:andHeight:)] == YES )
		NSLog (@"mySquare responds to setWidth:andHeight: method");
	if ( [Square respondsToSelector: @selector (alloc)] == YES )
		NSLog (@"Square class responds to alloc method");

	// instancesRespondTo:
	if ([MyRectangle instancesRespondToSelector: @selector (setSide:)] == YES)
		NSLog (@"Instances of Rectangle respond to setSide: method");
	if ([Square instancesRespondToSelector: @selector (setSide:)] == YES)
		NSLog (@"Instances of Square respond to setSide: method");
	if ([Square isSubclassOfClass: [MyRectangle class]] == YES)
		NSLog (@"Square is a subclass of a rectangle");

	[pool drain];
	
	return 0;
	
}