/************************************************************************************
*          This is a specification file for the 'CargoShip' class                   *
*	                   that determines what this class does.                        *
*************************************************************************************/
#ifndef CARGOSHIP_H
#define CARGOSHIP_H
#include<iostream>
#include<string>
#include"Ship.h"
using namespace std;

/************************************************************************************
*          CargoShip Class Declaration: Data Members and Inline Functions           *
*************************************************************************************/
class CargoShip : public Ship
{//'CargoShip' extends the base 'Ship' class
	private:
        //Data Member containing the cargo capacity (in tonnage)
        int capacity;
    public:
        //Default and Overloaded Constructors
        CargoShip() {
            setName("");
            capacity = 1000;
        }
        CargoShip(string n, int c) {
            setName(n);
            capacity = c;
        }
        ~CargoShip(){}//Default Destructor
        //Accessor and Mutator Member Functions
        int getCapacity() const {
            return capacity;
        }
        void setCapacity(int c) {
            capacity = c;
        }
        //'print()' Function that overrides the base class 'print()' Function
        virtual void print();
};
#endif