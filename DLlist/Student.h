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

#ifndef STUDENT_H
#define STUDENT_H


struct Student
{
	int id;
	char name[50];
	char citystate[50];
	char phone[12];
	char gender;
	int year; 
	int credits;
	float gpa;
	char major[6];

	Student();
	friend ostream & operator <<(ostream & out, const Student & data);

	bool operator == (const Student & rhs) const;
	bool operator == (int value) const;
	bool operator != (const Student & rhs) const;
	bool operator != (int value) const;
	bool operator < (const Student & rhs) const;
	bool operator < (int value) const;
	bool operator <= (const Student & rhs) const;
	bool operator <= (int value) const;
	bool operator > (const Student & rhs) const;
	bool operator > (int value) const;
	bool operator >= (const Student & rhs) const;
	bool operator >= (int value) const;


};

//****************************************************************************************************

Student::Student()
{
	id = 0;
}

//****************************************************************************************************

ostream & operator<< (ostream & out, const Student & data)
{
	out << left << data.id << "\t" << setw(25) << data.name << left << " " << setw(10) << data.major
		<< setw(5) << setprecision(2) << fixed << data.gpa << endl;
	
	return out;
}

//****************************************************************************************************

bool Student::operator == (const Student & rhs) const
{
	return (this->id == rhs.id);
}

//****************************************************************************************************

bool Student::operator == (int value) const
{
	return (this->id == value);
}

//****************************************************************************************************

bool Student::operator != (const Student & rhs) const
{
	return (this->id != rhs.id);
}

//****************************************************************************************************

bool Student::operator != (int value) const
{
	return (this->id != value);
}

//****************************************************************************************************

bool Student::operator < (const Student & rhs) const
{
	return (this->id < rhs.id);
}

//****************************************************************************************************

bool Student::operator < (int value) const
{
	return (this->id < value);
}

//****************************************************************************************************

bool Student::operator <= (const Student & rhs) const
{
	return (this->id <= rhs.id);
}

//****************************************************************************************************

bool Student::operator <= (int value) const
{
	return (this->id <= value);
}

//****************************************************************************************************

bool Student::operator > (const Student & rhs) const
{
	return (this->id > rhs.id);
}

//****************************************************************************************************

bool Student::operator > (int value) const
{
	return (this->id > value);
}

//****************************************************************************************************

bool Student::operator >= (const Student & rhs) const
{
	return (this->id >= rhs.id);
}

//****************************************************************************************************

bool Student::operator >= (int value) const
{
	return (this->id >= value);
}

//****************************************************************************************************

#endif