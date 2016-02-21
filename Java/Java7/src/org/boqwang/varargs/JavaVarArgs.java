package com.bqwang.varargs;

import static java.lang.System.out;

public class JavaVarArgs {
	public static void main(String[] args){
		JavaVarArgs jvargs = new JavaVarArgs();
		jvargs.logMessage("Format string", "first arg", "second arg", "third arg");
		// jvargs.logMessage2("format string", "first arg", "second arg", "third arg");
		jvargs.logMessage2("format a string", new Object[] { "first arg", "second arg", "third arg" });
	}
	
	private void logMessage(String fmt, Object ... params)
	{
		if (fmt == null) throw new NullPointerException("fmt");
		
		out.println("==============");
		out.println("format is ");
		out.println(fmt);
		int idx = 0;
		for (Object arg : params) { 
			out.print("" + (idx++) + arg);
		}
	}
	
	private void logMessage2(String fmt, Object[] params)
	{
		if (fmt == null) throw new NullPointerException("fmt");
		
		out.println("==============");
		out.println("format is ");
		out.println(fmt);
		int idx = 0;
		for (Object arg : params) { 
			out.print("" + (idx++) + arg);
		}
	}
}
