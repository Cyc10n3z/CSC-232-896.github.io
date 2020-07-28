/*------------------------------------------------------------------------------------
 * Author:        John Lorette III and Sky Ludwig
 * Date:          7/24/2020
 * Trace Folder:  HOMEWORK\HW-5\
 * File Name:     HW-5_LoretteIII_John_Ludwig_Sky.cpp
 * Description:   C++ Program that implements an algorithm for using "Radix Sort".
 ------------------------------------------------------------------------------------*/
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<string>
#include<queue>
#include<vector>
using namespace std;

/********************************************************************************
*                            Function Prototype(s)                              *
********************************************************************************/
void radixSort(vector<int>, int);        //Algorithmic Implementation of "Radix Sort" 
void count(vector<int>, int, int);       //Helper Function???...
/********************************************************************************
*                              The Main Function                                *
********************************************************************************/
int main(){
    //Variable(s) used for implementing "Radix Sort"
    vector<int> list = {};//Vector of 3-digit integers called 'list'
    int count = 0, threeDigits = 0, n = sizeof(list) / sizeof(list[0]);;
    //vector<int> listArray[SIZE] = {}; //Array of several lines of 'list's
    string line = "", temp = "";
    ifstream fin("input.txt");//Instantiate an input file stream object
    ofstream fout("output.txt");//Instantiate an output file stream object
    //Determine if the ifstream object is able to be opened for input
    if (!fin.is_open()) {
        cout << "The file you are trying to open is empty. Please try a different text file!\n";
        fin.close();
        return 0;
    }
    //Read input from a file called "input.txt" through the ifstream object, into a vector array?
    while (getline(fin, line)) {
        //
        istringstream test(line);
        //
        while (test >> temp) {
            threeDigits = stoi(temp);
            list.push_back(threeDigits);
        }
        //
        count++;
    }
    //Close the input file stream
    fin.close();
    
    //Determine if the ofstream object is able to be opened for output
    if (fout.fail()) {
        cout << "The file you are trying to open doesn't exist. Make sure it exists, and try again!\n";
        fout.close();
        return 0;
    }
    //Output the "Radix Sorted" 3-digit positive integer 'queue' list(s) to a file called "output.txt"
    radixSort(list, n);//Call the function that contains the implementation of the "Radix Sort" Algorithm
    for (int i = 0; i < 10; i++) {
        fout << list[i] << " ";
    }
    //Close the output file stream
    fout.close();

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
 * @param list[], n -- vector<int>, int
 * @return none -- void
 */
void radixSort(vector<int> list, int n) {
    //Variable(s) used for implementing "Radix Sort"
    int digits = 10, maxDigits = 3, currentDigit = 0;
    const int RADIX = 10;
    queue<int> bins[RADIX];

    ////
    //for (int d = 0, factor = 1; d < digits; factor *= RADIX, d++) {
    //    //
    //    for (int j = 0; j < n; j++) {
    //        bins[list[j] / factor % RADIX].push(list[j]);
    //    }
    //    //
    //    for (int j = 0, k = 0; k < RADIX; k++) {
    //        //
    //        while (!bins[j].empty()) {
    //            list[k++] = bins[j].front();
    //            bins[j].pop();
    //        }
    //    }
    //}

    //While the currentDigit is less than the maximum # of digits
    while (currentDigit < maxDigits) {
        //
        for (int i = 0; i < n; i++) {
            //
            int divisor = (int) pow(10, currentDigit);
            int num = static_cast<int>(list[i]);
            int digitValue = static_cast<int>((num / divisor) % 10);
            bins[digitValue].push(num);
        }
        //Put the contents of all the queues back into the vector<int>
        int j = 0;
        for (int k = 0; k < 10; k++) {
            //
            while (!bins[k].empty()) {
                int temp = bins[k].front();
                list[j] = temp;
                bins[k].pop();
                j++;
            }
        }
    //
    currentDigit++;
    }
}
/**
 * This helper function...
 *
 *
 * @param
 * @return
 */
void count(vector<int> list, int n, int place) {
    //
    vector<int> output = {}, count = {};
    
    //
    for (int i = 0; i < n; i++) {
        count[(list[i] / place) % 10]++;
    }
    //
    for (int j = 1; j < 10; j++) {
        count[j] += count[j - 1];
    }
    //
    for (int k = n - 1; k >= 0; k--) {
        output[count[(list[k] / place) % 10] - 1] = list[k];
        count[(list[k] / place) % 10]--;
    }
    //
    for (int l = 0; l < n; l++) {
        list[l] = output[l];
    }
}