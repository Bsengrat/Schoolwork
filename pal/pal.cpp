//****************************************************************************************************
//
//		File:					pal.cpp
//		
//		Student:				Bently Sengrath
//
//		Assignment:	 			Program  # 10
//
//		Course Name:			Data Structures   I 
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					Nov, 23, 2019
//
//
//		This program will find if there are plaindromes in a text file.
//		 
//		
//****************************************************************************************************

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <iomanip>
using namespace std;
#include "stack.h"
#include "Queue.h"

//****************************************************************************************************

bool testNdisplayPal(Queue<char> & Qstring, Stack<char> & Sstring, int SIZE);
char getPalType(bool valspaceNoP, bool validpunct);
void displayPalResult(bool valid, char paltype);

//****************************************************************************************************

int main()
{
	bool valid,
		 valspaceNoP = false,
		 validpunct = false;

	char paltype = '1';
	const int SIZE = 50;
	char palstring[SIZE];

	Queue<char> Qstring;
	Stack<char> Sstring;
	ifstream fout;

	fout.open("palindromes.txt");


	while (fout.getline(palstring, 50, '#'))
	{
		int plength = strlen(palstring);

		for(int i =0; i < plength; i++)
		{
			if (!ispunct(palstring[i]) && !isspace(palstring[i]))
			{
				Sstring.push(tolower(palstring[i]));
				Qstring.enqueue(tolower(palstring[i]));
			}
		}

		valid = testNdisplayPal(Qstring, Sstring, SIZE);

		if (valid)
		{
			int x = 0;

			while (palstring[x] != '\0')
			{
				if (isspace(palstring[x]))
				{
					valspaceNoP = true;
				}

				if (ispunct(palstring[x]))
				{
					validpunct = true;
				}

				x++;
			}

			paltype = getPalType(valspaceNoP, validpunct);
		}

		displayPalResult(valid, paltype);
		valspaceNoP = false;
		validpunct = false;
	}


	return 0;
}

//****************************************************************************************************

bool testNdisplayPal(Queue<char> & Qstring, Stack<char> & Sstring, int size)
{
	char StackVal,
		 QueueVal;
	int tempcount = 0;

	bool success = true;

	while (Sstring.pop(StackVal))
	{
		Qstring.dequeue(QueueVal);

		if (StackVal != QueueVal)
		{
			success = false;
		}

		tempcount++;
		cout << StackVal;
	}

	tempcount = size - tempcount;
	cout << setw(tempcount);


	return success;
}

//****************************************************************************************************

char getPalType(bool valspaceNoP, bool validpunct)
{
	char palType = '1';

	if (validpunct)
	{
		palType = '3';
	}
	else if (valspaceNoP)
	{
		palType = '2';
	}

	return palType;
}

//****************************************************************************************************

void displayPalResult(bool valid, char paltype)
{
	if (valid)
	{
		if (paltype == '1')
		{
			cout << "type 1";
		}
		else if (paltype == '2')
		{
			cout  << "type 2";
		}
		else if (paltype == '3')
		{
			cout << "type 3";
		}
	}
	else
	{
		cout << "invalid";
	}

	cout << endl;
}

//****************************************************************************************************

/*
aha                                         type 3
isitiitisi                                  type 3
deed                                        type 1
srotor                                     invalid
neveroddoreven                              type 2
nolemonsnomelon                             type 3
racecar                                     type 2
cimoc                                      invalid
wasitacaroracatisaw                         type 3
yddad                                      invalid

C:\C++\PalinDromes\Debug\PalinDromes.exe (process 22312) exited with code 0.
Press any key to close this window . . .
*/