/*------------------------------------------------------------------------------------
 * Author:        Joy Adeyemo and John Lorette III
 * Date:          7/17/2020
 * Trace Folder:  HOMEWORK\HW-4\
 * File Name:     HW-4_Adeyemo_Joy_LoretteIII_John.cpp
 * Description:   C++ Program that uses a dequeue STL object for simulating a queue to 
 *                update information about a Transaction that is at the front of the queue.
 * ------------------------------------------------------------------------------------*/
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<sstream>
#include<cassert>
#include<queue>//Required for using queues
#include<deque>//Required for using double ended queues
using namespace std;

/************************************************************************************
*                  "Transaction" Structure Template Definition                      *
*************************************************************************************/
template <class T>
struct Transaction
{
    int count;      //The 'count' index value for a transaction
    char type;      //The type of transaction ('Buy' or 'Sell')
    int shares;     //The 'shares' of a transaction
    int price;      //The 'price/cost' of a transaction
};
/************************************************************************************
*                  The programs main method, or control function                    *
*************************************************************************************/
int main() {
    //Create and Instantiate a deque<int> object 'queue'
    deque<Transaction<int>> queue;
    //Variables for reading transaction information from a text file
    int counter = 0, shares, price, profit = 0, loss = 0;
    string s;
    char t;
    //Create and Initialize an input file stream object
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cout << "The file you are trying to open is empty. Please try a different text file!\n";
        return 0;
    }
    
    //Loop through the rest of the text file, until you reach the end
    while (!fin.eof()) {
        //Read the first word in a line, of a text file, to determine whether it is "buy" or "sell"
        fin >> t;
        queue[counter].type = t;
        fin >> s;
        //IF the first word in the text file is equal to "buy"
        if (queue[counter].type == 'b') {
            //Read the 'count' of shares bought, and then skip until the share 'price'is read 
            fin >> shares >> s >> s >> s;
            //
            s = s.substr(1);
            queue[counter].price = stoi(s);
            fin >> s;//Skip the word "each"
            //
            queue.push_back(make_pair(shares, price));
        }else{//IF the first word in the text file is equal to "sell"
            //Read the 'count' of shares sold, and then skip until the share 'price' is read
            fin >> shares >> s >> s >> s;
            s = s.substr(1);
            fin >> s;//Skip the word "each"
            //
            p = queue.front();
            queue.pop_front();
            //Calculate the total capital gain or loss
            while (shares >= 1) {
                //
                if (p.first <= shares) {
                    //
                    profit += (p.first) * (price - p.second);
                    shares -= p.first;
                    //
                    p = queue.front();
                    queue.pop_front();
                }else{//
                    //
                    profit += (shares) * (price - p.second);
                    p.first -= shares;
                    //
                    shares = 0;
                    queue.push_front(p);
                }
                //
                cout << "Total capital gain is: $" << profit;
            }
            //
            cout << "Total capital loss is: $" << profit;
        }
        //Increment the count/number of Transaction's in the dequeue simulation of a queue
        queue[++counter].count = counter;
    }
    

    //Exit the main function, with 0 indicating success
    return 0;
}

