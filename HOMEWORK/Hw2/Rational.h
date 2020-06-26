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
        //Private data members for a numerator and denominator
        int numer, denom;
    public:
        //Default and Overloaded Constructors
        Rational(){
            numer = 0;
            denom = 1;
        }
        Rational(int n = 0, int d = 1){
            numer = n;
            denom = d;
            simplify();
        }
        ~Rational(){}//Destructor
        //Member Functions
        Rational simplify();
        static int findGCD(int, int);
        //Overloaded Arithmetic Operators
        Rational operator + (const Rational &) const;
        Rational operator - (const Rational &) const;
        Rational operator * (const Rational &);
        Rational operator / (const Rational &) const;
        //Overloaded Relational Operators
        bool operator > (const Rational &) const;
        bool operator < (const Rational &) const;
        bool operator >= (const Rational &) const;
        bool operator <= (const Rational &) const;
        bool operator == (const Rational &) const;
        bool operator != (const Rational &) const;
        //(Friend Functions)-> Overloaded Stream Insertion and Extraction Operators
        friend istream &operator >> (istream &, Rational &);
        friend ostream &operator << (ostream &, const Rational &);
        //Overloaded Postfix and Prefix Operators
        Rational operator ++ ();
        Rational operator ++ (int);
        Rational operator -- ();
        Rational operator -- (int);


};
#endif