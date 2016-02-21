// mutablecopy_eg.m

#import <Foundation/Foundation.h>

int main(int argc, char * argv[])
{
    @autoreleasepool { 
 		NSMutableArray *dataArray =[NSMutableArray arrayWithObjects: 
 			@"one", @"two", @"three", @"four", nil];
 			
 			
 			
 		NSMutableArray *dataArray2;
 		
 		// Simple assignment
 		dataArray2 = dataArray;
 		[dataArray2 removeObjectAtIndex: 0];
 		
 		NSLog(@"dataAray: ");
 		for (NSString *elem in dataArray)  {
 			NSLog(@"      %@", elem);
 		}
 		
 		NSLog(@"dataAray2: ");
 		for (NSString *elem in dataArray2)  {
 			NSLog(@"      %@", elem);
 		}

 		
 		// try a copy, then remove the first element from the copy
 		dataArray2 = [dataArray mutableCopy];
 		[dataArray2 removeObjectAtIndex: 0];
 		
 		
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