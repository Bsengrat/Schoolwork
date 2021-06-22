//****************************************************************************************************
//
//		File:					Node.h
//		
//		Student:				Bently Sengrath
//
//		Assignment:	 			Program  # 1
//
//		Course Name:			Data Structures   I 
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					Nov, 10, 2019
//
//
//		This program has the member functions for the Queue Struture
//		 
//		
//****************************************************************************************************

#ifndef QUEUE_H
#define QUEUE_H
#include <new>
#include "Node.h"


//****************************************************************************************************

template <typename TYPE>
class Queue
{
    private:
		Node<TYPE> * front;
		Node<TYPE> * rear;
		int numValues;

    public:
		Queue();
		~Queue();

		bool enqueue(const TYPE & dataIn);
		bool dequeue(TYPE & dataOut);

		bool viewFront(TYPE & dataOut) const;
		bool viewRear(TYPE & dataOut) const;
		int getNumValues() const;

		bool isFull() const;
		bool isEmpty() const;

};

//****************************************************************************************************

template <typename TYPE>
Queue<TYPE>::Queue()
{
	front = nullptr;
	rear = nullptr;
	numValues = 0;
}

//****************************************************************************************************

template <typename TYPE>
Queue<TYPE>::~Queue()
{
	Node<TYPE> * pdel;

	while (front)
	{
		pdel = front;
		front = front->next;
		delete pdel;

	}

	rear = nullptr;
	numValues = 0;
}

//****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE>::enqueue(const TYPE & dataIn)
{
	bool success = false;
	Node<TYPE> * pNew;
	pNew = new (nothrow) Node<TYPE> (dataIn);

	if (pNew)
	{
		if (rear)
		{
			rear->next = pNew;
		}
		else
		{
			front = pNew;
		}

		rear = pNew;
		numValues++;
		success = true;
	}
	
	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE>::dequeue(TYPE & dataOut)
{
	bool success = false;
	Node<TYPE> * pDel = front;

	if (front)
	{
		dataOut = front->data;
		front = front->next;
		delete pDel;
		numValues--;
		success = true;

		if (numValues == 0)
		{
			rear = nullptr;
		}
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE>::viewFront(TYPE & dataOut) const
{
	bool success = false;

	if (front)
	{
		dataOut = front->data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE>::viewRear(TYPE & dataOut) const
{
	bool success = false;

	if (rear)
	{
		dataOut = rear->data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
int Queue<TYPE>::getNumValues() const
{
	return numValues;
}

//****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE>::isFull() const
{
	bool success = true;

	Node<TYPE> * pCheck;
	pCheck = new (nothrow) Node<TYPE>;
	
	if (pCheck)
	{
		success = false;
		delete pCheck;
	}

	return success;
}
//****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE>::isEmpty() const
{
	return (front == nullptr);
}

//****************************************************************************************************

#endif