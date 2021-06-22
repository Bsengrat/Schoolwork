//****************************************************************************************************
//
//		File:					AList.h
//		
//		Student:				Bently Sengrath
//
//		Assignment:	 			Program  # 4
//
//		Course Name:			Data Structures   I 
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					Oct, 7, 2019
//
//
//		This program use the array list data structure
//		 
//		
//****************************************************************************************************

#ifndef ALIST_H
#define ALIST
#include <new>

//****************************************************************************************************

template <typename TYPE>
class AList
{
private:

	int capacity;
	int numValues;
	TYPE * list;

public:
	AList(int c = 5);
	~AList();

	bool _resize();
	bool insertFront(const TYPE & dataIn);
	bool insertBack(const TYPE & dataIn);
	bool insertAtIndex(int index, const TYPE & dataIn);
	
	bool removeFront(TYPE & dataOut);
	bool removeBack(TYPE & dataOut);
	bool removeAtIndex(int index, TYPE & dataOut);
	bool remove(TYPE & dataOut);
	
	bool retrieveFront(TYPE & dataOut) const;
	bool retrieveBack(TYPE & dataOut) const;
	bool retrieveAtIndex(int index, TYPE & dataOut) const;
	bool retrieve(TYPE & dataOut) const;

	bool updateFront(const TYPE & dataIn);
	bool updateBack(const TYPE & dataIn); 
	bool updateAtIndex(int index, const TYPE & dataIn);
	bool update(const TYPE & dataIn);

	bool display() const;
	bool getSmallest(TYPE & smallVal) const;
	int getCapacity() const;
	int getNumValues() const;
	bool isEmpty() const;
	bool isFull() const;
	bool clear();

};

//****************************************************************************************************

template <typename TYPE>
AList<TYPE>::AList(int c)
{
	if (c < 2)
	{
		c = 2;
	}

	capacity = c;
	numValues = 0;
	list = new TYPE[capacity];

}

//****************************************************************************************************

template <typename TYPE>
AList<TYPE>::~AList()
{
	delete[] list;
	list = nullptr;
	capacity = 0;
	numValues = 0;

}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::_resize()
{
	bool success = false;
	TYPE * templist;
	int newCap;
	
	newCap = (capacity + (capacity / 2));
	templist = new (nothrow) TYPE[newCap];

	if (templist)
	{
		for (int i = 0; i < numValues; i++)
		{
			templist[i] = list[i];
		}

		success = true;
		delete[] list;
		list = templist;
		capacity = newCap;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::insertFront(const TYPE & dataIn)
{
	bool success = true;

	if (numValues == capacity)
	{
		success = _resize();
	}

	if (success)
	{
		for (int i = numValues; i > 0; i--)
		{
			list[i] = list[i - 1];
		}
		list[0] = dataIn;
		numValues++;
	}


	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::insertBack(const TYPE & dataIn)
{
	bool success = true;
	
	if (numValues == capacity)
	{
		success = _resize();
	}

	if (success)
	{
		list[numValues] = dataIn;
		numValues++;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::insertAtIndex(int index, const TYPE & dataIn)
{
	bool success = true;

	if (index < 0 || index  > numValues)
	{
		success = false;
	}
	else
	{
		if (numValues == capacity)
		{
			success = _resize();
		}
	
		if(success)
		{
			for (int i = numValues; i > index; i--)
			{
				list[i] = list[i - 1];
			}

			list[index] = dataIn;
			numValues++;
		}
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::removeFront(TYPE & dataOut)
{
	bool success = false;

	if (numValues > 0)
	{
		dataOut = list[0];

		for (int i = 0; i < numValues - 1; i++)
		{
			list[i] = list[i + 1];
		}
		
		numValues--;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::removeBack(TYPE & dataOut)
{
	bool success = false;

	if (numValues > 0)
	{
		dataOut = list[numValues];
		numValues--;
		success = true;
	}
	
	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::removeAtIndex(int index, TYPE & dataOut)
{
	bool success = false;

	if (index > 0 && index <= numValues)
	{
		success = true;
		dataOut = list[index];
		numValues -= 1;

		for (int i = index; i < numValues; i++)
		{
			list[index] = list[index + 1];
		}
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::remove(TYPE & dataOut)
{
	bool success = false;

	if (numValues > 0)
	{
		for(int i = 0; i < numValues && !success; i++)
		{
			if (list[i] == dataOut)
			{
				for (int j = i; j < numValues; j++)
				{
					list[j] = list[j + 1];
				}
				
				numValues--;
				success = true;
			}
		}
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::retrieveFront(TYPE & dataOut) const
{
	bool success = true;

	if (numValues == 0)
	{
		success = false;
	}

	if (success)
	{
		dataOut = list[0];
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::retrieveBack(TYPE & dataOut) const
{
	bool success = true;

	if (numValues == 0)
	{
		success = false;
	}

	if (success)
	{
		dataOut = list[numValues];
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::retrieveAtIndex(int index, TYPE & dataOut) const
{
	bool success = true;

	if (index <= 0 || index > numValues)
	{
		success = false;
	}

	if (success)
	{
		dataOut = list[index];
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::retrieve(TYPE & dataOut) const
{
	bool success = false;

	if (numValues > 0)
	{
		for (int i = 0; i < numValues && !success; i++)
		{
			if (list[i] == dataOut)
			{
				success = true;
				dataOut = list[i];
			}
		}
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::updateFront(const TYPE & dataIn)
{
	bool success = true;

	if (numValues == 0)
	{
		success = false;
	}

	if (success)
	{
		list[0] = dataIn;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::updateBack(const TYPE & dataIn)
{
	bool success = true;

	if (numValues == 0)
	{
		success = false;
	}

	if (success)
	{
		list[numValues-1] = dataIn;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::updateAtIndex(int index, const TYPE & dataIn)
{
	bool success = true;

	if (numValues == 0)
	{
		success = false;
	}

	if (success)
	{
		list[index] = dataIn;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::update(const TYPE & dataIn)
{
	bool success = false;

	if (numValues > 0)
	{
		for (int i = 0; i < numValues && !success; i++)
		{
			if (list[i] == dataIn)
			{
				success = true;
				list[i] = dataIn;
			}

		}
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::display() const
{
	bool success = false;

	if (numValues > 0)
	{
		success = true;
	}

	if(success)
	{
		for (int i = 0; i < numValues; i++)
		{
			cout << i << '\t' << list[i] << endl;
		}
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::getSmallest(TYPE & smallVal) const
{
	bool success = false;
	smallVal = list[0];

	if (numValues != 0)
	{
		success = true;
	}
	
	if(success)
	{
		for (int i = 1; i < numValues; i++)
		{
			if (smallVal > list[i])
			{
				smallVal = list[i];
			}
		}
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
int AList<TYPE>::getCapacity() const
{
	return capacity;
}

//****************************************************************************************************

template <typename TYPE>
int AList<TYPE>::getNumValues() const
{
	return numValues;
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::isEmpty() const
{
	return (numValues == 0);
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::isFull() const
{
	return (numValues == capacity);
}

//****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::clear()
{
	bool success = true;

	delete[] list;
	list = nullptr;
	numValues -= numValues;

	return success;
}

//****************************************************************************************************

#endif