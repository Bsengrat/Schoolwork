//****************************************************************************************************
//
//		File:					defaultArgs.cpp
//		
//		Student:				Bently Sengrath
//
//		Assignment:	 			Program  # 1
//
//		Course Name:			Data Structures   I 
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					Sept 9, 2019
//
//
//		This program will call a single function displayMsg in four different ways default Args.
//		 
//		
//****************************************************************************************************

#include <iostream>
#include <cstring>

using namespace std;

void displayMsg(const char userMsg[50] = "Decide, Commit, Succeed.", char symbol = ' ', int num = 10);

//****************************************************************************************************

int main()
{
	displayMsg("I will decide.", '*', 15);
	displayMsg("I will commit.", '+');
	displayMsg("I will succeed.");
	displayMsg();

	return 0;
}

//****************************************************************************************************

void displayMsg(const char userMsg[], char symbol, int num )
{
	bool showmsg = false;
	for (int i = 0; i < num; i++)
	{
		cout << symbol;
	}
	cout << userMsg;
	for (int i = 0; i < num; i++)
	{
		cout << symbol;
	}
	cout << endl;
}

//****************************************************************************************************

/*
***************I will decide.***************
++++++++++I will commit.++++++++++
		  I will succeed.
		  Decide, Commit, Succeed.
*/
