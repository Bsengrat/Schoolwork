//****************************************************************************************************
//
//		File:					Node.h
//		
//		Student:				Bently Sengrath
//
//		Assignment:	 			Program  # 1
//
//		Course Name:			Data Structures   I 
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					Nov, 10, 2019
//
//
//		This program  creates nodes for uses in linked structures
//		 
//		
//****************************************************************************************************


#ifndef NODE_H
#define NODE

template <typename TYPE>
struct Node
{
	TYPE data;
	Node<TYPE> * next;

	Node();
	Node(TYPE d, Node<TYPE> * n = nullptr);

};


template <typename TYPE>
Node<TYPE>::Node()
{
	data = 0;
	next = nullptr;
}

template <typename TYPE>
Node<TYPE>::Node(TYPE d, Node<TYPE> * n)
{
	data = d;
	next = n;
}

#endif
