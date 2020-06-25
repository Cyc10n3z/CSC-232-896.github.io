/************************************************************************************
*          This is an implementation file for the 'CruiseShip' class                *
*	                   that determines what this class does.                        *
*************************************************************************************/
#include<iostream>
#include"CruiseShip.h"//'CruiseShip' class definition
using namespace std;

/************************************************************************************
*					      CruiseShip.h Member Functions			                    *
*************************************************************************************/
/**
 * This member function overrides the 'print()' virtual function in the base class
 * 
 * @param none
 * @return none -- void
 */
void CruiseShip::print(){
    //Output the base class ship name string and the derived class passengers value
    cout << "\nThe cruise ship " << getName() 
         << " can have a maximum of " << maxPassengers << " passengers";
}
/************************************************************************************/