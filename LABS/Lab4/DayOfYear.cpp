/************************************************************************************
*             This is an implementation file for the DayOfYear class                *
*	                   that determines what this class does.                        *
*************************************************************************************/
#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include"DayOfYear.h"//'DayOfYear' class definition
using namespace std;

/************************************************************************************
*							   DayOfYear.h Static Data Members		                *
*************************************************************************************/
string DayOfYear::monthNames[] = {"January", "February", "March", "April", "May", 
								  "June", "July", "August", "September", "October", 
	                              "November", "December"};
int DayOfYear::daysOfMonth[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
/************************************************************************************/

/************************************************************************************
*							   DayOfYear.h Member Functions			                *
*************************************************************************************/
/**
 * This public member function finds the month and day value(s) that correspond to
 * the day of the year passed to the constructor as user input.
 *
 * @param day -- integer value for the 'dayOfYear' user input
 * @return 'none' -- void
 */
void DayOfYear::findMonthAndDay(int day) {
	//Index variable for iterating through the loop
	int monthVal = 0;
	//Loop until the end day of the current month is less than the entered day of the year
	while (daysOfMonth[monthVal] < day) {
		monthVal++;
	}
	//Use the index variable to get the corresponding day and month from the static arrays
	month += monthNames[monthVal-1];
	dayOfMonth += dayOfYear - daysOfMonth[monthVal-1];
}
/**
 * This public 'friend function' that is a friend of the DayOfYear class prints to 
 * the screen the month-day formatted day passed to the constructor that the user 
 * gave as input.
 *
 * @param day -- DayOfYear class object
 * @return none -- void
 */
void print(DayOfYear day) {
	//Call the findMonthAndDay() function to find the month and day values
	day.findMonthAndDay(day.dayOfYear);
	//Output the day of the year (user input) converted to the month day format
	cout << "\nDay " << day.dayOfYear << " would be "
	     << day.month << " " << day.dayOfMonth << endl;
}
/*************************************************************************************/