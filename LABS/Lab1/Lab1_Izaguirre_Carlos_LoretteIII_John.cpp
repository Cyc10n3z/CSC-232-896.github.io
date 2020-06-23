/*------------------------------------------------------------------------------------
 * Author:        Carlos Izaguirre  and  John Lorette III\Lorette042
 * Date:          6/11/2020
 * Trace Folder:  LABS\Lab1\
 * File Name:     Lab1_Izaguirre_Carlos_LoretteIII_John.cpp
 * Description:   C++ Program that doubles the size of a specified array using smart
 *                pointers, and then display the contents of that array.
 ------------------------------------------------------------------------------------*/
#include<iostream>
#include<memory>
using namespace std;

//Function prototype(s)
int *doubleCapacity(const int*, int);
void display(int*, int);

//The program's main method, or control function
int main(){
   //Variable(s) for the first dynamically allocated array
   const int SIZE = 5, DOUBLE_SIZE = 10;
   int *arrayOne = new int[SIZE];

   //Loop to assign the values 1-5 into the first pointer array
   for(int i = 0; i < SIZE; i++){
       *(arrayOne + i) = i + 1;
   }
   //Display the elements of "arrOne"
   display(arrayOne, SIZE);
   //Dynamically allocate the pointer array memory, with the 'doubleCapacity()' function
   arrayOne = doubleCapacity(arrayOne, SIZE);
   //Loop to assign the values 6-10 into the new pointer array
   for (int i = SIZE; i < DOUBLE_SIZE; i++) {
       *(arrayOne + i) = i + 1;
   }
   //Display the elements of the new pointer array
   display(arrayOne, DOUBLE_SIZE);
   //Free the memory used for "arrayOne"
   delete[] arrayOne;
   arrayOne = nullptr;
 
   //Exit the program, with 0 indicating success
   return 0;
}
/**
   Double the size of the pointer array, and return the new pointer array

   @param -- *list (dynamic array of pointers)
   @param -- n (size of array)
   @return -- *newArray (new dynamic array of pointers)
*/
int *doubleCapacity(const int *list, int n){
   //Variable(s) for a dynamic array doubled in size
   int doubleSize = n * 2;
   int *newArray = new int[doubleSize];

   //Validate the dynamic array's size
   if (doubleSize <= 0) {
       return nullptr;
   }
   //Copy the contents of the first dynamic pointer array, into the doubled new dynamic pointer array
   for (int i = 0; i < doubleSize; i++) {
       *(newArray + i) = *(list + i);
   }
   //Return the new pointer array
   return newArray;
}
/**
   Display/print out all the elements in an array, separated by spaces

   @param -- *list (dynmamic array of pointers)
   @param -- n (size of dynamic array)
   @return -- void
*/
void display(int *list, int n){
    //Loop for displaying the values in the pointer array
    for (int i = 0; i < n; i++)
        cout << list[i] << " ";
    cout << endl;
}