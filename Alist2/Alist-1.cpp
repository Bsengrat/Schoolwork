
//****************************************************************************************************
//
//		File:					AList.cpp
//		
//		Student:				Bently Sengrath
//
//		Assignment:	 			Program  # 4
//
//		Course Name:			Data Structures   I 
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					Oct, 7, 2019
//
//
//		This program use the array list data structure
//		 
//		
//****************************************************************************************************

#include <iostream>
using namespace std;
#include "AList.h"

//****************************************************************************************************


int main()
{
	short min;
	short val;
	AList<short> test(3);

	if (test.insertFront(3))
	{
		test.display();
		test.getSmallest(min);
		cout << endl << "capacity is " << test.getCapacity() << "\t numValues is "
			<< test.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
	{
		cout << "Unable to insert the value 3";
	}

	if (test.insertAtIndex(0, 7))
	{
		test.display();
		test.getSmallest(min);
		cout << endl << "capacity is " << test.getCapacity() << "\t numValues is "
			<< test.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
	{
		cout << "Unable to insert the value 1" << endl;
	}

	if (test.insertBack(1))
	{
		test.display();
		test.getSmallest(min);
		cout << endl << "capacity is " << test.getCapacity() << "\t numValues is "
			<< test.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
	{
		cout << "Unable to insert the value r" << endl;
	}

	test.insertFront(1);
	cout << "new value inserted and New capacity: " << test.getCapacity() << endl;
	test.insertAtIndex(2, 4);
	cout << "All Values in Array List" << endl;
	test.display();

	if (test.updateFront(3))
	{
		cout << endl << "Updated data in list" << endl;
		test.display();
		cout << endl << "capacity is " << test.getCapacity() << "\t numValues is "
			<< test.getNumValues() << endl;
	}
	else
	{
		cout << "Could not update" << endl;
	}

	if (test.updateBack(6))
	{
		cout << endl << "Update data back value " << endl;
		test.display();
		cout << endl << "capacity is " << test.getCapacity() << "\t numValues is "
			<< test.getNumValues() << endl;
	}
	else
	{
		cout << "Could not update" << endl;
	}

	if (test.updateAtIndex(3, 8))
	{
		cout << endl << "Update data at index 3 value " << endl;
		test.display();
		cout << endl << "capacity is " << test.getCapacity() << "\t numValues is "
			<< test.getNumValues() << endl;
	}
	else
	{
		cout << "Could not update" << endl;
	}

	if (test.update(8))
	{
		cout << "Update at user value " << endl;
		test.display();
		cout << endl << "capacity is " << test.getCapacity() << "\t numValues is "
			<< test.getNumValues() << endl;
	}
	else
	{
		cout << "Could not update" << endl;
	}

	if (test.removeAtIndex(2, val))
	{
		cout << "removed at index value in list " << val
			<< "\tcapacity is " << test.getCapacity()
			<< "\tNumvalues is " << test.getNumValues() << endl;
	}
	else
	{
		cout << "Did not remove anything!!!" << endl;
	}

	test.display();

	if (test.removeBack(val))
	{
		cout << endl << "removed the back value in list " << val
			<< "\tcapacity is " << test.getCapacity()
			<< "\tNumvalues is " << test.getNumValues() << endl;
	}
	else
	{
		cout << "Did not remove anything!!!" << endl;
	}

	test.display();

	if (test.removeFront(val))
	{
		cout << endl << "removed the front value in list " << val
			<< "\tcapacity is " << test.getCapacity()
			<< "\tNumvalues is " << test.getNumValues() << endl;
	}
	else
	{
		cout << "Did not remove anything!!!" << endl;
	}

	val = 7;

	cout << "the valued that is being held right now: " << val << endl;

	if (test.remove(val))
	{
		cout << endl << "removed at user value in list " << val
			 << "\tcapacity is " << test.getCapacity()
			 << "\tNumvalues is " << test.getNumValues() << endl;
	}
	else
	{
		cout << "could not remove anything" << endl;
	}

	test.display();
	
	if (test.retrieveFront(val))
	{

		cout << "retrieved at front index value in list " << val
			 << "\tcapacity is " << test.getCapacity()
			 << "\tNumvalues is " << test.getNumValues() << endl;
	}
	else
	{
		cout << "could not retrieve the value" << endl;
	}

	if (test.retrieveBack(val))
	{

		cout << "retrieved at last index value in list " << val
			<< "\tcapacity is " << test.getCapacity()
			<< "\tNumvalues is " << test.getNumValues() << endl;
	}
	else
	{
		cout << "could not retrieve the value" << endl;
	}

	if (test.retrieveAtIndex(1, val))
	{

		cout << "retrieved at index value in list " << val
			<< "\tcapacity is " << test.getCapacity()
			<< "\tNumvalues is " << test.getNumValues() << endl;
	}
	else
	{
		cout << "could not retrieve the value" << endl;
	}

	val = 2;

	if (test.retrieve(val))
	{
		cout << "The retrieved value is " << val << endl;
	}
	else
	{
		cout << "Could not find the user value" << endl;
	}
	
	test.clear();

	if (test.remove(val))
	{
		cout << "There should not be anything to remove" << endl;
	}
	else
	{
		cout << "there is nothing to remove" << endl;
	}

	if (test.isFull())
	{
		cout << "The list is full" << endl;
	}

	if (test.isEmpty())
	{
		cout << "The list is empty" << endl;
	}

	return 0;
}

//****************************************************************************************************

/*
0       3

capacity is 3    numValues is 1  smallest value is 3
0       7
1       3

capacity is 3    numValues is 2  smallest value is 3
0       7
1       3
2       1

capacity is 3    numValues is 3  smallest value is 1
new value inserted and New capacity: 4
All Values in Array List
0       1
1       7
2       4
3       3
4       1

Updated data in list
0       3
1       7
2       4
3       3
4       1

capacity is 6    numValues is 5

Update data back value
0       3
1       7
2       4
3       3
4       6

capacity is 6    numValues is 5

Update data at index 3 value
0       3
1       7
2       4
3       8
4       6

capacity is 6    numValues is 5
Update at user value
0       3
1       7
2       4
3       8
4       6

capacity is 6    numValues is 5
removed at index value in list 4        capacity is 6   Numvalues is 4
0       3
1       7
2       8
3       8

removed the back value in list 6        capacity is 6   Numvalues is 3
0       3
1       7
2       8

removed the front value in list 3       capacity is 6   Numvalues is 2
the valued that is being held right now: 7

removed at user value in list 7 capacity is 6   Numvalues is 1
0       8
retrieved at front index value in list 8        capacity is 6   Numvalues is 1
retrieved at last index value in list 8 capacity is 6   Numvalues is 1
retrieved at index value in list 8      capacity is 6   Numvalues is 1
Could not find the user value
there is nothing to remove
The list is empty

C:\Users\Bseng\Downloads\Debug\Alist.exe (process 13796) exited with code 0.
Press any key to close this window . . .
*/