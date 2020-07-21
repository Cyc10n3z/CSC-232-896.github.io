/*------------------------------------------------------------------------------------
 * Author:        Joy Adeyemo and John Lorette III
 * Date:          7/16/2020
 * Trace Folder:  LABS\Lab10\
 * File Name:     Lab10_Adeyemo_Joy_LoretteIII_John.cpp
 * Description:   C++ Program that tests out how queue's work using function templates.
 ------------------------------------------------------------------------------------*/
#include<iostream>
#include<iomanip>
#include<cassert>
#include<queue>//Queue Structure from the S.T.L.
#include<stack>//Stack Structure from the S.T.L.
using namespace std;

/************************************************************************************
*                         Function Template Prototype(s)                            *
*************************************************************************************/
template <class T> void display(queue<T>);					//O(n)
template <class T> void nToFront(queue<T> &, int);	        //O(n)
template <class T> void reverseUsingNtoFront(queue<T> &);   //O(n)
template <class T> void reverseQueue(queue<T> &);		    //O(n), with a queue & stack
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
void nToFront(queue<T> &q, int n) {
	//Variable(s) used for moving the N'th element of the queue to the front
	queue<T> temp;
	T element;
	int count = 1;

	//Make sure the queue is not empty!
	if (n > 0) {
		//Empty the queue<T> reference object 'q'
		while (!q.empty()) {
			//Push the front element into queue<T> object 'temp'
			temp.push(q.front());
			q.pop();//Remove the front element from 'q'
			count++;
			//When the N'th element is equal to the count of elements
			if (count == n) {
				element = q.front();//Store the N'th element
				q.pop();//Remove the N'th element
			}
		}
		q.push(element);//Push the N'th element to the front of the queue
		//Empty the queue<T> object 'temp' back into the reference object 'q'
		while (!temp.empty()) {
			q.push(temp.front());
			temp.pop();
		}
	}else{//IF the queue is empty...
		cout << "You can't move the element at " << n << " in an empty queue!\n";
	}
}
/**
 *	This function template uses the 'nToFront()' function to reverse the order of the
 *  elements in a generic type queue.
 *
 *	@param q -- queue<T>
 *  @return none -- void
 */
template <class T>
void reverseUsingNtoFront(queue<T> &q) {
	//Variable for reversing a queue<T> reference object using the function 'nToFront()'
	queue<T> temp;
	int i = (int)q.size();

	//Loop through the queue<T> reference object 'q' and use the 'nToFront()' function
	while (i > 1) {//While 'i' is greater than 1 and less than or equal to 'qSize'
		nToFront(q, i);
		temp.push(q.front());
		q.pop();
		i--;
	}
	//Loop through the queue<T> object 'temp' until it is empty
	while (!temp.empty()) {
		q.push(temp.front());
		temp.pop();
	}
	//Push to the back of the queue and then pop, the last element left in the queue
	q.push(q.front());
	q.pop();
}
/**
 *  This function template also does the same thing as the 'reverseUsingNtoFront()'
 *  function by using the 'nToFront()' function. This function accomplishes the
 *  same task with running time O(n).
 *
 *  @param q -- queue<T>
 *  @return none -- void
 */
template <class T>
void reverseQueue(queue<T> &q) {
	//stack<T> object 'Stack' for reversing a queue<T> reference object
	stack<T> temp;

	//Loop through the queue<T> reference object 'q' until it is empty
	while (!q.empty()) {
		temp.push(q.front());
		q.pop();
	}
	//Loop through the queue<T> object 'temp' until it is empty
	while (!temp.empty()) {
		q.push(temp.top());
		temp.pop();
	}
}
/************************************************************************************/