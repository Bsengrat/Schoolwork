//****************************************************************************************************
//
//		File:					List.h
//		
//		Student:				Bently Sengrath
//
//		Assignment:	 			Program  # 6
//
//		Course Name:			Data Structures   I 
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					Oct 30, 2019
//
//
//		This program  will modify the linked list
//		 
//		
//****************************************************************************************************

#include <new>
#ifndef LIST_H
#define LIST
#include "Node.h"

//****************************************************************************************************

template <typename TYPE>
class LList
{
private:

	Node<TYPE> * front;

public:

	LList();
	~LList();

	bool insert(const TYPE & dataIn);
	bool remove(TYPE & dataOut);
	bool retrieve(TYPE & dataOut) const;
	bool viewFront(TYPE & dataOut) const;
	bool viewRear(TYPE & dataOut) const;

	void display() const;
	int getNumValues() const;
	bool isEmpty() const;
	bool isFull() const;
};

//****************************************************************************************************

template <typename TYPE>
LList<TYPE>::LList()
{
	front = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
LList<TYPE>::~LList()
{
	delete front;
	front = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
bool LList<TYPE>::insert(const TYPE & dataIn)
{
	bool success = false;

	Node<TYPE> * pBefore = nullptr;
	Node<TYPE> * pAfter = front;
	Node<TYPE> * pTemp;

	while ((pAfter) && ((pAfter->data) < (dataIn)))
	{
		pBefore = pAfter;
		pAfter = pAfter->next;
	}

	pTemp = (new (nothrow) Node<TYPE>(dataIn, pAfter));

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
		
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool LList<TYPE>::remove(TYPE & dataOut)
{
	bool success = false;

	Node<TYPE> * pBefore = nullptr;
	Node<TYPE> * pAfter = front;

	while ((pAfter) && pAfter->data < dataOut)
	{
		pBefore = pAfter;
		pAfter = pAfter->next;
	}

	if ((pAfter) && (pAfter->data == dataOut))
	{
		if (pBefore)
		{
			dataOut = pAfter->data;
			pBefore->next = pAfter->next;
			delete pAfter;
		}
		else
		{
			front = pAfter->next;
		}
		
		success = true;
	}
	
	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool LList<TYPE>::retrieve(TYPE & dataOut) const
{
	bool success = false;

	Node<TYPE> * pBefore = nullptr;
	Node<TYPE> * pAfter = front;

	while ((pAfter) && (pAfter->data < dataOut))
	{
		pBefore = pAfter;
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
bool LList<TYPE>::viewFront(TYPE & dataOut) const
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
bool LList<TYPE>::viewRear(TYPE & dataOut) const
{
	bool success = false;
	Node<TYPE> * ptemp = front;

	while ((ptemp) && ((ptemp->next) != nullptr))
	{
		ptemp = ptemp->next;
	}

	if (ptemp && ptemp->next == nullptr)
	{
		dataOut = ptemp->data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
void LList<TYPE>::display() const
{
	Node<TYPE> * ptemp = front;
	
	while (ptemp)
	{
		cout << ptemp->data << " ";
		ptemp = ptemp->next;
	}
}

//****************************************************************************************************

template <typename TYPE>
int LList<TYPE>::getNumValues() const
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
bool LList<TYPE>::isEmpty() const
{
	return (front == nullptr);
}

//****************************************************************************************************

template <typename TYPE>
bool LList<TYPE>::isFull() const
{
	bool success = true;
	Node<TYPE> * pTemp;

	pTemp = (new (nothrow) Node<TYPE>());

	if (pTemp)
	{
		delete pTemp;
		success = false;
	}

	return success;
}

//****************************************************************************************************

#endif