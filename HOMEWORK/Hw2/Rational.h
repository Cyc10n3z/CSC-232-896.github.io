/************************************************************************************
*             This is a specification file for the Rational class                   *
*	                   that determines what this class does.                        *
*************************************************************************************/
#ifndef RATIONAL_H
#define RATIONAL_H
#include<iostream>
using namespace std;

/************************************************************************************
*         Rational Class Declaration: Data Members and Inline Functions             *
*************************************************************************************/
class Rational
{
    
    private:
        //
        double numer, denom;
    public:
        //Default and Overloaded Constructors
        Rational(){}
        Rational(double n, double d){
            numer = n;
            denom = d;
        }
        //Member Functions
        

};
#endif