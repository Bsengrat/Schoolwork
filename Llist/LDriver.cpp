
//****************************************************************************************************
//
//		File:					LDriver.cpp
//		
//		Student:				Bently Sengrath
//
//		Assignment:	 			Program  # 1
//
//		Course Name:			Data Structures   I 
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					Oct 30, 2019
//
//
//		This program  will test the functions of the linked list.
//		 
//		
//****************************************************************************************************

#include<iostream>
using namespace std;
#include "List.h"

//****************************************************************************************************

int main()
{
	int value = 10,
		removeval = 4,
		val = 10,
		frontValue,
		backValue;
	
	LList<int> test;

	if (test.insert(value))
	{
		cout << "The value " << value << " was inserted into the list" << endl;
	}
	else
	{
		cout << "The value " << value << " was not able to be inserted into the list" << endl;
	}

	if (test.remove(val))
	{
		cout << "The value " << val << " was removed!" << endl;
	}
	else
	{
		cout << "the value was not able to be removed" << endl;
	}
	test.insert(4);

	if (test.retrieve(removeval))
	{
		cout << "The value " << removeval << " was retrieved!" << endl;
	}
	else
	{
		cout << "The value was not able to be retrieved." << endl;
	}
	
	if (test.remove(removeval))
	{
		cout << "The value " << removeval << " was removed!" << endl;
	}
	else
	{
		cout << "the value was not able to be removed" << endl;
	}

	test.insert(8);
	test.insert(2);
	test.insert(42);
	test.viewFront(frontValue);
	test.viewRear(backValue);

	test.display();
	
	cout << "The front value is: " << frontValue << endl
		 << "The rear value is: " << backValue << endl
		 << "The number of elements in list is: " << test.getNumValues() << endl;

	if (test.isEmpty())
	{
		cout << "\nThe list is empty" << endl;
	}
	else
	{
		cout << "\nThere are values in the list" << endl;
	}

	if (test.isFull())
	{
		cout << "The list is full" << endl;
	}
	else
	{
		cout << "The list is not full" << endl;
	}

	return 0;
}

//****************************************************************************************************

/*
The value 10 was inserted into the list
The value 10 was removed!
The value 4 was retrieved!
The value 4 was removed!
2 8 42 The front value is: 2
The rear value is: 42
The number of elements in list is: 3

There are values in the list
The list is not full

D:\Data Structures I\OLList\Debug\OLList.exe (process 12936) exited with code 0.
Press any key to close this window . . .
*/