//****************************************************************************************************
//
//		File:					rpn.cpp
//		
//		Student:				Bently Sengrath
//
//		Assignment:	 			Program  # 9
//
//		Course Name:			Data Structures   I 
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					Nov 18, 2019
//
//
//		This program  will use the stack data structure
//		 
//		
//****************************************************************************************************

#include "stack.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


//****************************************************************************************************

void outputToken(char token [], ofstream & resultsfile);
void processNumber(Stack<int> & q1, char token [], ofstream & resultsfile);
bool processOperator(Stack<int> & q1,char operate, ofstream & resultsfile);
void displayResult(Stack<int> & q1, ofstream & resultsfile, bool isval);
void resetFlagStack(Stack<int> & q1, bool & isVal);

//****************************************************************************************************

int main()
{
	ifstream fin;
	ofstream fout;
	Stack<int> s1;
	const int size = 10;
	char token [size];
	bool isVal = true;

	fin.open("expressions.txt");

	if (fin.is_open())
	{
		fout.open("Results.txt");

		if (fout.is_open())
		{

			while (fin >> token)
			{
				outputToken(token, fout);

				if (token[0] == ';')
				{
					displayResult(s1, fout, isVal);
					resetFlagStack(s1, isVal);
				}
				else if (isVal && isdigit(token[0]))
				{
					processNumber(s1, token, fout);
				}
				else if (isVal && !isalnum(token[0]))
				{
					isVal = processOperator(s1, token[0], fout);
				}
			}
		}
		else
		{
			cout << "Error opening File" << endl;
		}

		fin.close();
		fout.close();
	}
	else
	{
		cout << "Was not able to open the file!" << endl;
	}


	return 0;
}

//****************************************************************************************************

void outputToken(char token [], ofstream & resultsfile)
{
	resultsfile << endl << "(Token: " << token << " ) \t\t";

	if (token[0] != ';')
	{
		cout << token << " ";
	}
}

//****************************************************************************************************

void processNumber(Stack<int> & q1, char token [], ofstream & resultsfile)
{
	int iVal;

	iVal = atoi(token);
	q1.push(iVal);
	resultsfile << "push " << token;
}

//****************************************************************************************************

bool processOperator(Stack<int> & q1, char token, ofstream & resultsfile)
{
	bool success = false;

	int val1,
		val2,
		total;

	if (q1.pop(val2) && q1.pop(val1))
	{
		success = true;

		switch (token)
		{
		case '+':
			total = val1 + val2;
			break;
		case  '-':
			total = val1 - val2;
			break;
		case '*':
			total = val1 * val2;
			break;
		case '/':
			total = val1 / val2;
			break;
		case '%':
			total = val1 % val2;
			break;
		}
		q1.push(total);
		resultsfile << "pop  " << val1 << "\t\tPop " << val2 << "\t\tPush " << total;
	}

	return success;
}

//****************************************************************************************************

void displayResult(Stack<int> & q1, ofstream & resultsfile, bool isVald)
{
	int finalVal;
	int checknums = 1;

	if (isVald)
	{
		if (q1.getNumValues() > checknums)
		{
			cout << "\t\tInvalid" << endl;
			resultsfile << "\n\t\t\t\tInvalid RPN expression - too many operands" << endl;
		}
		else
		{
			q1.pop(finalVal);

			cout << " = " << finalVal << endl;
			resultsfile << "Pop  " << finalVal << endl
				<< "\t\t\t\tValid: result = " << finalVal << endl << endl;
		}
	}
	else
	{
		cout << "\t\tInvalid" << endl;
		resultsfile << "\n\t\t\t\tInvalid RPN expression - not enough operands" << endl;
	}



}

//****************************************************************************************************

void resetFlagStack(Stack<int> & q1, bool & isVal)
{
	int tempdel;

	while (q1.pop(tempdel));

	isVal = true;
}

//****************************************************************************************************

/*
2 4 * 5 +  = 13
13 5 % 5 +  = 8
15 1 + 2 / 1 -  = 7
15 + 1 + 2 / 1 -                Invalid
3 4 + 15 10 - *  = 35
3 4 + 6 15 10 - *               Invalid
2 13 + 14 6 - - 5 * 4 +  = 39
35 6 4 2 2 / + * -  = 5
3 4 + 1 2 - * 4 2 / 3 - +  = -8
3 14 1 2 4 2 3 + % * + - +  = 8

D:\Data Structures I\RPN Expressions\Debug\RPN Expressions.exe (process 24080) exited with code 0.
Press any key to close this window . . .
*/