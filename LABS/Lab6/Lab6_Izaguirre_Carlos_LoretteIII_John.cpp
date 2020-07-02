/*------------------------------------------------------------------------------------
 * Author:        Carlos Izaguirre and John Lorette III
 * Date:          6/30/2020
 * Trace Folder:  LABS\Lab6\
 * File Name:     Lab6_Izaguirre_Carlos_LoretteIII_John.cpp
 * Description:   C++ Program that tests the functionality of a class template 
 *                called 'Bag'. Also tests the functionality of exceptions.
 ------------------------------------------------------------------------------------*/
#include<iostream>
#include<iomanip>
#include<string>
#include<exception>//Include for using exception class?
using namespace std;

/************************************************************************************
*                        "Bag" Class Template Definition                            *
*************************************************************************************/
template <class T> class Bag//Defines a class template called 'Bag'
{
    private:
        T *list;                //Array of pointers (T generic type), for storing the generic values in a bag
        int capacity;           //Maximum capacity for a bag, the default value is 10
        int currentSize;        //Current number/count of generic values in a bag
    public:
        Bag(int cap = 10);      //Parameterized Constructor
        ~Bag();                 //Destructor
        T findMaximum();        //Template Function for finding the largest generic value
        bool isFull();          //Returns true if list is full
        void add(T);            //Function that adds a generic value to the end of the T type pointer array
        void display();         //Prints out the values in the bag
};
/************************************************************************************
*                     (Custom) Exception Class Definition                           *
*************************************************************************************/
class InvalidSize
{
    private:
        string msg;
    public:
        InvalidSize(){
            msg = "Invalid Bag Size! Please try again.\n";
        }
        InvalidSize(string str){
            msg = str;
        }
        string what() {
            return msg;
        }
};
/************************************************************************************
*             'Bag' Class Template: Member Function Implementation                  *
*************************************************************************************/
/**
 * This is the class template's parameterized Constructor.
 */
template <class T> 
Bag<T>::Bag(int cap)
{
    //Default values for the 'capacity' data member
    if (cap <= 0 || cap > 50)
        capacity = 10;
    else
        capacity = cap;
    //Create/declare a dynamically allocated array for the '*list' generic data member
    list = new T[capacity];
    currentSize = 0;
}
/**
 * This is the class template's Destructor.
 */
template <typename T> 
Bag<T>::~Bag()
{
    //Release dynamically allocated memory for the 'Bag' class
    delete [] list;
}
/**
 * This class template member function finds the largest generic value in
 * a generic type class template object and returns the generic value.
 * 
 * @param x -- Class template object 
 * @return maxValue -- Class template object generic maximum value 
 */
template<typename T>
T Bag<T>::findMaximum() {
    //Template generic value for the largest generic value in '*list'
    T maxValue = list[0];
    //Loop through the generic type T pointer array to find the largest generic value
    for (int i = 0; i < capacity; i++) {
        if (maxValue < *(list + i))
            maxValue = *(list + i);
    }
    //Return the largest generic object value
    return maxValue;
}
/**
 * This class template member function determines if the 
 * current 'Bag' class object is full.
 *
 * @param none
 * @return "boolean expression" -- bool
 */
template <typename T>
bool Bag<T>::isFull()
{
    return currentSize == capacity;
}
/**
 * This class template member function adds a value to the end of 
 * the array '*list' data member IF the '*list' array is not full.
 * 
 * @param value -- int
 * @return none -- void
 */
template <typename T>
void Bag<T>::add(T value)
{
    if (isFull()){
        cout << "Can not add to a full bag.\n";
        return;
    } else {
       list[currentSize++] = value;
    }
}
/**
 * This class template member function prints/displays to the console 
 * screen the values contained in '*list' for the current 'Bag' class template.
 *
 * @param none
 * @return none -- void
 */
template <typename T>
void Bag<T>::display()
{
    for (int i =0; i< currentSize; i++)
        cout << *(list + i) << " ";
    cout << endl;
}
/***********************************************************************************/

/************************************************************************************
*                 The programs main method, or control function                     *
*************************************************************************************/
int main() {
    //Create a 'Bag' class template object that contains integers
    Bag<int> b(5);
    //Add integer values to the 'b' class template object
    b.add(4);
    b.add(20);
    b.add(-3);
    //Display the class template 'b' object's generic values
    cout << "Values in the Bag: ";
    b.display();
    cout << "Largest Value in the Bag is: " << b.findMaximum() << endl << endl;

    //Variable(s) used for exception handling and a class template object 'names'
    int SIZE = 0;
    bool valid = false;//Loop variable
    //Loop to validate the user's input with exception handling
    while (!valid) {
        //Exception handling for the int variable 'SIZE'
        try
        {   
            //Prompt the user to enter an int value between 1 and 10 for the SIZE of the class template object 'names'
            cout << "Enter a value between 1 and 10 for the size of a bag of names: ";
            cin >> SIZE;
            //Throw an exception if the value of the 'SIZE' variable is invalid
            if (SIZE < 1 || SIZE > 10)
                throw InvalidSize();
            //Exit the while loop if the value of the 'SIZE' variable is valid
            if (SIZE >= 1 || SIZE <= 10)
                valid = true;
        }
        catch (InvalidSize error)//Catch any errors of 'InvalidSize()' exception type
        {
            cout << error.what();
        }
    }
    //Create a new 'Bag' class template object that contains names (as strings)
    Bag<string> names(SIZE);
    //Add values to the 'names' class template object
    names.add("Mary");
    names.add("Susan");
    names.add("Edward");
    names.add("Russ");
    names.add("John");
    names.add("Tracy");
    //Display the class template 'names' object's generic values
    cout << "\nValues in the Bag: ";
    names.display();
    //Find the largest value in 'names'
    cout << "Largest Value in the Bag is: " << names.findMaximum() << endl;

    //Exit the main function, with 0 indicating success
    return 0;
}