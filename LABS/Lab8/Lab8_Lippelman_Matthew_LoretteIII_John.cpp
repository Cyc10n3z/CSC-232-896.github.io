/*------------------------------------------------------------------------------------
 * Author:        Matthew Lippelman and John Lorette III
 * Date:          7/9/2020
 * Trace Folder:  LABS\Lab8\
 * File Name:     Lab8_Lippelman_Matthew_LoretteIII_John.cpp
 * Description:   C++ Program to practice working with Iterators and the STL containers
 *                "forward_list" and "list". These containers represent singly and
 *                doubly linked lists, respectively.
 ------------------------------------------------------------------------------------*/
#include<iostream>
#include<iomanip>
#include<forward_list>
#include<list>
using namespace std;

/************************************************************************************
*                  The programs main method, or control function                    *
*************************************************************************************/
int main(){
    //Task 1: Create a forward_list object and initialize the object with some values
    forward_list<string> names1 = {"Mark","Mary","James"};
    //Task 2: Use the push_front() function to add names to the 'names1' list
    names1.push_front("Susan");
    names1.push_front("Eric");
    //Task 3: Declare a constant iterator for 'names1'
    forward_list<string>::const_iterator iT1;
    //Task 3: Loop to print out the elements in the list 'names1' with a constant iterator
    for (iT1 = names1.begin(); iT1 != names1.end(); iT1++) {
        cout << *iT1 << " ";
    }

    //Taask 4: Create an empty list object and initialize it with three iterators
    list<string> names2;
    auto iT2 = names2.begin();
    auto iT3 = names1.begin();
    auto iT4 = names1.end();
    //Task 5: Copy all the elements in 'names1' to 'names2' with the insert() function
    names2.insert(iT2, iT3, iT4);
    //Task 6: Use a constant reverse iterator to print out the elements of 'names2'
    list<string>::const_reverse_iterator rIT1;
    for(rIT1 = names2.rbegin(); rIT1 != names2.rend(); rIT1++){
        cout << *rIT1 << " ";
    }
    cout << endl << endl;

    //Task 7: Use an iterator over 'names2' to search and erase the name Susan
    auto iT5 = names2.begin();
    for(iT5; iT5 != names2.end(); iT5++){
        if (*iT5 == "Susan") {
            iT5 = names2.erase(iT5);
            break;
        }
    }
    //Task 8: Using a range-based for loop, display the contents of 'names2'
    cout << "Contents of names2 after deleting Susan is: \n";
    for(auto element : names2){
        cout << element << " ";
    }
    cout << endl << endl;

    //Task 9: Use the insert(iterator, newValue) function to insert the name Tracy before
    //the name Mark, then display the contents of 'names2' using a range-based for loop.
    iT5 = names2.insert(iT5, "Tracy");
    cout << "Contents of names2 after inserting Tracy is: \n";
    for (auto element : names2) {
        cout << element << " ";
    }
    cout << endl << endl;

    //Task 10: Use the -- operator to move the iterator returned from the last call to insert()
    //one element backwards. Use the insert() function to insert the name John to the head of
    //'names2'. Then use a range-based for loop to display the contents of 'names2'.
    iT5--;
    names2.insert(iT5, "John");
    cout << "Contents of names2 after inserting John is: \n";
    for(auto element : names2){
        cout << element << " ";
    }
    cout << endl;

    //Exit the main function, with 0 indicating success
    return 0;
}