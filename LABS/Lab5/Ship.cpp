/************************************************************************************
*             This is an implementation file for the Ship class                     *
*	                   that determines what this class does.                        *
*************************************************************************************/
#include<iostream>
#include "Ship.h"//'Ship' class definition
using namespace std;

/************************************************************************************
*							   DayOfYear.h Member Functions			                *
*************************************************************************************/
/**
 * This virtual member function prints to the screen a ship's name and year it was built.
 * 
 * @param none
 * @return none -- void
 */
void Ship::print(){
     //Output each "Ship" object in the dynamic array by calling each object's 'print()' function
    cout << "\nThe ship " << name << " was built in the year " << buildYear;
}
/************************************************************************************/