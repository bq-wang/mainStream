import java.util.Stack;


/* the reference link to this page is availabe here : 
 * 
 * leetcode.com/2011/08/reverse-bits.html 
 */

@FunctionalInterface
interface Command
{
	void doWork();
}

public class FunctionInterfaceDemo {
	public static void main(String[] args)
	{
		// you can either using a inner interface implemenation 
		carryOutWork(new Command() { 
				@Override
				public void doWork() { 
					System.out.println("Do work ni SimpleFun impl...");
				}
			});
		
		// or you can use the new Java 8 lambda, which shows like below.
		carryOutWork(() -> System.out.println("Do work in lambda exp impl..."));
		
	}
	
	public static void carryOutWork(Command cmd) {
		cmd.doWork();
	}
	
}
