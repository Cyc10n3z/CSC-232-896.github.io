/************************************************************************************
*               This is a specification file for the Circle class                   *
*	                   that determines what this "Circle" does.                     *
*************************************************************************************/
#ifndef CIRCLE_H
#define CIRCLE_H

/************************************************************************************
*           Circle Class Declaration: Data Members and Inline Functions             *
*************************************************************************************/
class Circle
{
	private:
		//The radius of a "circle"
		double radius = 0.0;
		
	public:
		//Variable for the value of PI
		const double PI = 3.14159;
		//Default Constructor and Overloaded Constructor
		Circle();
		Circle(double);
		
		void setRadius(double);//Member Mutator Function: Set the radius value
		double getRadius() const//Inline Accessor Function: Get the radius value
		{return radius;}
		double getArea()//Inline Accessor Function: Get the calculated area
		{return radius * radius * PI;}
		double getDiameter()//Inline Accessor Function: Get the calculated diameter
		{return radius * 2;}
		double getCircumference()//Inline Accessor Function: Get the calculated circumference
		{return 2 * PI * radius;}
};
#endif
