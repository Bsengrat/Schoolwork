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
//		Due:					Sept 16, 2019
//
//
//		This program will implment class templates
//		 
//		
//****************************************************************************************************


#ifndef DYAD_H
#define DYAD

using namespace std;

//****************************************************************************************************

template <typename TYPE>
class Dyad
{
private:
	TYPE val1;
	TYPE val2;
public:
	Dyad(TYPE v1 = 0, TYPE v2 = 0);

	TYPE getFirst() const;
	TYPE getSecond() const;
	void swapValues();
	void get2Values(TYPE & v1, TYPE & v2) const;

};

//****************************************************************************************************
template <typename TYPE>
Dyad<TYPE>::Dyad(TYPE v1, TYPE v2)
{
	val1 = v1;
	val2 = v2;
}
//****************************************************************************************************

template <typename TYPE>
TYPE Dyad<TYPE>::getFirst() const
{
	return val1;
}

//****************************************************************************************************

template <typename type>
type Dyad<type>::getSecond() const
{
	return val2;
}

//****************************************************************************************************
template <typename TYPE>
void Dyad<TYPE>::swapValues()
{
	TYPE tempv2 = val2;
	val2 = val1;
	val1 = tempv2;
}

//****************************************************************************************************

template <typename TYPE>
void Dyad<TYPE>::get2Values(TYPE & v1, TYPE & v2) const
{
	v1 = val1;
	v2 = val2;
}

#endif