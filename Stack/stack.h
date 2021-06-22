//****************************************************************************************************
//
//		File:					stack.h
//		
//		Student:				Bently Sengrath
//
//		Assignment:	 			Program  # 7
//
//		Course Name:			Data Structures   I 
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					Nov 4, 2019
//
//
//		This program  will create the stack data structure
//		 
//		
//****************************************************************************************************

#ifndef STACK_H
#define STACK

//****************************************************************************************************

template <typename TYPE>
class Stack
{
private:
	TYPE * stack;
	int capacity;
	int top;

public:
	Stack(int c = 5);
	~Stack();

	bool push(const TYPE & dataIn);
	bool pop(TYPE & dataOut);
	bool peek(TYPE & dataOut) const;

	int getNumValues() const;
	bool isFull() const;
	bool isEmpty() const;

};

//****************************************************************************************************

template <typename TYPE>
Stack<TYPE>::Stack(int c)
{
	stack = nullptr;

	if (c < 2)
	{
		c = 2;
	}
	
	capacity = c;
	top = -1;
	stack = new TYPE[capacity];

}

//****************************************************************************************************

template <typename TYPE>
Stack<TYPE>::~Stack()
{
	delete [] stack;
	stack = nullptr;
	top = 0;
	capacity = 0;
}

//****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::push(const TYPE & dataIn)
{
	bool success = false;
	
	if (top + 1 < capacity)
	{
		top++;
		stack[top] = dataIn;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::pop(TYPE & dataOut)
{
	bool success = false;

	if (top > -1)
	{
		dataOut = stack[top];
		top--;
		success = true;
	}

	return success;

}

//****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::peek(TYPE & dataOut) const
{
	bool success = false;

	if (top > -1)
	{
		dataOut = stack[top];
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
int Stack<TYPE>::getNumValues() const
{
	return top;
}

//****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::isFull() const
{
	return (top + 1 == capacity);
}

//****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::isEmpty() const
{
	return (top < 0);
}

//****************************************************************************************************

#endif
