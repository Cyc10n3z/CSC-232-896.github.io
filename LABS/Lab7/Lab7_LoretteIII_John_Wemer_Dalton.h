/*------------------------------------------------------------------------------------
 * Author:        John Lorette III and Dalton Wemer
 * Date:          7/7/2020
 * Trace Folder:  LABS\Lab7\
 * File Name:     Lab7_LoretteIII_John_Wemer_Dalton.h
 * Description:   C++ Program that tests the functionality and implementation 
 *                of a class template singly-linked list. Our group chose to 
 *                implement the Extra Credit function.
 ------------------------------------------------------------------------------------*/
#ifndef LAB7_LORETTEIII_JOHN_WEMER_DALTON_H
#define LAB7_LORETTEIII_JOHN_WEMER_DALTON_H
#include<iostream>
#include<iomanip>
#include<cassert>
using namespace std;

/************************************************************************************
*                     'Node' Structure Template Definition                          *
*************************************************************************************/
template <class T>
struct Node
{
    T value;        //The value in this node
    Node<T> *next;  //To point to the next node
};
/************************************************************************************
*                    'LinkedList' Class Template Definition                         *
*************************************************************************************/
template <class T>
class LinkedList
{
private:
    Node<T> *head;   //List 'head' pointer (Beginning Node of the Linked List)

    //Helper Function 1 -- Copy/Preserve the Linked List in ascending order
    void copyList(const LinkedList<T> &);
    //Helper Function 2 -- Destroy/Empty the current Linked List
    void deleteList();
public:
    //Constructor
    LinkedList(){
        head = nullptr;
    }
    //Copy Constructor                  
    LinkedList(const LinkedList &otherList) {
        //Helper function used for 'deep copying' the referenced Linked List object
        head = nullptr;
        copyList(otherList);
    }
    //Destructor
    ~LinkedList();

    //Linked List operations
    void displayList() const;
    void insertNode(T);
    void deleteNode(T);
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Added Functions>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    int search(T) const;                   //Function (1)
    int countNodes();                      //Function (2)
    void deleteByPosition(int);            //Function (4)
    void insertByPosition(int, T);         //Extra Credit Function!
};

/************************************************************************************
*           Linked List Class Template: Member Function Implementations             *
*************************************************************************************/
//**************************************************
//                  Destructor                     *
// This function deletes every node in the list.   *
//**************************************************
template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *nodePtr;   //To traverse the list
    Node<T> *nextNode;  //To point to the next node
    //Position nodePtr at the head of the list
    nodePtr = head;

    //While nodePtr is not at the end of the list...
    while (nodePtr != nullptr)
    {
        //Save a pointer to the next node
        nextNode = nodePtr->next;
        //Delete the current node.
        delete nodePtr;
        //Position nodePtr at the next node
        nodePtr = nextNode;
    }
}
//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************
template <class T>
void LinkedList<T>::displayList() const
{
    Node<T> *nodePtr;//To move through the list

    //Position nodePtr at the head of the list
    nodePtr = head;

    //While nodePtr points to a node, traverse the list
    while (nodePtr)
    {
        //Display the value in this node
        cout << nodePtr->value << " ";
        //Move to the next node
        nodePtr = nodePtr->next;
    }
    cout << endl;
}
//**************************************************
// The insertNode function inserts a node with     *
// newValue copied to its value member.            *
// New node is added in its proper sorted location *
// in the linked list.                             *
//**************************************************
template <class T>
void LinkedList<T>::insertNode(T newValue)
{
    Node<T> *newNode;					//A new node
    Node<T> *nodePtr;					//To traverse the list
    Node<T> *previousNode = nullptr;	//The previous node

    //Allocate a new node and store newValue there
    newNode = new Node<T>;
    newNode->value = newValue;

    //If there are no nodes in the list...
    //Make 'newNode' the first node
    if (!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else  //Otherwise, insert newNode
    {
        //Position nodePtr at the head of list
        nodePtr = head;

        //Initialize previousNode to nullptr
        previousNode = nullptr;

        //Skip all nodes whose value is less than newValue
        while (nodePtr != nullptr && nodePtr->value < newValue)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        //If the new node is to be the 1'st in the list,
        //insert it before all other nodes.
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else//Otherwise insert after the previous node
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}
//*****************************************************
// The deleteNode function searches for a node        *
// with searchValue as its value. The node, if found, *
// is deleted from the linked list and from memory.   *
//*****************************************************
template <class T>
void LinkedList<T>::deleteNode(T searchValue)
{
    Node<T> *nodePtr;                 //To traverse the list
    Node<T> *previousNode = nullptr;  //To point to the previous node

    //If the list is empty, do nothing.
    if (!head)
        return;

    //Determine if the first node is the one.
    if (head->value == searchValue)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        //Initialize nodePtr to head of list
        nodePtr = head;

        //Skip all nodes whose value member is
        //not equal to num.
        while (nodePtr != nullptr && nodePtr->value != searchValue)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        //If nodePtr is not at the end of the list,
        //link the previous node to the node after
        //nodePtr, then delete nodePtr.
        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}
/**
 * This class template member function searches for the node
 * that contains a value inside a linked list, and returns the 
 * position of that value. IF the value isn't found return -1.
 *
 * @param searchValue -- T
 * @return listIndex -- int
 */
template <class T>
int LinkedList<T>::search(T searchValue) const {
    //Variable(s) for searching through the Node values in a linked list
    Node<T> *current = head, *previous = head;
    int listIndex = 0;

    //Loop through all the Node<T> values in a Linked List with pointers
    while (current) {
        //IF the searchValue is found...return the int value for the 'Node' index
        if (current->value == searchValue)
            return listIndex;
        //Make the current Node the previous Node, and make the current Node the next Node
        previous = current;
        current = current->next;
        //Increment the Index position for the current/next 'Node'
        listIndex++;
    }
    //The value wasn't found, return -1
    return -1;
}
/**
 * This class template member function counts and returns
 * the counted number of nodes in a linked list.
 *
 * @param none
 * @return count -- int
 */
template <class T>
int LinkedList<T>::countNodes() {
    //Pointer variable(s) used for counting the Nodes in a linked list
    Node<T> *current = head;
    int count = 0;
    //Loop through all the Node<T> values in a linked list
    while (current != nullptr) {
        //For each Node<T> found update the count and then point to the next Node<T>
        count++;
        current = current->next;
    }
    //Return the count of Nodes found in the linked list
    return count;
}
 /**
  * This class template member function deletes a node at
  * a specified position. If the position is less than 0 or 
  * equal to the linked list length, then print an error 
  * message and do nothing.
  *
  * @param position -- int
  * @return none -- void
  */
template <class T>
void LinkedList<T>::deleteByPosition(int position) {
    //Pointer variable(s) used for deleting a Node<T> 
    Node<T> *current = head, *previous = head, *last = nullptr;
    //Variable(s) used for deleting a Node<T> at a specific location
    int listLength = countNodes(), index = 1;
    bool found;//Boolean loop variable
    
    //Case 1a or 4?: IF the specified position is less than 0 OR greater than or equal to the linked list length
    if (position < 0 || position >= listLength) {
        cout << "There is no node located at position " << position << endl;
    }
    //Case 1b: The linked list is empty
    if (head == nullptr) {
        cout << "Cannot delete from an empty list." << endl;
    }
    else {
        //Case 2: The first Node is the specified position of the linked list
        if (position == 0) {
            //
            current = head;
            head = head->next;
            listLength--;
            if (head == nullptr)
                last = nullptr;
            //Deallocate the dynamic memory used at/for the currently pointed to Node<T>
            delete current;
        }
        else {//Case 3a: Search the list for the given Node<T> position
            found = false;
            previous = head;//Point to the first Node
            current = head->next;//Point to the second Node
            //Loop through the Node<T> values and search the list
            while (current != nullptr && !found) {
                //Find the Node<T> at a specified position of a linked list
                if (index != position) {
                    //Check each Node at the index position of the linked list
                    previous = current;
                    current = current->next;
                    index++;//Update the index position counter
                }
                else {
                    found = true;
                }
            }
            //Case 3b: IF the given Node<T> position of a linked list is found, DELETE the Node
            if (found) {
                //Set the previous Node's 'link value' to the current Node's 'link value'
                previous->next = current->next;
                listLength--;//Decrement the linked list's length
                index--;//Decrement the current location's index of the linked list
                //IF the Node to be deleted is the last Node in the linked list
                if (position == listLength) {
                    last = previous;
                    previous->next = nullptr;
                }
                //Deallocate the dynamic memory used at/for the currently pointed to Node<T>
                delete current;
            }
        }   
    }
}
/**
 * This class template member function attempts to insert a new value
 * at a specified position "IF possible". If inserting the 'newValue' at
 * the specific position would make the linked list unsorted, print an 
 * error message and do nothing. If the position is less than or equal 
 * to 0, insert 'newValue' at the head of the linked list. If the position
 * is greater than or equal to the linked list length, insert 'newValue'
 * at the end of the linked list.
 *
 * @param position, newValue -- int, T
 * @return none -- void
 */
template <class T>
void LinkedList<T>::insertByPosition(int position, T newValue) {
    //Pointer variable(s) used for inserting a new Node<T>, at a specific position in the linked list
    Node<T> *newNode, *current = head, *previous = head, *last = nullptr;
    //For comparing a specific linked list location with the total # of Nodes
    int listLength = countNodes(), index = 1;
    bool found;//Boolean loop variable

    //Dynamically allocate memory for a new Node<T> and store the newValue there
    newNode = new Node<T>;
    newNode->value = newValue;
    newNode->next = nullptr;
    //Case 1: If the linked list is empty, then make
    //'newNode' the first node value in the linked list
    if (head == nullptr){
        head = newNode;
        last = newNode;
        listLength++;
        index++;
    }else{//All Other...Logical Case's
        //Set the currently pointed to Node, to point to the first/head Node in the linked list
        current = head;
        found = false;
        //Case 2: The first/head Node of the linked list is the specified position
        if (position <= 0 && current == head) {
            if (newValue > current->value) {
                cout << "Cannot insert " << newValue << " at the head because that would make the list unsorted!\n";
            }else{
                //IF the Node is able to be inserted at the specified position at the head Node or before it, then do the insert
                newNode->next = current;
                head = newNode;
                listLength++;
            }
        }else{//Case 3: The linked list is NOT empty, and the newNode should be inserted somewhere after the first Node
            //Loop through and search for the specified position and the T value of 'newValue' in the linked list
            while ((current->next != nullptr) && !found) {
                //Case 4: Determine IF you can insert the 'newValue' at the given index/position inside the linked list
                if (index == position) {
                    //Evaluate if the new Node value is less than or equal to the currently
                    //pointed to Node value in the linked list
                    if ((newValue >= current->value) && (newValue < current->next->value)) {
                        found = true;
                        previous = current;
                        newNode->next = current->next;
                        current->next = newNode;
                        listLength++;
                        ++index;
                    }else{
                        cout << "Cannot insert " << newValue << " at location " << index << " because that would make the list unsorted!\n";
                        found = true;
                    }
                }else{//Iterate through the Nodes until you reach nullptr
                    //Change the pointer 'links' for the previous Node and the currently pointed to Node positions
                    previous = current;
                    current = current->next;
                    //WHEN you reach the end of the list, update the last pointer to point to the last Node in the linked list
                    if (current->next == nullptr) {
                        last = current;
                    }else{//IF you haven't reached the end of the list yet, increment the linked list index
                        ++index;
                    }
                }
                //Case 5: IF the current pointer is pointing to the last element in the linked list
                if (current->next == nullptr) {
                    //IF the given position is greater or equal to the listLength and the value is too small to be inserted at the end
                    if (position >= listLength && newValue < last->value) {
                        cout << "Cannot insert " << newValue << " at the end because that would make the list unsorted!\n";
                        found = true;
                    }else{//IF the 'newValue' is greater than or equal to the last element of the linked list
                        found = true;
                        previous = current;
                        newNode->next = current->next;
                        current->next = newNode;
                        last = newNode;//Insert the new Node at the end of the linked list
                        listLength++;
                        index++;
                    }
                }
            }
        }
    }
}
/**
 * This (private) class template helper member function copies the entire
 * LinkedList and preserves it's order.
 *
 * @param newList -- Node<T> *(pointer)
 * @return t -- Node<T> *(pointer)
 */
template <class T>
void LinkedList<T>::copyList(const LinkedList<T> &otherList) {
    //Dynamically Allocated pointers for creating new Nodes for a newly copied linked list
    Node<T> *newNode, *current, *last;
    int count = 0;//Integer variable for counting the # of Nodes

    //If the linked list is NOT empty, then make it empty
    if (head != nullptr)
        deleteList(); //Empty all the Nodes in the current linked list
    //IF the copied linked list is empty
    if (otherList.head == nullptr) {
        head = nullptr;
        last = nullptr;
    }
    else {//IF the new linked list is NOT empty
        //Set the currently pointed to Node, to the first Node in the referenced linked list to be copied
        current = otherList.head;
        //Dynamically Allocate and then copy the new head Node into the new linked list
        head = new Node<T>;
        head->value = current->value;//Copy the currently pointed to Node value(s)
        head->next = nullptr;//Set the linked field/next pointer of the Node to nullptr
        last = head;
        current = current->next;
        //Loop through the newly copied linked list and dynamically allocate memory for 
        //Node<T> values for that linked list. Preserve the ascending order of the entire 
        //linked list and copy it.
        while (current != nullptr) {
            newNode = new Node<T>;
            newNode->value = current->value;
            newNode->next = nullptr;
            last->next = newNode;
            last = newNode;
            current = current->next;
            count++;
        }
    }
}
/**
 * This (private) class template helper member function deallocates memory used by each Node
 * in a linked list. 
 *
 * @param none
 * @return none -- void
 */
template <class T>
void LinkedList<T>::deleteList() {
    //Pointer variable(s) used for deallocating memory used by each Node in a linked list
    Node<T> *temp, *last;
    int listLength = countNodes();
    //Loop through the linked list and exit only when the linked list head pointer is empty
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    //Set the pointers used to nullptr
    temp = nullptr;
    last = nullptr;
    listLength = 0;
}

#endif