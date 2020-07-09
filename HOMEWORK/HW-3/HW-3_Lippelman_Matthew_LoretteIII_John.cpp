/*------------------------------------------------------------------------------------
 * Author:        Matthew Lippelman and John Lorette III
 * Date:          7/10/2020
 * Trace Folder:  HOMEWORK\HW-3\
 * File Name:     HW-3_Lippelman_Matthew_LoretteIII_John.cpp
 * Description:   C++ Program that demonstrates a dynamica implementation of a stack
 *                template using doubly linked lists. A Node in a doubly linked list
 *                stores a link to the node before it and a link to the node after it.
 ------------------------------------------------------------------------------------*/
#include<iostream>
#include<iomanip>
#include<cassert>
using namespace std;

/************************************************************************************
*                    'StackNode' Structure Template Definition                      *
*************************************************************************************/
template <class T>
struct StackNode
{
    T data;                 //The data stored in a Node
    StackNode<T> *top;      //Link to the Node on top of this Node
    StackNode<T> *bottom;   //Link to the Node below this Node
}; 
/************************************************************************************
*                       'Stack' Class Template Definition                           *
*************************************************************************************/
template <class T>
class Stack
{
private:
    //Pointer to the Node at the top of the Stack
    StackNode<T> *head;
    //Helper Function 1 -- Copy/Preserve the current Stack
    void copyStack(const Stack<T> &);
    //Helper Function 2 -- Destroy/Empty the current Stack
    void deleteStack();
public:
    //Default Constructor
    Stack(){
        head = nullptr;
    };
    //Copy Constructor
    Stack(const Stack<T> &otherStack){
        head = nullptr;
        copyStack(otherStack);
    }
    //Destructor
    ~Stack() {
        deleteStack();//Call the helper function 'deleteStack()'
    }
    //Stack Member Functions Added
    const Stack<T>& operator=(const Stack<T>&);//Overloaded Assignment Operator
    bool isEmpty();
    T top();
    void pop();
    //Stack Member Functions Provided
    void displayStack();
    void push(T);
};
/************************************************************************************
*              'Stack' Class Template: Member Function Implementations              *
*************************************************************************************/
/**
 * This class template (private) helper function makes an identical copy of a Stack
 * that is passed to the copy constructor, and then this function.
 *
 * @param otherList -- constant Stack<T> &  
 * @return none -- void
 */
template<class T>
void Stack<T>::copyStack(const Stack<T> &otherStack) {
    //Pointer variable(s) for deep copying a referenced Stack object
    StackNode<T> *newNode, *current, *last;
    //IF the current Stack is not empty, make it empty
    if (head != nullptr) {
        deleteStack();
    }
    //IF the other Stack is empty, make the current one also empty
    if (otherStack.head == nullptr) {
        head = nullptr;
    }else{
        //Set the currently pointed to Stack, to the Stack that will be copied
        current = otherStack.head;
        //Dynamically allocate memory and copy the head element of the Stack
        head = new StackNode<T>;
        head->data = current->data;
        //Set the head element link field of the StackNode to nullptr
        head->top = nullptr;
        //Set the last Node pointer to link to the head of the Stack
        last = head;
        //Update the currently pointed to StackNode in 'otherStack', with the bottom linked StackNode
        current = current->bottom;

        //Loop for copying the remaining Stack>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        while (current != nullptr) {
            //Dynamically allocate memory for a 'newNode' to copy to, from 'otherStack'
            newNode = new StackNode<T>;
            newNode->data = current->data;//Copy the currently pointed to StackNode in otherStack
            newNode->bottom = nullptr;//Set the bottom link of newNode to nullptr
            //Update the bottom link of the last pointed to StackNode to be the newNode
            last->bottom = newNode;
            last = newNode;
            //Update the currently pointed to StackNode in 'otherStack', with the bottom linked StackNode
            current = current->bottom;
        }
    }
}
/**
* This class template (private) helper function uses a temporary StackNode<T> pointer to iterate
* through the list and deallocate the memory of each StackNode.
*
* @param none
* @return none -- void
*/
template <class T>
void Stack<T>::deleteStack() {
    //Pointer variable for deleting Nodes found inside the Stack
    StackNode<T> *tempNode;
    //While there are still elements found in the Stack
    while (head != nullptr) {
        tempNode = head;
        head = head->bottom;
        //Deallocate memory used by the tempNode
        delete tempNode;
    }
}
/**
* This class template function overrides the assignment operator so the assigment operator
* may be used to assign one Stack object to another.
*
* @param other -- constant Stack<T> &
* @return Stack<T>
*/
template <class T>
const Stack<T>& Stack<T>::operator=(const Stack<T> &other) {
    //IF the current Stack<T> object is not equal to the '&other' Stack<T> object
    if (this != &other) {
        copyStack(other);//Make a copy of the '&other' Stack
    }
    //return what is pointed to by the current Stack<T> object
    return *this;
}
/**
 * This class template member function determines if the current Stack is empty or not.
 * 
 * @param none
 * @return empty -- bool
 */
template<class T>
bool Stack<T>::isEmpty(){
    return (head == nullptr);
}
/**
 * This class template member function uses the 'assert' function to make sure the Stack
 * is not empty before returning the value stored at the top of the Stack.
 *
 * @param none
 * @return top -- T
 */
template<class T>
T Stack<T>::top() {
    //Make sure the head element of the Stack is not pointing to nullptr
    assert(head != nullptr);//Terminate program if the stack is empty
    //Return the T value stored at the top of the Stack
    return head->data;
}
/**
 * This class template member function removes the StackNode<T> at the top of the Stack.
 * If the Stack is empty, print to the screen an error message.
 * 
 * @param none
 * @return none -- void
 */
template<class T>
void Stack<T>::pop(){
    //Pointer variable for iterating through the StackNode<T>'s in a Stack
    StackNode<T> *tempNode;
    //IF the Stack is not empty...Else cout an error
    if (head != nullptr) {
        //Remove the StackNode<T> at the top of the Stack
        tempNode = head;
        head = head->bottom;
        //Delete the dynamically allocated memory at the pointed to tempNode
        delete tempNode;
    } else {
        cout << "\nCannot remove item from an empty stack." << endl;
    }
}
/**
 * This class template member function displays the information stored in the Stack.
 *
 * @param none
 * @return none -- void
 */
template<class T>
void Stack<T>::displayStack()
{
    //Pointer to traverse the Stack
    StackNode<T>* p;
    //Point to the head 'StackNode' of the Stack
    p = head;
    //While you haven't reached the end of the Stack
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->bottom;
    }
    cout << endl;
}
/**
 * This class template member function 'pushes' a given T value onto the
 * top element of the Stack.
 *
 * @param newValue -- T
 * @return none -- void
 */
template<class T>
void Stack<T>::push(T newValue)
{
    StackNode<T>* newNode;//Pointer to a 'newNode'

    //Dynamically allocate memory for 'newNode' to store the 'newValue'
    newNode = new StackNode<T>;
    newNode->data = newValue;
    newNode->top = nullptr;
    newNode->bottom = head;//This works even if head is nullptr
    //IF the stack is empty
    if (head == nullptr) {
        head = newNode;
    }
    else {
        head->top = newNode;
        head = newNode;
    }
}
/************************************************************************************/

/************************************************************************************
*                  The programs main method, or control function                    *
*************************************************************************************/
int main(){
    //Create an int Stack 's1'
    Stack<int> s1;

    //Use a loop to push 5 elements onto the Stack
    for (int i = 1; i <= 5; i++) {
        s1.push(i);
    }
    s1.displayStack();
    //Use a loop to 
    while(!s1.isEmpty()){
        int value = s1.top();
        cout << value << endl;//Output the top element in the Stack
        s1.pop();//Remove/pop the top element in the Stack
    }
    
    //Create a string Stack 's2'
    Stack<string> s2;
    s2.push("Mark");
    s2.push("John");
    s2.push("Eric");
    cout << "\nContents of s2: ";
    s2.displayStack();

    //Testing the copy constructor
    cout << "\nTesting the copy constructor" << endl;
    Stack<string> s3(s2);//Initialize the Stack 's3' with the Stack 's2'
    cout << "Contents of s3: ";
    s3.displayStack();

    //Testing the overloaded assignment operator
    cout << "\nTesting the overloaded assignment operator" << endl;
    Stack<string> s4;//Create a string Stack 's4'
    s4 = s2;
    cout << "Contents of s4: ";
    s4.displayStack();
    
    //Display the contents of the string Stack 's4' after two "pops" and one "push"
    s4.pop();
    s4.pop();
    s4.push("David");
    cout << "\nContents of s4 after two pops and one push: ";
    s4.displayStack();

    //Exit the main function, with 0 indicating success
    return 0;
}