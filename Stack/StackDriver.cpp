//****************************************************************************************************
//
//		File:					StackDriver.cpp
//		
//		Student:				Bently Sengrath
//
//		Assignment:	 			Program  # 1
//
//		Course Name:			Data Structures   I 
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					Nov 4, 2019
//
//
//		This program  will test the functions in the stack.h
//		 
//		
//****************************************************************************************************

#include <iostream>
using namespace std;
#include "stack.h"

//****************************************************************************************************

int main()
{
	Stack<int> list1;
	int removeval;


	if (list1.push(5))
	{
		cout << "the values 5 was inserted" << endl;
	}
	else
	{
		cout << "the value could not be implemented" << endl;
	}

	if (list1.pop(removeval))
	{
		cout << "the value " << removeval << " was able to be removed from the stack" << endl;
	}
	else
	{
		cout << "the value was not able to removed" << endl;
	}

	list1.push(6);
	list1.push(88);
	list1.push(75);
	list1.push(3);
	list1.push(7);

	if (list1.peek(removeval))
	{
		cout << "the value " << removeval << " was able to be retrieved" << endl;
	}
	else
	{
		cout << "the value was not able to retrieved" << endl;
	}

	if ((list1.push(8)))
	{
		cout << "the values 8 was inserted" << endl;
	}
	else
	{
		cout << "the value could not be implemented" << endl;
	}

	if (list1.pop(removeval))
	{
		cout << "the value " << removeval << " was able to be removed from the stack" << endl;
	}
	else
	{
		cout << "the value was not able to removed" << endl;
	}

	cout << list1.getNumValues() + 1 << " is the number of values in the stack" << endl;

	if(list1.isFull())
	{ 
		cout << "The list is full" << endl;
	}
	else
	{
		cout << "The list is not filled to capacity" << endl;
	}

	if (list1.isEmpty())
	{
		cout << "The list is empty." << endl;
	}
	else
	{
		cout << "THe list is not empty." << endl;
	}

	return 0;
}

//****************************************************************************************************

/*
the values 5 was inserted
the value 5 was able to be removed from the stack
the value 7 was able to be retrieved
the value could not be implemented
the value 7 was able to be removed from the stack
4 is the number of values in the stack
The list is not filled to capacity
THe list is not empty.

C:\C++\Stack\Debug\Stack.exe (process 4768) exited with code 0.
Press any key to close this window . . .

*/