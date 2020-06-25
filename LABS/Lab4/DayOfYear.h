/************************************************************************************
*             This is a specification file for the DayOfYear class                  *
*	                   that determines what this class does.                        *
*************************************************************************************/
#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
#include<iostream>
using namespace std;

/************************************************************************************
*         DayOfYear Class Declaration: Data Members and Inline Functions            *
*************************************************************************************/
class DayOfYear
{
	private:
		int dayOfMonth = 0, dayOfYear = 0;//The integer values for a day of the month and year
		string month = "";
		//Static member variables used for all class objects created
		static string monthNames[12];//Array for holding the string name/value for each month for a full year
		static int daysOfMonth[13];//Array for holding the last day of the month for a full year
	public:
		//Default and Overloaded Constructors
		DayOfYear(){}
		DayOfYear(int d)
		{dayOfYear = d;}
		//Member Functions
		void findMonthAndDay(int);
		friend void print(DayOfYear);
};
#endif
