/*------------------------------------------------------------------------------------
 * Author:        Carlos Izaguirre and John Lorette III
 * Date:          6/23/2020
 * Trace Folder:  LABS\Lab4\
 * File Name:     Lab4_Izaguirre_Carlos_LoretteIII_John.cpp, DayOfYear.h
 * Description:   C++ Program that uses a class named 'DayOfYear' to output a "month-day" 
 *				  date formatted string based on a user's specific integer input.
 ------------------------------------------------------------------------------------*/
#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include"DayOfYear.h"//DayOfYear class definition
using namespace std;

/************************************************************************************
*                 The programs main method, or control function                     *
*************************************************************************************/
int main() {
	//Variable(s) used for input from a user
	int userEntry = 0;

	//Ask the user for integer input
	cout << "------------------------------------------------------------------------\n";
	cout << "Enter the day of the year as an integer, between 1 and 365: ";
	cin >> userEntry;
	//Validate user input
	while (userEntry < 1 || userEntry > 365) {
		//
		cout << "------------------------------------------------------------------------\n";
		cout << "Error! The value must be between 1 and 365. Try again.";
		cout << "Enter the day of the year as an integer, between 1 and 365: ";
		cin >> userEntry;
		cout << "------------------------------------------------------------------------\n";
	}
	//Create a DayOfYear class object
	DayOfYear testYear(userEntry);
	//   ???
	testYear.set_endDaysOfMonths();
	testYear.set_monthNames();
	//Call the friend function to the class DayOfYear named 'print()', to display/print the month-day format
	print(testYear);
	cout << "------------------------------------------------------------------------\n";

	//Exit the main function, with 0 indicating success
	return 0;
}