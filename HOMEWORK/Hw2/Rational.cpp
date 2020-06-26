/************************************************************************************
*             This is an implementation file for the Rational class                 *
*	                   that determines what this class does.                        *
*************************************************************************************/
#include<iostream>
#include "Rational.h"//'Rational' class definition
using namespace std;

/************************************************************************************
*							   Rational.h Member Functions			                *
*************************************************************************************/
/**
 * This member function simplifies two 'Rational' number terms 'numer' and 'denom'
 * to their simpliest/smallest value(s). Called inside the Constructor.
 * 
 * @param none 
 * @return this -- 'this' pointer to a 'Rational' object
 */
Rational Rational::simplify(){
    //Variable for simplifying int terms by finding the G.C.D.
    int temp = findGCD(numer, denom);
    //Simplify the numerator and denominator terms with the G.C.D.
    numer /= temp;
    denom /= temp;
    //Return the simplified terms with 'this' pointer
    return *this;
}
/**
 * This static member function finds the Greatest Common Divisor among two
 * 'Rational' numbers and returns that divisor.
 * 
 * @param numer, denom -- int, int
 * @return findGCD() -- int function (Recursion)
 */
int Rational::findGCD(int numer, int denom) {
    //Recursively find the G.C.D. IF denominator is not 0
    return (denom == 0)? numer : findGCD(denom, numer % denom);
}
/**
 * This member function overloads the addition operator.
 * 
 * @param &right -- referenced const 'Rational' object
 * @return r -- 'Rational' object
 */
Rational Rational::operator + (const Rational &right) const {
    //Class object 'r' for overloading the + operator
    Rational r;
    //Overload the + operator
    r.numer = numer * right.denom + right.numer * denom;
    r.denom = denom * right.denom;
    r.simplify();//Find G.C.D.
    return r;
}
/**
 * This member function overloads the subtraction operator.
 * 
 * @param &right -- referenced const 'Rational' object 
 * @return r -- 'Rational' object
 */
Rational Rational::operator - (const Rational &right) const {
    //Class object 'r' for overloading the - operator
    Rational r;
    //Overload the - operator
    r.numer = numer * right.denom - right.numer * denom;
    r.denom = denom * right.denom;
    r.simplify();//Find G.C.D.
    return r;
}
/**
 * This member function overloads the multiplication operator.
 * 
* @param &right -- referenced const 'Rational' object 
 * @return r -- 'Rational' object
 */
Rational Rational::operator * (const Rational &right) const {
    //Class object 'r' for overloading the / operator
    Rational r;
    //Overload the / operator
    r.numer = numer * right.numer;
    r.denom = denom * right.denom;
    r.simplify();//Find G.C.D.
    return r;
}
/**
 * This member function overloads the division operator.
 *  
 * @param &right -- referenced const 'Rational' object 
 * @return r -- 'Rational' object 
 */
Rational Rational::operator / (const Rational &right) const {
    //Class object 'r' for overloading the / operator
    Rational r;
    //Overload the / operator
    r.numer = numer * right.denom;
    r.denom = denom * right.numer;
    r.simplify();//Find G.C.D.
    return r;
}
/**
 * This member function overloads the greater than operator.
 *
 * @param &right -- referenced 'Rational' object
 * @return "boolean expression" -- const bool 
 */
bool Rational::operator > (const Rational &right) const {
    //Return the value of the boolean comparison
    return (numer > right.numer) || (denom > right.denom);
}
/**
 * This member function overloads the greater than or equals operator.
 *
 * @param &right -- referenced 'Rational' object
 * @return "boolean expression" -- const bool
 */
bool Rational::operator >= (const Rational &right) const {
    //Return the value of the boolean comparison
    return (numer >= right.numer) || (denom >= right.denom);
}
/**
 * This member function overloads the less than operator.
 *
 * @param &right -- referenced 'Rational' object
 * @return "boolean expression" -- const bool
 */
bool Rational::operator < (const Rational &right) const {
    //Return the value of the boolean comparison
    return (this->numer < right.numer) && (this->denom < right.denom);
}
/**
 * This member function overloads the less than or equals operator.
 *
 * @param &right -- referenced 'Rational' object
 * @return "boolean expression" -- const bool
 */
bool Rational::operator <= (const Rational &right) const {
    //Return the value of the boolean comparison
    return (numer <= right.numer) && (denom <= right.denom);
}
/**
 * This member function overloads the equal equals operator.
 *
 * @param &right -- referenced 'Rational' object
 * @return "boolean expression" -- const bool
 */
bool Rational::operator == (const Rational &right) const {
    //Return the value of the boolean comparison
    return (numer == right.numer) && (denom == right.denom);
}
/**
 * This member function overloads the does not equal operator.
 *
 * @param &right -- referenced 'Rational' object
 * @return "boolean expression" -- const bool
 */
bool Rational::operator != (const Rational& right) const {
    //Return the value of the boolean comparison
    return (numer != right.numer) || (denom != right.denom);
}
/**
 * This member function overloads the istream operator.
 * 
 * @param &stream, &obj -- referenced istream object, referenced 'Rational' object 
 * @return &stream -- referenced istream object
 */
istream &operator >> (istream &stream, Rational &obj){
    //Input 'Rational' object values into the istream object for overloading
    stream >> obj.numer;
    stream.ignore();//Ignore the '/' character between numer and denom, in the istream object stream
    stream >> obj.denom;
    obj.simplify();//Simplify the 'Rational' reference objects numerator and denominator
    //Return the input stream object
    return stream;
}
/**
 * This member function overloads the ostream operator.
 * 
 * @param &stream, &obj -- referenced ostream object, referenced const 'Rational' object
 * @return &stream -- referenced ostream object
 */
ostream &operator << (ostream &stream, const Rational &obj){
    //Output 'Rational' object values into the ostream object for overloading
    stream << obj.numer;
    stream << "/";
    stream << obj.denom;
    //Return the output stream object
    return stream;
}
/**
 * This member function overloads the pre-increment operator.
 * 
 * @param none
 * @return *this -- this 'Rational' object pointer
 */
Rational Rational::operator ++ (){
    ++numer;
    simplify();
    return *this;
}
/**
 * This member function overloads the post-increment operator.
 * 
 * @param (dummy parameter) -- int
 * @return temp -- 'Rational' object
 */
Rational Rational::operator ++ (int){
    //Class object 'temp' for overloading the post-increment operator
    Rational temp = *this;
    //
    numer++;
    simplify();
    return temp;
}
/**
 * This member function overloads the pre-decrement operator.
 * 
 * @param none
 * @return *this -- this 'Rational' object pointer 
 */
Rational Rational::operator -- (){
    //
    --numer;
    simplify();
    return *this;
}
/**
 * This member function overloads the post-decrement operator.
 * 
 * @param (dummy parameter) -- int
 * @return temp -- 'Rational' object
 */
Rational Rational::operator -- (int){
    //Class object 'temp' for overloading the post-decrement operator
    Rational temp = *this;
    //
    numer--;
    simplify();
    return temp;
}
/************************************************************************************/