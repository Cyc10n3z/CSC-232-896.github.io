/*------------------------------------------------------------------------------------
 * Author:        Carlos Izaguirre and John Lorette III
 * Date:          6/307/2020
 * Trace Folder:  LABS\Lab6\
 * File Name:     Lab6_Izaguirre_Carlos_LoretteIII_John.cpp
 * Description:   C++ Program that 
 ------------------------------------------------------------------------------------*/
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

/************************************************************************************
*                          Bag Template Class Definition                            *
*************************************************************************************/
template <class T> class Bag//Class Template Definition
{
    private:
        T *list;                          //Array of pointers (T generic type), for storing the generic values in a bag
        int capacity;                     //Maximum capacity for a bag, the default value is 10
        int currentSize;                  //Current number/count of generic values in a bag
    public:
        Bag<T>(int cap = 10);             //Constructor
        ~Bag<T>();                        //Destructor
        T findMaximum();                  //Template Function for finding the largest generic value
        bool isFull();                    //Returns true if list is full
        void add(T);                      //Function that adds a generic value to the end of the T type pointer array
        void display();                   //Prints out the values in the bag
};
/************************************************************************************
*                      Bag Template Class Member Functions                          *
*************************************************************************************/
//Parameterized Constructor
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
//Destructor
template <typename T> 
Bag<T>::~Bag()
{
    //Release dynamically allocated memory for the 'Bag' class
    delete [] list;
}
/**
 * This template class member function finds the largest generic value in
 * a generic type class template object and returns the generic value.
 * 
 * @param x -- Template class object 
 * @return maxValue -- Template class object generic maximum value 
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
 * This template class member function determines if the 
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
 * This template class member function adds a value to the end of 
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
 * This template class member function prints/displays to the console 
 * screen the values contained in '*list' for the current 'Bag' template class.
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
    //Create a 'Bag' template class object that contains integers
    Bag<int> b(5);
    //Add integer values to the 'b' template class object
    b.add(4);
    b.add(20);
    b.add(-3);
    //Display the template class 'b' object's generic values
    cout << "Values in the Bag: ";
    b.display();
    cout << "Largest Value in the Bag is: " << b.findMaximum();

    //Prompt the user to enter a value between 1 and 10 for the SIZE of the template class object 'names'
    int SIZE = 0;
    bool valid = false;//Validation loop variable
    cout << "\n\nEnter a value between 1 and 10 for the size of a bag of names: ";
    cin >> SIZE;
    //Loop to validate the user's input with exception handling
    while (!valid) {
        //Exception handling for the template class object of string type called 'names'
        try
        {
            if (SIZE < 1 || SIZE > 10) {
                string errorMessage = "Invalid Bag Size! Please try again.\n";
                throw errorMessage;
            }
            if (SIZE >= 1 || SIZE <= 10)
                valid = true;
        }
        catch (string errorMessage)
        {
            cout << errorMessage;
            cout << "Enter a value between 1 and 10 for the size of a bag of names: ";
            cin >> SIZE;
        }
    }

    //Create a new 'Bag' template class object that contains names (as strings)
    Bag<string> names(SIZE);
    //Add values to the 'names' template class object
    names.add("Mary");
    names.add("Susan");
    names.add("Edward");
    names.add("Russ");
    names.add("John");
    names.add("Tracy");
    //Display the template class 'names' object's generic values
    cout << "\nValues in the Bag: ";
    names.display();
    //Find the largest value in 'names'
    cout << "Largest Value in the Bag is: " << names.findMaximum() << endl;


    //Exit the main function, with 0 indicating success
    return 0;
}