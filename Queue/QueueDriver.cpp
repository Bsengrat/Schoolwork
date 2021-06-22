//****************************************************************************************************
//
//		File:					QueueDriver.cpp
//		
//		Student:				Bently Sengrath
//
//		Assignment:	 			Program  # 8
//
//		Course Name:			Data Structures   I 
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					Nov, 10, 2019
//
//
//		This program  will test the Queue member Functions
//		 
//		
//****************************************************************************************************

#include<iostream>
using namespace std;
#include "Queue.h"

//****************************************************************************************************

int main()
{
	Queue<int> list1;
	int frontVal,
		rearVal,
		remVal;

	list1.enqueue(1);
	list1.enqueue(9);
	list1.enqueue(45);
	list1.enqueue(777);
	list1.viewFront(frontVal);
	list1.viewRear(rearVal);
	cout << "the front of the queue is " << frontVal << "! " << endl
		<< "The back value of queue is " << rearVal << "!" << endl;
	list1.dequeue(remVal);
	list1.viewFront(frontVal);
	cout <<"the new front of the queue is " << frontVal << "! " << endl 
		 << "The  new back value of queue is " << rearVal << "!" << endl;
	cout << "The removed value is " << remVal << endl
		 << "The number of items in the queue is " << list1.getNumValues() << endl;

	if (list1.isFull())
	{
		cout << "the queue is full" << endl;
	}
	else
	{
		cout << "The queue is not full" << endl;
	}

	if (list1.isEmpty())
	{
		cout << "the list is empty" << endl;
	}
	else
	{
		cout << "the list is not Empty" << endl;
	}

	return 0;

}

/*
the front of the queue is 1!
The back value of queue is 777!
the new front of the queue is 9!
The  new back value of queue is 777!
The removed value is 1
The number of items in the queue is 3
The queue is not full
the list is not Empty

C:\AppNotes\Project1\Debug\Queue.exe (process 10264) exited with code 0.
Press any key to close this window . . .
*/
