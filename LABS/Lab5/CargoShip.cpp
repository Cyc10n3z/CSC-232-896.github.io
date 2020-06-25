/************************************************************************************
*             This is an implementation file for the Ship class                     *
*	                   that determines what this class does.                        *
*************************************************************************************/
#include<iostream>
#include"CargoShip.h"//'CargoShip' class definition
using namespace std;

/************************************************************************************
*						   CargoShip.h Member Functions		    	                *
*************************************************************************************/
/**
 * This member function overrides the 'print()' virtual function in the base class
 * 
 * @param none
 * @return none -- void
 */
void CargoShip::print(){
    //Print the base class ship name string and the derived class capacity value
    cout << "\nThe cargo ship " << getName() 
         << " has a maximum capacity of " << capacity << " tons";
}
/************************************************************************************/