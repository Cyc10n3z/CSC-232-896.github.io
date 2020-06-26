/*------------------------------------------------------------------------------------
* Author:        Carlos Izaguirre and John Lorette III
* Date:          6/26/2020
* Trace Folder:  HOMEWORK\Hw2\
* File Name:     testRational.cpp, Rational.cpp, Rational.h
* Description:   C++ Program that tests all member and overloaded operator
*                functions of the class 'Rational.h' in this 'testRational' file.
-------------------------------------------------------------------------------------*/
#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include "Rational.h"//'Rational' class definition
using namespace std;

/************************************************************************************
*                 The programs main method, or control function                     *
*************************************************************************************/
int main() {
    //Create the first 2 "Rational" class objects
    Rational r1(12, 18); // 2/3
    cout << "r1 is " << r1 << endl;
    Rational r2(2, 24); // 1/12
    cout << "r2 is " << r2 << endl;
    //Create the next 4 "Rational" class objects for testing
    cout << "\nTesting the arithmetic operators" << endl;
    Rational r3 = r1 + r2; // 3/4
    cout << r1 << " + " << r2 << " = " << r3 << endl;
    Rational r4 = r3 - r2; // 2/3
    cout << r3 << " - " << r2 << " = " << r4 << endl;
    Rational r5 = r1 * r3; // 1/2
    cout << r1 << " * " << r3 << " = " << r5 << endl;
    Rational r6 = r1 / r2; // 8/1
    cout << r1 << " / " << r2 << " = " << r6 << endl;
    //Test the overloaded comparison operators
    cout << "\nTesting the comparison operators" << endl;
    cout << "Is " << r1 << " == " << r2 << "? " << (r1 == r2) << endl;
    cout << "Is " << r1 << " != " << r2 << "? " << (r1 != r2) << endl;
    cout << "Is " << r1 << " < " << r2 << "? " << (r1 < r2) << endl;
    cout << "Is " << r1 << " <= " << r2 << "? " << (r1 <= r2) << endl;
    cout << "Is " << r1 << " > " << r2 << "? " << (r1 > r2) << endl;
    cout << "Is " << r1 << " >= " << r2 << "? " << (r1 >= r2) << endl;
    //Test the overloaded extraction operator
    cout << "\nTesting the extraction operator" << endl;
    cout << "Enter a rational number in the form a/b: ";
    cin >> r1;
    cout <<"This rational is equal to " << r1 << endl;
    //Test the overloaded pre-increment operator
    cout << "\nTesting the pre-increment operator" << endl;
    cout << "r2 is " << r2 << endl;
    cout << "r3 is " << r3 << endl;
    r3 = ++r2;
    cout << "After executing r3 = ++r2" << endl;
    cout << "r2 is " << r2 << endl;
    cout << "r3 is " << r3 << endl;
    //Test the overloaded post-increment operator
    cout << "\nTesting the post-increment operator" << endl;
    r3 = r2++;
    cout << "After executing r3 = r2++" << endl;
    cout << "r2 is " << r2 << endl;
    cout << "r3 is " << r3 << endl;
    //Test the overloaded pre-decrement operator
    cout << "\nTesting the pre-decrement operator" << endl;
    Rational r7(5, 6);//Create the 7'th and final "Rational" class object
    cout << "r7 is " << r7 << endl;
    cout << "r1 is " << r1 << endl;
    r1 = --r7;
    cout << "After executing r1 = --r7" << endl;
    cout << "r1 is " << r1 << endl;
    cout << "r7 is " << r7 << endl;
    //Test the overloaded post-decrement operator
    cout << "\nTesting the post-decrement operator" << endl;
    r1 = r7--;
    cout << "After executing r1 = r7--" << endl;
    cout << "r1 is " << r1 << endl;
    cout << "r7 is " << r7 << endl;

    //Exit the main function, with 0 indicating success
    return 0;
}