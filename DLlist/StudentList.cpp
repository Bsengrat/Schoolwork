//****************************************************************************************************
//
//		File:					Student.h
//		
//		Student:				Bently Sengrath
//
//		Assignment:	 			Program  # 6
//
//		Course Name:			Data Structures   I 
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					Dec 2, 2019
//
//
//		This program will create overloaded student header file
//		 
//		
//****************************************************************************************************

#include <iostream>
#include<fstream>
#include <cstring>
#include <iomanip>

using namespace std;

#include "Student.h"
#include "DLlist.h"

//****************************************************************************************************

char getChoice();
void process(DLList<Student> & data);
void buildList(DLList<Student> & data);
void displayStudents(DLList<Student> & data);
void displayStudentsRev(DLList<Student> & data);

void countStudents(DLList<Student> & data);
void addNewStudent(DLList<Student> & data);
void removeStudent(DLList<Student> & data);
void findStudent(DLList<Student> & data);

//****************************************************************************************************

int main()
{
	DLList<Student> studentList;

	buildList(studentList);
	process(studentList);

	return 0;
}

//****************************************************************************************************

char getChoice()
{
	char choice;
	bool valid;

	cout << left << setw(10) << "=================Menu==================" << endl
		<< "A: Add a new Student " << endl
		<< "F: Find a Student Record " << endl
		<< "R: Remove Student Record " << endl
		<< "C: Count the Student List" << endl
		<< "D: Display Student Record in reverse Order " << endl
		<< "Q: Quit " << endl << endl
		<< "Enter your choice: ";

	do
	{
		cin >> choice;
		choice = toupper(choice);

		switch (choice)
		{
		case 'A':
		case 'F':
		case 'R':
		case 'C':
		case 'D':
		case 'Q':
			valid = true;
			break;
		default:
			valid = false;
			cout << "\aInvalid choice\n"
				 << "Please Try again: ";
			break;
		}
	} 
	while (!valid);

	return choice;
}

//****************************************************************************************************

void process(DLList<Student> & studentList)
{
	char choice;

	do
	{
		choice = getChoice();
		switch (choice)
		{
		case 'A':
			addNewStudent(studentList);
			break;
		case 'F':
			findStudent(studentList);
			break;
		case 'R':
			removeStudent(studentList);
			break;
		case 'C':
			countStudents(studentList);
			break;
		case 'D':
			displayStudentsRev(studentList);
			break;
		case 'Q':
			break;
		}
	} 
	while (choice != 'Q');

}

//****************************************************************************************************

void buildList(DLList<Student> & studentList)
{
	Student student;
	ifstream studentData;

	studentData.open("studentFile.txt");

	while (studentData >> student.id)
	{
		studentData.ignore();
		studentData.getline(student.name, 50);
		studentData.getline(student.citystate, 50);
		studentData >> student.phone
					>> student.gender
					>> student.year
					>> student.credits
					>> student.gpa
					>> student.major;

		studentList.insert(student);
	}

	studentData.close();
}

//****************************************************************************************************

void displayStudents(DLList<Student> & studentList)
{
	studentList.display();
}

//****************************************************************************************************

void displayStudentsRev(DLList<Student> & studentList)
{
	cout << setw(10) << "\tReverse Student List" << endl
		 << "================================================" << endl
		 << "ID" << "\tNAME" << "\t\t\t  MAJOR" << "\t    GPA" << endl
		 << "================================================" << endl;
	studentList.displayReverse();
}

//****************************************************************************************************

void countStudents(DLList<Student> & studentList)
{
	cout << "The Number of Students: " << studentList.getNumValues() << endl;
}

//****************************************************************************************************

void addNewStudent(DLList<Student> & studentList)
{
	Student student;

	cout << "Enter Student ID: ";
	cin >> student.id;
	cin.ignore();
	cout << "Enter Student Name: ";
	cin.getline(student.name, 50);
	cout << "Enter City And State: ";
	cin.getline(student.citystate, 50);
	cout << "Enter Phone Number: ";
	cin >> student.phone;
	cout << "Enter Gender: ";
	cin >> student.gender;
	cout << "Enter School Year: ";
	cin >> student.year;
	cout << "enter Credits: ";
	cin >> student.credits;
	cout << "Enter Student GPA: ";
	cin >> student.gpa;
	cout << "Enter Student Major: ";
	cin >> student.major;

	if (studentList.insert(student))
		cout << "New student added: " << student << endl;
	else
		cout << "Student could not be added to the list!!!" << endl;
}

//****************************************************************************************************

void removeStudent(DLList<Student> & studentList)
{
	int stuId;
	Student student;

	cout << " What is the id of the student to be deleted: ";
	cin >> stuId;
	student.id = stuId;

	if (studentList.remove(student))
		cout << "Student removed: " << student << endl;
	else
		cout << "student could not be found!!! Try again!!! " << endl;
}

//****************************************************************************************************

void findStudent(DLList<Student> & studentList)
{
	int StuId;
	Student student;

	cout << "What is the id of the student you are searching for?: ";
	cin >> StuId;
	student.id = StuId;

	if (studentList.retrieve(student))
		cout << "Student: " << student.name << "retreived" << endl;
	else
		cout << "student not on the list!!! Try again!!!" << endl;
}

//****************************************************************************************************

/*
=================Menu==================
A: Add a new Student
F: Find a Student Record
R: Remove Student Record
C: Count the Student List
D: Display Student Record in reverse Order
Q: Quit

Enter your choice: d
		Reverse Student List
================================================
ID      NAME                      MAJOR     GPA
================================================
32631   Freud, JR, Fred E         PSYC      1.85
32598   Xerxes, Art I             GREE      3.25
31631   Aristotle, Alice A        PHIL      3.10
30878   Lewis, Clark N            GEOG      3.37
30749   Mendelssohn, Mozart W     MUSC      2.87
30655   Angelo, Mike L            ART       3.74
30381   Elba, Able M              SPEE      3.40
30280   Dewey, Johanna A          EDUC      3.83
30268   Newmann, Alfred E         EDUC      0.99
29583   Yewliss, Cal C            MATH      2.99
28658   Cicero, Marsha            LATI      2.87
27503   Fahrenheit, Felicia O     CHEM      3.85
26316   Custer, General G         HIST      1.95
25831   Santamaria, Nina P        HIST      1.77
25377   Porgy, Bess N             MUSI      2.78
24237   Euler, Lennie L           MATH      3.83
23750   Vespucci, Vera D          GEOG      2.29
23544   Gestalt, Gloria G         PSYC      2.48
23497   Fault, Paige D            CPSC      2.95
23314   Macdonald, Ronald B       CPSC      2.99
22447   Zylstra, Zelda A          ENGL      1.95
22277   Principal, Pamela P       EDUC      1.75
21144   Pasteur, Louise A         BIOL      3.10
20991   Augusta, Ada B            CPSC      3.83
20454   Chicita, Juanita A        BIOL      2.66
19918   Virus, Vera W             CPSC      3.25
19077   Medes, Archie L           ENGR      3.10
18264   Lucky, Lucy L             HIST      2.29
18213   Marx, Karl Z              ECON      2.75
17424   Nakamura, Toky O          SOCI      1.95
17376   Scrooge, Ebenezer T       SOCI      3.25
16622   Issacson, Esau B          RELI      2.98
16540   Weerd, Dewey L            PHIL      2.99
16183   Kuts, Cole                FOOD      3.98
15889   Gazelle, Gwendolyn D      PE        2.78
15802   Pascal, Blaze R           CPSC      1.98
15755   VandenVander, Vanessa V   HIST      3.74
15671   Rembrandt, Roberta E      ART       2.20
15052   Einstein, Alfred M        ENGR      2.78
14815   Tchaikovsky, Wolfgang A   MUSC      2.75
14674   Rockne, Newton K          PE        1.98
13511   Pitt, Stew                GNED      0.21
11951   Mouse, Michael E          EDUC      1.99
11749   Issacson, Jacob A         RELI      2.99
11688   Kronecker, Leo P          MATH      2.75
10304   Deutsch, Sprechen Z       GERM      3.05
10236   Andrews, Peter J          CPSC      2.78
9743    Johnson, James L          ENGR      3.15
9463    Hochschule, Hortense C    EDUC      2.70
7885    Fibonacci, Leonard O      MATH      3.25
7844    Aardvark, Anthony A       ENGR      2.79
7448    Roosevelt, Rose Y         POLS      2.95
7107    Shoemaker, Imelda M       POLS      3.15
5873    Psycho, II,  Prunella E   PSYC      2.99
5710    Busch, Arch E             ENGR      2.75
5430    Nightingale, Florence K   NURS      3.15
5316    GotoDijkstra, Edgar G     CPSC      4.00
4777    Gauss, Carl F             MATH      4.00
4559    Shyster, Samuel D         SOCI      1.95
4454    Atanasoff, Eniac C        CPSC      1.88
3930    Leibniz, Gottfried W      MATH      1.95
=================Menu==================
A: Add a new Student
F: Find a Student Record
R: Remove Student Record
C: Count the Student List
D: Display Student Record in reverse Order
Q: Quit

Enter your choice: q

C:\C++\Double LInked list\Doubly Linked List\Debug\Doubly Linked List.exe (process 17888) exited with code 0.
Press any key to close this window . . .

*/