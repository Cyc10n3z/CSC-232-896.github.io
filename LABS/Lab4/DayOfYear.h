/************************************************************************************
*             This is a specification file for the DayOfYear class                  *
*	                   that determines what this class does.                        *
*************************************************************************************/
#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
#include<iostream>
#include<iomanip>
#include<string>

/************************************************************************************
*         DayOfYear Class Declaration: Data Members and Inline Functions            *
*************************************************************************************/
class DayOfYear
{
	private:
		int dayOfMonth, dayOfYear;//The integer value for a day of the month and year
		string month;//The string value for a month
	
	public:
		//Default and Overloaded Constructors
		DayOfYear(){};
		DayOfYear(int input)
		{dayOfYear = input;}
		//Member Functions
		void findMonthAndDay();
		friend void print(DayOfYear);
};
#endif
