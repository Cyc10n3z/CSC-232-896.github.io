/*
    authors: Matt Lippelman & John Lorette III
    lab9

    This program checks words and phrases to see if they are
    palindromes while demonstrating stacks
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function Prototype
bool isPalindrome(string);

int main() {
    string inputString;

    cout << "Enter a string (-1 to exit): ";
    getline(cin, inputString);

    while (inputString != "-1") {

        if(isPalindrome(inputString)) {
            cout << inputString << " is a palindrome" << endl << endl;
        } else {
            cout << inputString << " is not a palindrome" << endl << endl;
        }

        cout << "Enter a string (-1 to exit): ";
        getline(cin, inputString);
    }

    return 0;
}

//***********************************************
// isPalindrome takes a string argument, s      *
// The function uses a stack to reverse s and   *
// compare the reverse string with s to         *
// determine if s is a palindrome. Will return  *
// true if s reads the same forward and backward*
// , false otherwise                            *
//***********************************************
bool isPalindrome(string s) {

    return true;
}