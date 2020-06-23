/*------------------------------------------------------------------------------------
* Author:        Carlos Izaguirre and John Lorette III
* Date:          6/23/2020
* Trace Folder:  LABS\lab4\
* File Name:     Lab3_Izaguirre_Carlos_LoretteIII_John.cpp, DayOfYear.h
* Description:   C++ Program that uses a class named 'DayOfYear' to output a "month-day" 
*				  date formatted string based on a user's specific integer input.
-------------------------------------------------------------------------------------*/
#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include"DayOfYear.h"//DayOfYear class definition
using namespace std;

/************************************************************************************
*							   DayOfYear.h Member Functions			                *
*************************************************************************************/
void DayOfYear::findMonthAndDay(){


}
void DayOfYear::print(DayOfYear days){
	//Print an error message if the user's input is invalid
	if (days < 1 || days > 365)
		cout << "Error! Value must be between 1 and 365. Try again.";
}
/***********************************************************************************

//Function Prototypes
//...

/************************************************************************************
*                 The programs main method, or control function                     *
*************************************************************************************/
int main() {
	//Variable(s) for use on a 'DayOfYear' class object
	DayOfYear testYear;
	int userEntry = 0;

	//Ask the user for integer input
	cout << "------------------------------------------------------------------------\n";
	cout << "Enter an integer between 1 and 365 for the day of the year: ";
	cin >> userEntry;
	//Validate user input
	while (userEntry != sizeof(short) || userEntry < 1 || userEntry > 365) {
		//
		cout << "------------------------------------------------------------------------\n";
		cout << "Error! The value must be between 1 and 365. Try again.";
		cout << "Enter an integer between 1 and 365 for the day of the year: ";
		cin >> userEntry;
		cout << "------------------------------------------------------------------------\n";
	}
	testYear = userEntry;
	DayOfYear::print(testYear);//Call the 'DayOfYear::print()' function
	cout << "------------------------------------------------------------------------\n";

	//Exit the main function, with 0 indicating success
	return 0;
}