package org.boqwang.syntax.switchstrings;

public class SwitchStrings {
	public static void main(String[] args) {
		System.out.println(new SwitchStrings().getTypeOfDayWithSwitchStatement("Monday"));
	}
	
	public String getTypeOfDayWithSwitchStatement(String dayOfWeekArg) {
		String typeOfDay;
		switch (dayOfWeekArg) {
        case "Monday":
            typeOfDay = "Start of work week";
            break;
        case "Tuesday":
        case "Wednesday":
        case "Thursday":
            typeOfDay = "Midweek";
            break;
        case "Friday":
            typeOfDay = "End of work week";
            break;
        case "Saturday":
        case "Sunday":
            typeOfDay = "Weekend";
            break;
        default:
        	throw new IllegalArgumentException("Invalid day of the week: " + dayOfWeekArg);
		}
		return typeOfDay;
	}
}
