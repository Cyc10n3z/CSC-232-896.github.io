/************************************************************************************
*               This is a specification file for the Ship class                     *
*	                   that determines what this class does.                        *
*************************************************************************************/
#ifndef SHIP_H
#define SHIP_H
#include<iostream>
using namespace std;

/************************************************************************************
*            Ship Class Declaration: Data Members and Inline Functions              *
*************************************************************************************/
class Ship
{//Base class 'Ship'
	private:
        //Data members containing details for each 'Ship' class object
        string name;
        int buildYear;
    public:
        //Default and Overloaded Constructors
        Ship() {
            name = "";
            buildYear = 0;
        }
        Ship(string n, int year){
            name = n; 
            buildYear = year;
        }
        virtual ~Ship(){}//Virtual Destructor
        //Accessor and Mutator Member Functions
        string getName() const {
            return name;
        }
        int getBuildYear() const {
            return buildYear;
        }
        void setName(string n) {
            name = n;
        }
        void setBuildYear(int year) {
            buildYear = year;
        }
        //Virtual Function
        virtual void print();
};
#endif