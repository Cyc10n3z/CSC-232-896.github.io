/*------------------------------------------------------------------------------------
 * Author:        Matthew Lippelman and John Lorette III
 * Date:          7/14/2020
 * Trace Folder:  LABS\Lab9\
 * File Name:     Lab9_Lippelman_Matthew_LoretteIII_John.cpp
 * Description:   C++ Program that demonstrates the use of a Stack implementation 
 *                to determine IF a string argument is a palindrome or not.
 ------------------------------------------------------------------------------------*/
#include<iostream>
#include<iomanip>
#include<stack>
#include<string>
#include<ctype.h>
using namespace std;

/************************************************************************************
*                               Function Prototype(s)                               *
*************************************************************************************/
bool isPalindrome(string);
/************************************************************************************
*                  The programs main method, or control function                    *
*************************************************************************************/
int main(){
    //String variable for user input
    string inputString;

    //Ask the user to enter a string, exit if -1 is entered
    cout << "Enter a string (-1 to exit): ";
    getline(cin, inputString);
    //Loop until the user enters -1
    while(inputString != "-1"){
        //IF the 'isPalindrome()' function returns true
        if(isPalindrome(inputString)){
            cout << inputString << " is a palindrome." << endl << endl;
        }else{//If the 'isPalindrome()' function returns false
            cout << inputString << " is not a palindrome." << endl << endl;
        }
        //Keep asking for the user to enter a string until -1 is entered
        cout << "Enter a string (-1 to exit): ";
        getline(cin, inputString);
    }

    //Exit the main function, with 0 indicating success
    return 0;
}
/**
 * This function uses a stack to reverse the given string argument 's'
 * and compare the reversed string with 's' to determine if 's' is
 * or isn't a palindrome. The function will return true if 's' reads
 * the same forward and backward. The function will return false
 * otherwise.
 * 
 * @param s -- string
 * @return boolean value -- bool
 */
bool isPalindrome(string s){
    //Create a char Stack object
    stack<char> charStack;

    //Iterate through each character in the string 's'
    for (int i = 0; i < s.length(); i++) {
        //IF the character is an alpha or numeric char
        if (isalnum(s[i])) {
            //Push the char to the stack
            charStack.push(s[i]);
        }
        //Otherwise do nothing
    }
    //Loop/iterate through each character in the string 's'
    for(int i = 0; i < s.length(); i++){
        //IF the character is: an alpha char or numeric char
        if(isalnum(s[i])){
            //Retrieve the top element from the Stack
            char currentChar = charStack.top();
            //Remove the top element from the Stack
            charStack.pop();
            //IF the i'th character in the string is not equal to
            //the character in currentChar, return false
            if(tolower(s[i]) != tolower(currentChar))
                return false;
        }
    }
    //Return true if the program iterates through the entire string
    //without returning false.
    return true;
}