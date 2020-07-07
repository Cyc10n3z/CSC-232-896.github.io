/*
    authors: Matt Lippelman & John Lorette III
    lab8

    This program demonstrates the forward_list and list
    containers in the STL.
*/
#include <iostream>
#include <string>
#include <forward_list>
#include <list>
using namespace std;

int main() {

    // create a forward_list object with the name names1
    forward_list<string> names1 = {"Mark", "Mary", "James"};

    // add two new elements to names1 using push_front()
    names1.push_front("Susan");
    names1.push_front("Eric");

    // declare a constant iterator for names1
    forward_list<string>::const_iterator it1;

    // use for loop and constant iterator to print out the elements of names1
    for (it1 = names1.begin(); it1 != names1.end(); it1++) {
        cout << *it1 << " ";
    }
    cout << endl;

    // create an empty list object with name names2
    list<string> names2;
    auto it2 = names2.begin();
    auto it3 = names1.begin();
    auto it4 = names1.end();

    // use the function insert to copy all the elements in names1 to names2
    names2.insert(it2, it3, it4);

    // declare a constant reverse iterator for names2
    list<string>::const_reverse_iterator rIt1;

    // use a constant reverse iterator to print the elements of names2 in reverse
    for (rIt1 = names2.rbegin(); rIt1 != names2.rend(); rIt1++) {
        cout << *rIt1 << " ";
    }
    cout << endl << endl;

    auto it5 = names2.begin();

    // use an iterator over names 2 to search for susan
    for (it5; it5 != names2.end(); it5++) {
        if (*it5 == "Susan") {
            // erase the name Susan
            it5 = names2.erase(it5);
            break;
        }
    }

    cout << "Contents of names2 after deleting Susan is: \n";
    // use a range based for loop to display contents of names2
    for (auto element : names2) {
        cout << element << " ";
    }
    cout << endl << endl;

    // use insert(iterator, newValue) to insert "Tracy" before element
    // "Mark"
    it5 = names2.insert(it5, "Tracy");

    cout << "Contents of names2 after inserting Tracy is: \n";
    // display the contents of names 2
    for (auto it = names2.begin(); it != names2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    // use the -- operator to move the iterator returned from the last call
    it5--;
    // use the insert function to insert the name John to the head of names2
    names2.insert(it5, "John");

    // use a range-basd for loop to display the contents of names2
    cout << "Contents of names2 after inserting John is: \n";
    for (auto element : names2) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}