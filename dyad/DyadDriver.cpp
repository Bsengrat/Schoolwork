//****************************************************************************************************
//
//		File:					Dyad.h
//		
//		Student:				Bently Sengrath
//
//		Assignment:	 			Program  # 3
//
//		Course Name:			Data Structures   I 
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					Sept 19, 2019
//
//
//		This program will implment class templates
//		 
//		
//****************************************************************************************************

#include "Dyad.H"
#include <iostream>

using namespace std;

//****************************************************************************************************

int main()
{
	int val1,
		val2;
	double val3,
		   val4;
	char val5,
		 val6;

	Dyad<int>test1(7, 5);
	val1 = test1.getFirst();
	val2 = test1.getSecond();
	cout << "the original values for test 1: " << val1 << " " << val2 << endl;
	test1.swapValues();
	test1.get2Values(val1, val2);
	cout << "the swapped values for test 1: " << val1 << " " << val2 << endl;

	Dyad<double> test2(85.24487, 99.23547);
	val3 = test2.getFirst();
	val4 = test2.getSecond();
	cout << "the original values for test 2: " << val3 << " " << val4 << endl;
	test2.swapValues();
	test2.get2Values(val3, val4);
	cout << "the swapped values for test 2: " << val3 << " " << val4 << endl;

	Dyad<char>test3('a', 'v');
	val5 = test3.getFirst();
	val6 = test3.getSecond();
	cout << "the original values for test 3: " << val5 << " " << val6 << endl;
	test3.swapValues();
	test3.get2Values(val5, val6);
	cout << "the swapped values for test 3: " << val5 << " " << val6 << endl;

	return 0;
}

//****************************************************************************************************

/*
the original values for test 1: 7 5
the swapped values for test 1: 5 7
the original values for test 2: 85.2449 99.2355
the swapped values for test 2: 99.2355 85.2449
the original values for test 3: a v
the swapped values for test 3: v a

D:\Data Structures I\Dyad\Debug\Dyad.exe (process 7564) exited with code 0.
Press any key to close this window . . .
*/