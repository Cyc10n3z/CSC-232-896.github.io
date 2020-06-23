/*------------------------------------------------------------------------------------
 * Author:        Carlos Izaguirre and John Lorette III
 * Date:          6/18/2020
 * Trace Folder:  LABS\lab3\
 * File Name:     Lab3_Izaguirre_Carlos_LoretteIII_John.cpp, Circle.h
 * Description:   C++ Program that demonstrates the use and behavior of a Circle class.
 *				  Included is the Circle specification file.
 ------------------------------------------------------------------------------------*/
#include<iostream>
#include<iomanip>
#include<string>
#include "Circle.h"//Circle class definition
using namespace std;

/************************************************************************************
*							   Circle.h Member Functions			                *
*************************************************************************************/
Circle::Circle(): radius(0.0)//Default Constructor
{
}
Circle::Circle(double r)//Overloaded Constructor
{
	radius = r;
}
//Member mutator function definition for 'setRadius'
void Circle::setRadius(double r) {
	if (r >= 0) {
		radius = r;
	}
	else {
		cout << "That is an invalid radius.\n";
		exit(EXIT_FAILURE);
	}
}
/***********************************************************************************/

//Function Prototypes
//...

/************************************************************************************
*                 The programs main method, or control function                     *
*************************************************************************************/
int main() {
	//Class object instantiation for demonstrating the Circle class
	Circle c1, c2(12.5);
	double r = 0.0;//Variable for the user's radius input

	//Output the values for the first circle's data using the default constructor to create the circle
	cout << "Here is the first circle's data after using the default constructor for creating the circle: ";
	cout << "\nRadius: " << c1.getRadius()
	     << "\nDiameter: " << c1.getDiameter()
		 << "\nArea: " << c1.getArea()
		 << "\nCircumference: " << c1.getCircumference() << endl;
	//Ask the user for a radius value
	cout << "\nWhat value do you want to set the radius to?: ";
	cin >> r;
	c1.setRadius(r);//Set the 'c1' circle object's radius to the user's input

	//Output the values for the first circle's data after setting the radius to the user's value
	cout << "\nHere is the first circle's data after setting the radius to " << c1.getRadius() << ": ";
	cout << "\nRadius: " << c1.getRadius()
		 << "\nDiameter: " << c1.getDiameter()
		 << "\nArea: " << c1.getArea()
		 << "\nCircumference: " << c1.getCircumference() << endl;

	//Output the values for the second circle's data
	cout << "\nHere is the second circle's data: ";
	cout << "\nRadius: " << c2.getRadius()
	 	 << "\nDiameter: " << c2.getDiameter()
	 	 << "\nArea: " << c2.getArea()
		 << "\nCircumference: " << c2.getCircumference() << endl << endl;

	//Exit the main function, with 0 indicating success
	return 0;
}