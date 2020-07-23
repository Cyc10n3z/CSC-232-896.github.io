/*------------------------------------------------------------------------------------
 * Author:        John Lorette III and Sky Ludwig
 * Date:          7/23/2020
 * Trace Folder:  LABS\Lab11\
 * File Name:     Lab11_LoretteIII_John_Ludwig_Sky.cpp
 * Description:   C++ Program that uses recursive functions to implement specific tasks.
 ------------------------------------------------------------------------------------*/
#include<iostream>
#include<iomanip>
using namespace std;

//--- 7/20/2020 -> John Lorette III -- Completed recursive implementation's for the 'search()' function.                                               
//--- 7/22-23/2020 -> John Lorette III -- Completed recursive implementation's for the 'printReverse()', 'replace()', and 'remove()' functions. 

//--- 7/??/2020 -> Sky Ludwig -- ???

/********************************************************************************
*                      'ListNode' Structure Definition                          *
********************************************************************************/
struct ListNode
{
    int value;
    ListNode *next;
};
/********************************************************************************
*                      'LinkedListRec' Class Definition                         *
********************************************************************************/
class LinkedListRec
{
private:
   ListNode *head;                               //ListNode head pointer
   //Provided Recursive Functions
   void destroyList();                           //Recursive function to destroy the linked list
   void displayList(const ListNode *) const;     //Recursive function to display the info in the list
   int countNodes(ListNode *) const;             //Recursive function to count number of nodes in the list
   //Added Recursive Functions
   bool search(const ListNode *, int);           //Function that search's/looks for a given value in the current linked list
   void printReverse(const ListNode *) const;    //Function that prints out the values in the linked list in reverse order
   void replace(ListNode *, int, int);           //Function that replaces every occurrence of a value in the current linked list, with a new value 
   bool remove(ListNode *, int);                 //Function that deletes the first occurence of a specified ListNode value in the current linked list
public:
   //Default Constructor
   LinkedListRec()
   {head = nullptr;}
   //Destructor
   ~LinkedListRec(){
      destroyList();
   }
   //Provided Wrapper Functions
   bool isEmpty() const;                      //Function to determine if the linked list is empty or not
   void addFirst(int);                        //Function that adds a new ListNode with specified data at the head of the current linked list
   void displayList() const;                  //Wrapper function to display all the values in the current linked list
   int countNodes() const;                    //Wrapper function to count the number of nodes in the current linked list
   //Added Wrapper Functions
   bool search(int);                          //Wrapper function that helps search for a given value in the current linked list
   void printReverse() const;                 //Wrapper function that helps print out all the values in the current linked list, in reverse
   void replace(int, int);                    //Wrapper function that helps to replace every occurrence of a value in the current linked list, with a new value
   bool remove(int);                          //Wrapper function that helps to delete the first occurence of a specified ListNode value in the current linked list
};

/********************************************************************************
*                'LinkedListRec' Private Member Functions                       *
********************************************************************************/
/**
 * This private member function recursively 'destroys' or empties the
 * current linked list.
 *
 * @param none
 * @return none -- void
 */
void LinkedListRec::destroyList() {
    if (head == nullptr) //Case list is empty
        return;
    else if (head->next == nullptr) //Case list has only one node
        delete head;
    else //Case list has more than one node
    {
        ListNode *temp;
        temp = head;
        head = head -> next;
        delete temp;
        destroyList();
    }
}
/**
 * This private member function recursively displays the contents of each
 * ListNode in the current linked list.
 *
 * @param nodePtr -- const ListNode *
 * @return none -- void
 */
void LinkedListRec::displayList(const ListNode *nodePtr) const {
    if (nodePtr == nullptr)
        return;
    else
    {
        cout << nodePtr->value << " "; //display data stored in current node
        displayList(nodePtr->next); //call function recursively on remaining nodes
    }
}
/**
 * This private member function recursively counts the number of ListNode's
 * found in the current linked list.
 *
 * @param nodePtr -- ListNode *
 * @return int
 */
int LinkedListRec::countNodes(ListNode *nodePtr) const {
   if (nodePtr == nullptr)
      return 0;
   else
      return 1 + countNodes(nodePtr->next);
}
/**
 * This private member function recursively searches for a value in
 * the current linked list. The function returns false if the value
 * is not found, and true if the value is found.
 *
 * @param searchPtr, value -- const ListNode *, int
 * @return bool
 */
bool LinkedListRec::search(const ListNode *searchPtr, int value) {
   //Recursive Search
   if (searchPtr == nullptr)//Base Case 1
      return false;
   if (searchPtr->value == value)//Base Case 2
      return true;
   //return 1 + search(searchPtr->next, x);
   return search(searchPtr->next, value);
}
/**
 * This private member function recursively prints out the values in
 * the current linked list in reverse order.
 *
 * @param print -- const ListNode *
 * @return none
 */
void LinkedListRec::printReverse(const ListNode *print) const {
    //Base Case 1
    if (print == nullptr)
        return;
    //Recursive function call
    printReverse(print->next);
    //Print out each value after the recursive function call
    cout << print->value << " ";
}
/**
 * This private member function recursively replaces every occurrence of
 * an int value in the current linked list with a new specified int value,
 * as parameters.
 *
 * @param r, oldValue, newValue -- ListNode *, int, int
 * @return none -- void
 */
void LinkedListRec::replace(ListNode *r, int oldValue, int newValue) {
    //Base Case 1
    if (r == nullptr)
        return;
    //Loop 'countNodes()' times to search for 
    for (int i = 0; i < countNodes(); i++) {
        //IF the currently pointed to ListNode has the same value as the oldValue
        if (r->value == oldValue) {
            r->value = newValue;//Replace with newValue
        }
    }
    //Recursive function call
    replace(r->next, oldValue, newValue);
}
/**
 * This private member function recursively looks for and then removes the first
 * ListNode, if any, that contains the specified parameter int value from the
 * current linked list.
 *
 * @param removePtr, value -- ListNode *, int
 * @return bool
 */
bool LinkedListRec::remove(ListNode *removePtr, int value) {
    //Pointer variable(s) for removing a ListNode in the current linked list
    ListNode *temp = head, *previous = head;

    //Base Case 1: IF the value specified is invalid
    if (value < 1)
        return removePtr;
    //Base Case 2: IF the end of the current linked list is reached
    if (removePtr == nullptr)
        return false;
    //Base Case 2: The value to be removed is found and is at the head of the current linked list
    if (removePtr == head && removePtr->value == value) {
        //
        head = removePtr->next;
        delete removePtr;
    }else{
        //Base Case 3: Check if the value to be removed is the next value in the current linked list
        if (removePtr->next && removePtr->next->value == value) {
            //
            temp = removePtr->next;
            removePtr->next = temp->next;
            delete temp;
            //?...
            return remove(removePtr, value);
        }
        //Recursive function call
        return remove(removePtr->next, value);
    }
}
/********************************************************************************
*                'LinkedListRec' Public Member Functions                        *
********************************************************************************/
/**
 * This public member function checks if the current linked list
 * is empty or not.
 *
 * @param none
 * @return bool
 */
bool LinkedListRec::isEmpty() const {
   return head == nullptr;
}
/**
 * This public member function adds a new ListNode at the head of
 * the current linked list with the specified parameter int value.
 *
 * @param data - int
 * @return none -- void
 */
void LinkedListRec::addFirst(int data) {
    ListNode * newNode = new ListNode;
    newNode -> value = data;
    newNode -> next = head;
    head = newNode;
}
/**
 * This public member 'wrapper' function helps to recursively display
 * the content of the current linked list.
 *
 * @param none 
 * @return none -- void 
 */
void LinkedListRec::displayList() const {
    displayList(head);
}
/**
 * This public member 'wrapper' function helps to recursively count
 * all the ListNodes in the current linked list.
 *
 * @param none
 * @return countNodes(head) -- int
 */
int LinkedListRec::countNodes() const {
    return countNodes(head);
}
/**
 * This public member 'wrapper' function helps the same private function
 * to recursively search for a given value in the current linked list.
 *
 * @param none 
 * @return search(head) -- bool
 */
bool LinkedListRec::search(int value) {
    return search(head, value);
}
/**
 * This public member 'wrapper' function helps the same private function
 * to recursively print all the values in the current linked list in reverse.
 *
 * @param none
 * @return printReverse() -- void
 */
void LinkedListRec::printReverse() const {
    printReverse(head);
}
/**
 * This public member 'wrapper' function helps the same private function
 * to recursively search for and then replace an old value in the current
 * linked list with a new/given value.
 *
 * @param oldV, newV -- int, int
 * @return none -- void
 */
void LinkedListRec::replace(int oldV, int newV) {
    replace(head, oldV, newV);
}
/**
 * This public member 'wrapper' function helps the same private function
 * to recursively search for and then remove a given value in the current
 * linked list.
 *
 * @param value -- int
 * @return bool
 */
bool LinkedListRec::remove(int value) {
    return remove(head, value);
}
/*******************************************************************************/

/********************************************************************************
*                   The control method, or main function                        *
********************************************************************************/
int main() {
    //Create and Instantiate a LinkedListRec object called "myList"
    LinkedListRec myList;
    //
    for (int i = 1; i<= 5; i++)
        myList.addFirst(i);
    cout << endl << "Printing the list: ";
    myList.displayList();
   
    cout <<"\nPrinting the list in reverse: ";
    myList.printReverse();
    cout << endl;
   
    cout << "\nNumber of nodes in the list is " << myList.countNodes() << endl;

    cout << "\nIs the value 3 in the list? " << myList.search(3) << endl;
    cout << "Is the value 7 in the list? " << myList.search(7) << endl;

    cout << "\nReplacing 2 by 4";
    myList.replace(2, 4);
    cout << "\nReplacing 4 by 25";
    myList.replace(4, 25);
    cout <<"\nThe list now is: ";
    myList.displayList();

    cout << "\n\nRemove 100";
    myList.remove(100);
    cout << "\nRemove 1";
    myList.remove(1);
    cout << "\nRemove 3";
    myList.remove(3);
    cout << "\nRemove 5";
    myList.remove(5);
    cout <<"\nThe list now is: ";
    myList.displayList();

    cout << endl;
    //Exit the main function, with 0 indicating success
    return 0;
}
