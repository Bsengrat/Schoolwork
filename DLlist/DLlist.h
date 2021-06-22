//****************************************************************************************************
//
//		File:					DLList.h
//		
//		Student:				Bently Sengrath
//
//		Assignment:	 			Program  # 11
//
//		Course Name:			Data Structures   I 
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					Dec 20, 2019
//
//
//		This program will create the doubly linked list class
//		 
//		
//****************************************************************************************************


#include <new>
#ifndef DLLIST_H
#define DLLIST_H
#include "Node.h"

//****************************************************************************************************

template <typename TYPE>
class DLList
{
private:

	Node<TYPE> * front;
	Node<TYPE> * rear;

public:

	DLList();
	~DLList();

	bool insert(const TYPE & dataIn);
	bool remove(TYPE & dataOut);
	bool retrieve(TYPE & dataOut) const;
	bool viewFront(TYPE & dataOut) const;
	bool viewRear(TYPE & dataOut) const;

	void display() const;
	void displayReverse() const;
	int getNumValues() const;
	bool isEmpty() const;
	bool isFull() const;
};

//****************************************************************************************************

template <typename TYPE>
DLList<TYPE>::DLList()
{
	front = nullptr;
	rear = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
DLList<TYPE>::~DLList()
{
	Node<TYPE> * ptemp;

	while (front)
	{
		ptemp = front;
		front = front->next;
		delete ptemp;
	}

	delete front;
	front = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE>::insert(const TYPE & dataIn)
{
	bool success = false;

	Node<TYPE> * pBefore = nullptr;
	Node<TYPE> * pAfter = front;
	Node<TYPE> * pTemp;

	while ((pAfter) && ((pAfter->data) < (dataIn)))
	{
		pAfter = pAfter->next;
	}

	if (pAfter)
	{
		pBefore = pAfter->prev;
	}
	else
	{
		pBefore = rear;
	}

	pTemp = (new (nothrow) Node<TYPE>(dataIn, pAfter, pBefore));

	if (pTemp)
	{
		if (pBefore)
		{
			pBefore->next = pTemp;
		}
		else
		{
			front = pTemp;
		}

		if (pAfter)
		{
			pAfter->prev = pTemp;
		}
		else
		{
			rear = pTemp;
		}

		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE>::remove(TYPE & dataOut)
{
	bool success = false;

	Node<TYPE> * pDel = front;

	while ((pDel) && pDel->data < dataOut)
	{
		pDel = pDel->next;
	}

	if ((pDel) && (pDel->data == dataOut))
	{
		dataOut = pDel->data;

		if (pDel->prev)
		{
			(pDel->prev)->next = pDel->next;
		}
		else
		{
			front = pDel->next;
		}

		if (pDel->next)
		{
			(pDel->next)->prev = pDel->prev;
		}
		else
		{
			rear = pDel->next;
		}

		success = true;
		delete pDel;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE>::retrieve(TYPE & dataOut) const
{
	bool success = false;


	Node<TYPE> * pAfter = front;

	while ((pAfter) && (pAfter->data < dataOut))
	{
		pAfter = pAfter->next;
	}

	if ((pAfter) && (pAfter->data == dataOut))
	{
		dataOut = pAfter->data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE>::viewFront(TYPE & dataOut) const
{
	bool success = false;
	Node<TYPE> * pfront = front;

	if (pfront)
	{
		dataOut = pfront->data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE>::viewRear(TYPE & dataOut) const
{
	bool success = false;
	Node<TYPE> * ptemp = nullptr;

	if (rear)
	{
		dataOut = rear->data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
void DLList<TYPE>::display() const
{
	Node<TYPE> * ptemp = front;

	while (ptemp)
	{
		cout << ptemp->data;
		ptemp = ptemp->next;
	}
}

//****************************************************************************************************

template <typename TYPE>
void DLList<TYPE>::displayReverse() const
{
	Node<TYPE> * pRev = rear;
	
	while (pRev)
	{
		cout << pRev->data;
		pRev = pRev->prev;
	}
}

//****************************************************************************************************

template <typename TYPE>
int DLList<TYPE>::getNumValues() const
{
	int counter = 0;
	Node<TYPE> * ptemp = front;

	while (ptemp)
	{
		counter++;
		ptemp = ptemp->next;
	}

	return counter;
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE>::isEmpty() const
{
	return (front == nullptr);
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE>::isFull() const
{
	bool success = false;
	Node<TYPE> * pTemp;

	pTemp = new (nothrow) Node<TYPE>();
	if (pTemp)
	{
		delete pTemp;
		success = true;
	}

	return success;
}
//****************************************************************************************************

#endif
