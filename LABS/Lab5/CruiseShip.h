/************************************************************************************
*           This is a specification file for the 'CruiseShip' class                 *
*	                   that determines what this class does.                        *
*************************************************************************************/
#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include<iostream>
#include<string>
#include"Ship.h"
using namespace std;

/************************************************************************************
*         CruiseShip Class Declaration: Data Members and Inline Functions           *
*************************************************************************************/
class CruiseShip : public Ship
{//'CruiseShip' extends the base 'Ship' class
	private:
        //Data Member containing the maximum number of passengers allowed
        int maxPassengers;
    public:
        //Default and Overloaded Constructors
        CruiseShip() {
            setName("");
            maxPassengers = 100;
        }
        CruiseShip(string n, int people) {
            setName(n);
            maxPassengers = people;
        }
        ~CruiseShip(){}//Default Destructor
        //Accessor and Mutator Member Functions
        int getMaxPeople() const {
            return maxPassengers;
        }
        void setMaxPeople(int people) {
            maxPassengers = people;
        }
        //'print()' Function that overrides the base class 'print()' Function
        virtual void print();
};
#endif