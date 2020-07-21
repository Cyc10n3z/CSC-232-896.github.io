/*------------------------------------------------------------------------------------
 * Author:        Joy Adeyemo and John Lorette III
 * Date:          7/17/2020
 * Trace Folder:  HOMEWORK\HW-4\
 * File Name:     HW-4_Adeyemo_Joy_LoretteIII_John.cpp
 * Description:   C++ Program that uses a dequeue STL object for simulating a queue to
 *                update information about a Transaction that is at the front of the queue.
 * ------------------------------------------------------------------------------------*/
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<string>
#include<deque>//Required for using double ended queues
using namespace std;

/************************************************************************************
*                 "Transaction" Structure (Template) Definition                     *
*************************************************************************************/
struct Transaction
{
    char type;      //The type of transaction ('b' for buy or 's' for sell)
    int shares;     //The # of 'shares' for a transaction
    int price;      //The 'price/cost' per share for a transaction
};
/************************************************************************************
*                         Function Template Prototype(s)                            *
*************************************************************************************/
int sellTransaction(deque<Transaction> &, int);  //Function for handling the "sell" Transaction type

/************************************************************************************
*                  The programs main method, or control function                    *
*************************************************************************************/
int main() {
    //Create and Initialize a deque<Transaction> object 'queue'
    deque<Transaction> queue = {};
    //Create and Instantiate a Transaction object 'temp'
    Transaction temp;
    //Variables for reading transaction information from a text file
    int days = 0, index = 0, capital = 0, totalProfit = 0,
        totalLoss = 0, shares, cost;
    string text = " ", line = " ";
    char c = ' ', t = ' ';
    //Create and Initialize an input file stream object
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cout << "The file you are trying to open is empty. Please try a different text file!\n";
        return 0;
    }

    //Loop through the rest of the text file, reading each line until you reach the end
    while (!fin.eof()) {//Read the first word in a line, of a text file, to determine whether it is "Buy" or "Sell"
        //Read an entire line in the text file, piece by piece
        fin >> t;
        fin >> text >> shares >> text >> text >> c >> cost >> text;
        //Pass the values, in a line in the text file, to the respective Transaction object in the 'deque<Transaction>'
        temp.type = t;
        temp.shares = shares;
        temp.price = cost;
        queue.push_back(temp);
        days++;
    }

    //Call the 'sellTransaction()' function to calculate the capital gained or lost when selling
    capital = sellTransaction(queue, days);
    //Determine IF the sell total of "X bought shares sold at Y sell price" is a capital gain or loss
    if (capital > 0) {
        totalProfit = capital;
        cout << "\nTotal capital gain is: " << totalProfit << endl;
    }else if (capital < 0) {
        totalLoss = abs(capital);
        cout << "\nTotal capital loss is: " << totalLoss << endl;
    }else{
        cout << "\nTotal capital has not changed!\n";
    }

    //Exit the main function, with 0 indicating success
    return 0;
}

/************************************************************************************
*                           Function Template Definition                            *
*************************************************************************************/
/**
 *  This function takes as parameters: a deque<Transaction> reference object,
 *  and an integer value for the number of day Transactions inside the dequeue.
 *  The function processes the 'Buy' Transactions that occur before encountering
 *  the 'Sell' Transaction. Depending on IF there are no shares left or IF there are
 *  shares left for 'Sell' or 'Buy' Transactions...return the calculated capital value.
 *
 *  @param q, days -- deque<Transaction> &, int
 *  @return capital -- int
 */
int sellTransaction(deque<Transaction> &q, int days) {
    //Variable(s) for processing a "Sell" Transaction in the dequeue
    deque<Transaction> buy = {};
    Transaction *sell;
    int capital = 0, count = 0, soldPrice = 0,
        sellShares = 0, boughtShares = 0;

    //Put 'Buy' Transactions into the 'buy' dequeue
    for (int i = 0; i < days; i++) {
        //IF the Transaction day type is "Buy" or 'b'
        if (q.front().type == 'b') {
            buy.push_back(q.front());
            q.pop_front();
        }
        //IF the Transaction day type is "Sell" or 's'
        if (q.front().type == 's') {
            q.push_back(q.front());
            q.pop_front();
        }
    }
    //Push to the back of the dequeue the last "Sell" Transaction left in the dequeue
    q.push_back(q.front());
    q.pop_front();

    //While 'Sell shares' are greater than 0 (NOT empty)
    while (!q.empty()) {
        //IF "Sell" Transaction shares at the front are less than or equal to "Buy" Transaction shares at the front
        if (q.front().shares <= buy.front().shares) {
            buy.front().shares -= q.front().shares;
            capital += q.front().shares * (q.front().price - buy.front().price);
            q.front().shares = 0;
            q.pop_front();
        }else{//IF "Sell" Transaction shares at the front are greater than "Buy" Transaction shares at the front
            q.front().shares -= buy.front().shares;
            capital += buy.front().shares * (q.front().price - buy.front().price);
            buy.front().shares = 0;
            buy.pop_front();
        }
    }

    //Return the calculated capital sold
    return capital;
}
/*************************************************************************************/
