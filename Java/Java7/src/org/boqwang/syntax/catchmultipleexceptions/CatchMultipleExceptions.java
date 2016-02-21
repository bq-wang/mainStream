package org.boqwang.syntax.catchmultipleexceptions;

import java.io.IOException;
import java.sql.SQLException;

/*
check: 

Catching Multiple Exception Types and Rethrowing Exceptions with Improved Type C: http://docs.oracle.com/javase/7/docs/technotes/guides/language/catch-multiple.html
 
 */

public class CatchMultipleExceptions {
	public static void oldStyleThrowStatements() throws Exception {
		try {
			throwsSQLException();
			throwsIOException();
		} catch (IOException ex) {
		     // logger.log(ex);
		     throw ex;
		} catch (SQLException ex) {
		     // logger.log(ex);
		     throw ex;
		}
	}
	
	public static void catchMultipleAndRethrowStatements() throws Exception { 
		try {
			throwsSQLException();
			throwsIOException();
		} catch (IOException | SQLException ex) {
			// logger.log(ex);
		     throw ex;
		}
	}
	
	private static void throwsSQLException() throws SQLException {
		throw new SQLException();
	}
	private static void throwsIOException() throws IOException { 
		throw new IOException();
	}
	
	static class FirstException extends Exception { }
	static class SecondException extends Exception { }
	
	public void rethrowException(String exceptionName) throws Exception { 
		try {
			if (exceptionName.equals("First")) {
				throw new FirstException();
			} else { 
				throw new SecondException();
			}
		} catch (Exception e) { 
			throw e;
		}
	}
	
	/*
	 Java 7 compiler does more type check, and you can throw more accurate exceptions in the throws statement.
	 
	 However, in Java SE 7, you can specify the exception types FirstException and SecondException in the throws clause in the rethrowException method declaration. 
	 
	 The Java SE 7 compiler can determine that the exception thrown by the statement throw e must have come from the try block, and the only exceptions thrown by the try block can be FirstException and SecondException. Even though the exception parameter of the catch clause, e, is type Exception, the compiler can determine that it is an instance of either FirstException or SecondException:
	 
	 */
	public void rethrowExceptionInMoreRefinedManner(String exceptionName) throws FirstException, SecondException { 
		try {
			if (exceptionName.equals("First")) {
				throw new FirstException();
			} else { 
				throw new SecondException();
			}
		} catch (Exception e) { 
			throw e;
		}
	}
	
	/*
	 In detail, in Java SE 7 and later, when you declare one or more exception types in a catch clause, and rethrow the exception handled by this catch block, the compiler verifies that the type of the rethrown exception meets the following conditions:

* The try block is able to throw it.
* There are no other preceding catch blocks that can handle it.
* It is a subtype or supertype of one of the catch clause's exception parameters.

In releases prior to Java SE 7, you cannot throw an exception that is a supertype of one of the catch clause's exception parameters. A compiler from a release prior to Java SE 7 generates the error, "unreported exception Exception; must be caught or declared to be thrown" at the statement throw e.
The compiler checks if the type of the exception thrown is assignable to any of the types declared in the throws clause of the rethrowException method declaration. However, the type of the catch parameter e is Exception, which is a supertype, not a subtype, of FirstException andSecondException.
	 */
	
}
