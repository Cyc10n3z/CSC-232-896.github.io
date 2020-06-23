/************************************************************************************
*             This is an implementation file for the DayOfYear class                *
*	                   that determines what this class does.                        *
*************************************************************************************/
#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include"DayOfYear.h"//DayOfYear class definition
using namespace std;

/************************************************************************************
*							   DayOfYear.h Static Data Members		                *
*************************************************************************************/
string DayOfYear::monthNames[13] = {""};
int DayOfYear::endDaysOfMonths[13] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
/************************************************************************************/

/************************************************************************************
*							   DayOfYear.h Member Functions			                *
*************************************************************************************/
/**
	This public member function finds the month and day value(s) that correspond to
	the day of the year passed to the constructor as user input.

	@param -- 
	@return 'none' -- void
*/
void DayOfYear::findMonthAndDay() {


}
/**
	This public 'friend function' that is a friend of the DayOfYear class prints to 
	the screen the month-day formatted day passed to the constructor that the user 
	gave as input.

	@param days -- DayOfYear class object
	@return none -- void
*/
void print(DayOfYear days) {
	//Variable(s) for iterating through an array
	int monthValue = 0;

	//Loop until the end day of the month is less than the input entered by the user
	while (days.endDaysOfMonths[monthValue] < days.dayOfYear) {
		monthValue++;
	}
	//Get the corresponding day and month from the private array data members
	days.month += days.monthNames[monthValue-1];
	days.dayOfMonth += days.dayOfYear - days.endDaysOfMonths[monthValue-1];
	//Outout the day of the year (user input) converted to the month day format
	cout << "\nDay " << days.dayOfYear << " would be: ";
	cout << days.month << " " << days.dayOfMonth << endl;
}
/**
	This public member function 'sets' the day values for each day at the end of
	the month into the variable 'endDayOfMonths', for the 'DayOfYear' Class. 

	@param none -- 
	@return none -- void
*/
void DayOfYear::set_endDaysOfMonths() {
	//Fill/set the array with the corresponding int values for the end day of the month
	endDaysOfMonths[] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
	
}
/**
	This public member function 'sets' the month string values for each month into
	the variable 'monthArray', for the 'DayOfYear' Class.

	@param none --
	@return none -- void
*/
void DayOfYear::set_monthNames() {
	//Fill/set the array with the corresponding string values for each month
	monthNames[0] = "January";
	monthNames[1] = "February";
	monthNames[2] = "March";
	monthNames[3] = "April";
	monthNames[4] = "May";
	monthNames[5] = "June";
	monthNames[6] = "July";
	monthNames[7] = "August";
	monthNames[8] = "September";
	monthNames[9] = "October";
	monthNames[10] = "November";
	monthNames[11] = "December";
}
/*************************************************************************************/