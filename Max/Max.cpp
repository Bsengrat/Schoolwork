//****************************************************************************************************
//
//		File:					max.cpp
//		
//		Student:				Bently Sengrath
//
//		Assignment:	 			Program  # 2
//
//		Course Name:			Data Structures   I 
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					Sept 16, 2019
//
//
//		This program will use help in making a difference between overloaded and template functions.
//		 
//		
//****************************************************************************************************

#include <iostream>
#include <cstring>
#include <typeinfo>

using namespace std;

//****************************************************************************************************

template <typename type> 
void getData(type &var1, type &var2);
void getData(char var1[], char var2[]);
template <typename type>
type findMax(type var1, type var2);
char * findMax(char string1[], char string2[]);
template <typename type>
void displayMax(type var1, type var2, type max);

//****************************************************************************************************

int main()
{
	int ivar1, 
		ivar2, 
		maxInt;
	double dvar1, 
		   dvar2,
		   maxDouble;
	char cvar1, 
		 cvar2,
		 maxChar;
	char string1[50], 
		 string2[50],
		 * maxArray;

	getData(ivar1, ivar2);
	getData(dvar1, dvar2);
	getData(cvar1, cvar2);
	getData(string1, string2);
	maxInt = findMax(ivar1, ivar2);
	maxDouble = findMax(dvar1, dvar2);
	maxChar = findMax(cvar1, cvar2);
	maxArray = findMax(string1, string2);
	displayMax(ivar1, ivar2, maxInt);
	displayMax(dvar1, dvar2, maxDouble);
	displayMax(cvar1, cvar2, maxChar);
	displayMax(string1, string2, maxArray);

	return 0;
}

//****************************************************************************************************

template <typename type>
void getData(type &var1, type &var2)
{
	cout << "Enter 2 " << typeid(var1).name() << "s: ";
	cin >> var1 >> var2;
}

//****************************************************************************************************

template <typename type>
type findMax(type var1, type var2)
{
	if (var1 > var2)
	{
		return var1;
	}
	else
	{
		return var2;
	}
}

//****************************************************************************************************

void getData(char var1[], char var2[])
{
	cout << "Enter 2 Char Strings." << endl
		 << "Enter first string: ";
	cin.ignore();
	cin.getline(var1, 50);
	cout << "Enter Second string: ";
	cin.getline(var2, 50);
}

//****************************************************************************************************

char * findMax(char string1[], char string2[])
{
	if (strcmp(string1, string2) > 0)
	{
		return string1;
	}
	else
	{
		return string2;
	}
}

//****************************************************************************************************

template <typename type>
void displayMax(type var1, type var2, type max)
{
	cout << "The two values" << var1 << "\t" << var2 << endl
		 << "The max is: " << max << endl;
}

/*
Enter 2 ints: 5 56
Enter 2 doubles: 52.15 54.65
Enter 2 chars: z v
Enter two strings.
Enter first string:apple pies
Enter second string: apple dumplings
The two values: 5       56
The max is: 56
The two values: 52.15   54.65
The max is: 54.65
The two values: z       v
The max is: z
The two values: apple pies      apple dumplings
The max is: apple pies

D:\Data Structures I\Max\Debug\Max.exe (process 92) exited with code 0.
Press any key to close this window . . .
*/