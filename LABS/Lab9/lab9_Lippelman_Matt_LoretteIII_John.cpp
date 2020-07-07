/*
    authors: Matt Lippelman & John Lorette III
    lab9

    This program checks words and phrases to see if they are
    palindromes while demonstrating stacks
*/
#include <iostream>
#include <stack>
#include <string>
#include <ctype.h>
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
    stack<char> charStack;

    // iterate through each character in the string s
    for (int i = 0; i < s.length(); i++) {
        // if the character is an alpha or numeric char
        if (isalnum(s[i])) {
            // push the char to the stack
            charStack.push(s[i]);
        }
        // otherwise do nothing
    }

    // iterate through each character in the string s
    for (int i = 0; i < s.length(); i++) {
        // if the character is an alpha or numeric char
        if (isalnum(s[i])) {
            // retrieve the top element from the stack
            char currentChar = charStack.top();
            // remove the top element from the stack
            charStack.pop();
            // if the ith character in the string is not equal to
            // the character in currentChar, return false
            if (tolower(s[i]) != tolower(currentChar))
                return false;
        }
    }
    // return true if it made it through the entire string without
    // returning false, meaning it is a palindrome
    return true;
}