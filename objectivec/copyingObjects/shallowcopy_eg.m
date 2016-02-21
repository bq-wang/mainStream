// shallowcopy_eg.m

#import <Foundation/Foundation.h>

int main(int argc, char * argv[])
{
    @autoreleasepool { 
 		NSMutableArray *dataArray =[NSMutableArray arrayWithObjects: 
 			[NSMutableString stringWithString: @"one"],
 			[NSMutableString stringWithString: @"two"],
 			[NSMutableString stringWithString: @"three"],
 			nil];
 		
 		NSMutableArray *dataArray2;
 		NSMutableString *mStr;

 		// try a copy, then remove the first element from the copy
 		dataArray2 = [dataArray mutableCopy];
 		mStr = [dataArray2 objectAtIndex: 0];
 		
 		[mStr appendString: @"ONE"];
 		
 		NSLog(@"dataArray: ");
 		for (NSString *elem in dataArray)  {
 			NSLog(@"      %@", elem);
 		}
 		
 		NSLog(@"dataAray2: ");
 		for (NSString *elem in dataArray2)  {
 			NSLog(@"      %@", elem);
 		}
    }
    
    return 0;
}