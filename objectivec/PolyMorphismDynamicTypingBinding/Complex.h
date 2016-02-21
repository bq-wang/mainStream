// Complex.h

#import <Foundation/Foundation.h>

@interface Complex: NSObject
{
	double real, imaginary;
}
@property double real, imaginary;


-(void) print;
-(void) setReal: (double) a andImaginary: (double) b;
-(Complex *) add: (Complex *) f;

@end


