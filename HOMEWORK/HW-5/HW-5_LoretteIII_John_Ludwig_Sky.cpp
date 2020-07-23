/*------------------------------------------------------------------------------------
 * Author:        John Lorette III and Sky Ludwig
 * Date:          7/24/2020
 * Trace Folder:  HOMEWORK\HW-5\
 * File Name:     HW-5_LoretteIII_John_Ludwig_Sky.cpp
 * Description:   C++ Program that implements an algorithm for using "Radix Sort".
 ------------------------------------------------------------------------------------*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<queue>
using namespace std;

/********************************************************************************
*                            Function Prototype(s)                              *
********************************************************************************/
void radixSort(int *, int);//Algorithmic Implementation of "Radix Sort" 


/********************************************************************************
*                   The control method, or main function                        *
********************************************************************************/
int main(){
    //Variable(s) used for creating an int array called 'list[]', that has 'queues' containing 3-digit number groups
    const int SIZE = 10;
    vector<int> list[SIZE] = {};//
    queue<int> test = {};//
    int n = sizeof(list) / sizeof(list[0]);
    ifstream fin("input.txt");//Instantiate an input file stream object
    ofstream fout("output.txt");//Instantiate an output file stream object
    
    //Read input from a file called "input.txt" through the ifstream object


    //Call the function that contains the implementation of the "Radix Sort" Algorithm
    radixSort(list, n);
    

    //Output the "Radix Sorted" 3-digit positive integer 'queue' list(s) to a file called "output.txt"
    for (int i = 0; i < SIZE; i++) {
        fout >> list[i];
    }


    //


    //Exit the main function, with 0 indicating success
    return 0;
}

/********************************************************************************
*                          Function Definition(s)                               *
********************************************************************************/
/**
 * This function implements a "Radix Sort" Algorithm to count and then sort
 * the unordered 'queues' containing 3-digit number groups inside the integer
 * array parameter called 'list[]'.
 * 
 * @param list[], n -- int, int
 * @return none -- void
 */
void radixSort(vector<int> *list, int n){
    //Variable(s) used for implementing "Radix Sort"
    int i, j, k, l, x;
    
    //
    for (i = 0; i < 10; i++) {
    


    }
    
    //
    for (j = 0; j < 9; j++) {}
        //
        if ()
            k++;
        if ()
            l++;
        if () {
            k++;
            //
            if (l != 9)
                l++;
        }
    }

    //
    for (j = 0; j < 10; j++) {

    }
    cout << "" << endl;
}