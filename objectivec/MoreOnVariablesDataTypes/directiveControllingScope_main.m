// directiveControllingScope_main.m

// You can put four directives in front of your instance variables when they are declared in the interface section, to more precisely control their scope:

/*

@protected！ Methods defined in the class and any subclasses can directly access the instance variables that follow.This is the default for instance variables defined in the interface section.

@private！ Methods defined in the class can directly access the instance variables that follow, but subclasses cannot.This is the default for instance variables defined in the implementation section.

@public！ Methods defined in the class and any other classes or modules can directly access the instance variables that follow.

@package！ For 64-bit images, the instance variable can be accessed anywhere within the image that implements the class.

*/


/*

please check the code here in the Printer.h definitions 

*/

