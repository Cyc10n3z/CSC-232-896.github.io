/************************************************************************************
*             This is a specification file for the DayOfYear class                  *
*	                   that determines what this class does.                        *
*************************************************************************************/
#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

/************************************************************************************
*         DayOfYear Class Declaration: Data Members and Inline Functions            *
*************************************************************************************/
class DayOfYear
{
private:
	int dayOfMonth, dayOfYear;//The integer value for a day of the month and year
	string month;//The string value for the month of the year
	//Static member variables required for storing the month-day results
	static string monthNames[];//Array for holding the string name/value for each month for a full year
	static int endDaysOfMonths[];//Array for holding the last day of the month for a full year

public:
	//Default and Overloaded Constructors
	DayOfYear(){}
	DayOfYear(int input)
	{dayOfYear = input;}
	void findMonthAndDay();
	friend void print(DayOfYear);
	//Mutator functions for interacting with private static data members
	static void set_endDaysOfMonths();
	static void set_monthNames();
};
#endif
