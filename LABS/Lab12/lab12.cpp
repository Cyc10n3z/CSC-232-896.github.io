//@file goldenCoins.cpp

#include <iostream>
#include <fstream>
#include <cmath> //for max function


using namespace std;

//Display the information in the 2D array table on a row by row basis
void display(int ** table, int numRows, int numColumns)
{
     for (int row = 0; row < numRows; row++)
     {
         for (int column = 0; column< numColumns; column++)
           cout << table[row][column] << " ";
         cout << endl;
     }
     cout << endl;
}//display()

//-----------------------------------------------------------------------
//This function uses dynamic programming to find the maximum
//number of golden coins that can be collected on a path starting at the
//top-left cell and ending at the bottom-right cell. From any cell, the
//user can move either to the cell to the right or below the current
//cell. The golden coins in a cell are collected upon entering that cell.
//@param table -- a 2D array specifying the number of coins in each cell
//@param numRows -- number of rows of table
//@param numColumns -- number of columns of the table
//@return -- maximum number of coins that can be collected
//-------------------------------------------------------------------------
int maxGoldenCoins(int ** table, int numRows, int numColumns)
{
    int sum = table[0][0];
    int *place = table[0][0];
    int **cache;
    cache = new int*[numRows];
    bool end = false;


    while(!end){
        if (place == &table[numRows][numColumns]){
            end = true;
        }
        else{
            
        }
    }


    //display(cache, numRows, numColumns);

    return sum; //replace this by actual return value

}//maxGoldenCoins()

int main()
{
    //read info from file
    ifstream inputFile;
    inputFile.open("input.txt");

    int numRows, numColumns;
    while (inputFile >> numRows >> numColumns)//read table dimensions from file
    {
        int **table; //a 2D array, or pointer to pointer to create the 2D array dynamically
        table = new int* [numRows]; //create an array of numRows int pointers
        //create the actual rows
        for (int r = 0; r < numRows; r++)
            table[r] = new int[numColumns];

        //read table contents from file
        for (int row = 0; row < numRows; row++)
            for (int column = 0; column< numColumns; column++)
                inputFile >> table[row][column];

        cout << "Input table" << endl;
        display(table, numRows, numColumns);
        int number = maxGoldenCoins(table, numRows, numColumns);
        cout << "Maximum number of golden coins we can collect is " << number << endl << endl;

        //Deallocate memory
        for (int r = 0; r < numRows; r++)
            delete [] table[r];
        delete [] table;
    }
    inputFile.close();
    return 0;
}//main()