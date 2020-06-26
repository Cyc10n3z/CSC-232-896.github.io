/*------------------------------------------------------------------------------------
 * Author:        Carlos Izaguirre and John Lorette III
 * Date:          6/23/2020
 * Trace Folder:  LABS\Lab5\
 * File Name:     testShip.cpp, Ship.h, Ship.cpp, CruiseShip.h, 
 *                CruiseShip.cpp, CargoShip.h, CargoShip.cpp
 * Description:   C++ Program demonstrates the use of three 'Ship' classes.
 ------------------------------------------------------------------------------------*/
#include<iostream>
#include<iomanip>
#include"Ship.h"//'Ship' class definition
#include"CruiseShip.h"//'CruiseShip' class definition
#include"CargoShip.h"//'CargoShip' class definition
using namespace std;

/************************************************************************************
*                 The programs main method, or control function                     *
*************************************************************************************/
int main() {
    //Variable(s) for Dynamically Allocated Memory for an array of pointers, that point to derived class objects
    const int NUM_SHIPS = 3;
    Ship *ships[NUM_SHIPS] = {new Ship("Santa Maria", 1460), 
                              new CruiseShip("Royal Princes", 3600), 
                              new CargoShip("Panamax", 52500)};
    
    //Loop through the array of pointers and call the 'print()' function for each derived 'Ship' class object
    for(int i = 0; i < NUM_SHIPS; i++){
        ships[i]->print();
    }
    cout << endl << endl;

    //Release the dynamically allocated memory for each array element and then the array itself
    delete ships[0];
    ships[0] = nullptr;
    delete ships[1];
    ships[1] = nullptr;
    delete ships[2];
    ships[2] = nullptr;
    delete [] *ships;
    //Exit the main function, with 0 indicating success
    return 0;
}