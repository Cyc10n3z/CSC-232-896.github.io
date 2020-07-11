/*------------------------------------------------------------------------------------
 * Author:        Joy Adeyemo and John Lorette III
 * Date:          7/16/2020
 * Trace Folder:  LABS\Lab10\
 * File Name:     Lab10_Adeyemo_Joy_LoretteIII_John.cpp
 * Description:   C++ Program that tests out how queue's work, with function templates.
 ------------------------------------------------------------------------------------*/
#include<iostream>
#include<iomanip>
#include<cassert>
#include<queue>//Required for using queues
using namespace std;

/************************************************************************************
*                         Function Template Prototype(s)                            *
*************************************************************************************/
template <class T> void display(queue<T>);                  //Completed!
template <class T> void nToFront(queue<T>, int);			//In Progress...
template <class T> void reverseUsingNtoFront(queue<T>);		//In Progress...
template <class T> void reverseQueue(queue<T>);				//In Progress...
/************************************************************************************
*                  The programs main method, or control function                    *
*************************************************************************************/
int main() {
	//Create and Instantiate a queue object 'q'
	queue<int> q;

	//Loop through the queue and 'push' the values 1 through 10 into the queue
	for (int i = 1; i <= 10; i++)
		q.push(i);

	//Display the initial contents of the queue
	cout << "Initial content of queue: " << endl;
	display(q);
	//Call the 'nToFront' function with the queue and update the displayed contents
	nToFront(q, 3);//Move the 3rd element to the front of the queue
	cout << "Queue after calling nToFront(q, 3): " << endl;
	display(q);
	//Call the 'reverseUsingNtoFront' function with the queue and update the displayed contents
	reverseUsingNtoFront(q);
	cout << "Queue after calling reverseUsingNtoFront(q): " << endl;
	display(q);
	//Call the 'reverseQueue' function with the queue and update the displayed contents
	reverseQueue(q);
	cout << "Queue after calling reverseQueue(q): " << endl;
	display(q);

	//Exit the main function, with 0 indicating success
	return 0;
}

/************************************************************************************
*                           Function Template Definitions                           *
*************************************************************************************/
/**
 *	This function template displays by printing to the screen, all the elements of 
 *  a generic type queue separated by spaces.
 *
 *	@param q -- queue<T>
 *  @return none -- void
 */
template <class T>
void display(queue<T> q) {
	//Loop through the queue<T> object parameter and display the contents while it isn't empty
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}
/**
 *	This function template moves the N'th element of the queue to the front and leaving
 *  the order of all the other elements unchanged.
 *
 *	@param q, n -- queue<T>, int
 *  @return none -- void
 */
template <class T>
void nToFront(queue<T> q, int n) {
	//queue<T> pointers for the front and back of the 'queue' structure
	queue<T> *front = 0, *back = 0;
	int count = 0;

	//Loop to traverse the queue<T> object with two pointers until it's empty
	while (!q.empty()) {
		//IF the N'th element of the queue is found, move it to the front
		if (count == n) {
			
		}
		//
		
		count++;
	}
}
 /**
  *	 This function template uses the 'nToFront()' function to reverse the order of the
  *  elements in a generic type queue.
  *
  *	 @param q -- queue<T>
  *  @return none -- void
  */
template <class T>
void reverseUsingNtoFront(queue<T> q) {
	//queue<T> pointers for the front and back of the 'queue' structure
	queue<T> *front, *back;

	//




}
  /**
   *  This function template also does the same thing as the 'reverseUsingNtoFront()'
   *  function by using the 'nToFront()' function. However, this function accomplishes
   *  the same task with running time O(n).
   *
   *  @param q -- queue<T>
   *  @return none -- void
   */
template <class T>
void reverseQueue(queue<T> q) {
	//queue<T> pointers for the front and back of the 'queue' structure
	queue<T> *front, *back;

	//






}
/************************************************************************************/