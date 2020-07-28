/*------------------------------------------------------------------------------------
 * Author:        John Lorette III and Sky Ludwig
 * Date:          7/28/2020
 * Trace Folder:  LABS\Lab12\
 * File Name:     Lab12_LoretteIII_John_Ludwig_Sky.cpp
 * Description:   C++ Program that uses Dynamic Programming to find the path, in a M x N
 *                grid/table, where you collect the maximum number of gold coins.
 ------------------------------------------------------------------------------------*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<algorithm>////For the 'max()' function
using namespace std;

/***********************************************************************************
*                             Function Prototype(s)                                *
***********************************************************************************/
void display(int **, int, int);           //Display Function -> O(M * N)    
int maxGoldenCoins(int **, int, int);     //D.P. Bottom-Up Solution -> O(M * N)
/***********************************************************************************
*                               The Main Function                                  * 
***********************************************************************************/ 
int main() {
    //Variable(s) used for reading information from a file
    ifstream inputFile;
    inputFile.open("input.txt");
    int numRows, numColumns;

    //Read table dimensions from the file
    while (inputFile >> numRows >> numColumns) {
        int **table; //A pointer to pointer to create the 2-D array dynamically
        table = new int* [numRows]; //Create an array of 'numRows' int pointers
        //Create the actual rows
        for (int r = 0; r < numRows; r++)
            table[r] = new int[numColumns];
        //Read table contents from file
        for (int row = 0; row < numRows; row++) {
            for (int column = 0; column < numColumns; column++)
                inputFile >> table[row][column];
        }
        cout << "Input table" << endl;
        display(table, numRows, numColumns);
        int number = maxGoldenCoins(table, numRows, numColumns);
        cout << "Maximum number of golden coins we can collect is: " << number << endl << endl;

        //Deallocate Memory
        for (int r = 0; r < numRows; r++)
            delete [] table[r];
        delete [] table;
    }
    //Close the input stream object
    inputFile.close();
    //Exit the main function, with 0 indicating success
    return 0;
}
/***********************************************************************************
*                           Function Definition(s)                                 *
***********************************************************************************/
/**---------------------------------------------------------------------
 * This helper function displays the information in the 2-D array table
 * on a row by row basis. The runtime complexity for this function is O(M x N).
 * 
 * @param table, numRows, numColumns -- int **, int, int
 * @return none -- void
 *--------------------------------------------------------------------*/
void display(int ** table, int numRows, int numColumns) {
     //For each Row X Column, output the table value(s)
     for (int row = 0; row < numRows; row++) {
         for (int column = 0; column< numColumns; column++)
           cout << table[row][column] << " ";
         cout << endl;
     }
     cout << endl;
}
/**----------------------------------------------------------------------
 * This function uses dynamic programming to find the maximum number of 
 * golden coins that can be collected on a path starting at the top-left
 * cell (0, 0) and ending at the bottom-right cell (M - 1, N - 1). From 
 * any cell, the user can move ONLY to the cell to the right or below the
 * current cell. The golden coins in a cell are collected upon entering 
 * that cell. The runtime complexity for this 'bottom-up' approach is O(M * N).
 * 
 * @param table -- a 2-D array specifying the number of coins in each cell.
 * @param numRows -- The number of rows in the table.
 * @param numColumns -- The number of columns in the table.
 * @return maxCoins -- The maximum # of coins that can be collected.
 *---------------------------------------------------------------------*/
int maxGoldenCoins(int** table, int numRows, int numColumns) {
    //Variable(s) used for counting golden coins
    int maxCoins = 0;
    int **coinTable = new int*[numRows];//Pointer to Pointer Integer Dynamic Array -> Cache Table

    //Create the 'rows with columns' for the Cache Table
    for (int r = 0; r < numRows; r++)
        coinTable[r] = new int[numColumns];
    //Traverse the Cache Table R times
    for (int row = 0; row < numRows; row++) {
        //Traverse the Cache Table (R x) C times
        for (int column = 0; column < numColumns; column++) {
            //Fill the Cache Table with the current (R, C) value from the 'int **table'
            coinTable[row][column] = table[row][column];
            //Determine the maximum gold coin PATH through the 'int **table' based on the Cache Table contents
            if (row == 0 && column > 0) { //Fill the first row of the Cache Table, by only moving to the right (Moving FROM the adjacent LEFT cell)
                coinTable[0][column] += coinTable[0][column - 1];
            }else if (column == 0 && row > 0) { //Fill the first column of the Cache Table, by only moving downward (Moving FROM the adjacent TOP cell)
                coinTable[row][0] += coinTable[row - 1][0];
            }else if (row > 0 && column > 0) { //Fill the other rows and columns of the Cache Table, dependent on the 'maximum gold coin' cost path!
                coinTable[row][column] += max(coinTable[row - 1][column], coinTable[row][column - 1]);
            }
        }
    }
    /*The last cell of the "coinTable[][]" stores the 'maximum gold coin' cost PATH for reaching
    that destination cell denoted by (R - 1, C - 1), from the beginning/source cell (0, 0).*/
    maxCoins = coinTable[numRows - 1][numColumns - 1];
    
    //Display the contents of the "int **coinTable" used as a 'Cache Table'
    cout << "Cache table" << endl;
    display(coinTable, numRows, numColumns);
    //Deallocate Memory used for the 'Cache Table' called "int **coinTable"
    for (int i = 0; i < numRows; i++)
        delete[] coinTable[i];
    delete[] coinTable;

    //Return the stored maximum # of coins collected, based on the 'maximum gold coin' cost PATH
    return maxCoins;
}