//*****************************************************************************************************
//
//		File:			    AStack.h 
//
//		Student:			 Matthew Goninan
//
//		Assignment:			 Assignment 10
//
//		Course Name:		 Data Structures I
//
//		Course Number:		 COSC 3050-01
//
//	    Due:				 Nov 16, 2016
//
//		This program uses a templated class called Queue  
//
//*****************************************************************************************************
#ifndef LLQUEUE_H
#define LLQUEUE_H
#include "Node.h"

template <typename Type>
class LLQueue
{
	private:
		Node<Type> * front;
		Node<Type> * rear;
		int numValues;

	public:
		LLQueue();
		~LLQueue();
		bool enqueue(const Type & dataIn);
		bool dequeue(Type & dataOut);
		bool viewFront(Type & dataOut) const;
		bool viewRear(Type &dataOut) const;
		bool isEmpty() const;
		bool isFull() const;
		int getSize() const;

};

//*****************************************************************************************************
template <typename Type>
LLQueue <Type> ::LLQueue()
{
	front = nullptr;
	rear = nullptr;
	numValues = 0;
}

//*****************************************************************************************************

template <typename Type>
LLQueue <Type> ::~LLQueue()
{
	Node<Type> * pTemp;
	while (front != nullptr)
	{
		pTemp = front;
		front = pTemp->next;
		delete pTemp;
		numValues--;
	}
}

//*****************************************************************************************************

template <typename Type>
bool LLQueue <Type> :: enqueue(const Type & dataIn)
{
	bool success = false;
	Node <Type> *pNew = new(nothrow) Node<Type>;
	pNew->data = dataIn;
	if (pNew != nullptr)
	{
		if (rear != nullptr)
		{
			rear->next = pNew;
		}
		else
		{
			front = pNew;
		}
		rear = pNew;
		numValues++;
		success = true;
	}
	return success;
}

//*****************************************************************************************************

template <typename Type>
bool LLQueue <Type> ::dequeue(Type & dataOut)
{
	bool success = false;
	Node<Type> * pTemp;
	if (front != nullptr)
	{
		pTemp = front;
		dataOut = front->data;
		front = front->next;
		numValues--;
		delete[] pTemp;
		success = true;
	}
	if (numValues == 0)
	{
		rear = nullptr;
		success = true;
	}
	return success;
}

//*****************************************************************************************************

template <typename Type>
bool LLQueue <Type> ::viewFront(Type & dataOut) const
{
	bool success = false;
	if (front != nullptr)
	{
		dataOut = front->data;
		success = true;
	}
	return success;
}

//*****************************************************************************************************

template <typename Type>
bool LLQueue <Type> ::viewRear(Type & dataOut) const
{
	bool success = false;
	if (rear != nullptr)
	{
		dataOut = rear->data;
		success = true;
	}
	return success;
}

//*****************************************************************************************************

template <typename Type>
bool LLQueue <Type> :: isEmpty() const
{
	bool success = false;
	if (front == nullptr)
	{
		success = true;
	}
	return success;
}

//*****************************************************************************************************

template <typename Type>
bool LLQueue <Type> ::isFull() const
{
	bool success = false;
	Node <Type> *pNew = new(nothrow) Node<Type>;
	if (!pNew)
	{
		success = true;
	}
	return success;
}

//*****************************************************************************************************

template <typename Type>
int LLQueue <Type> ::getSize() const
{
	return numValues;
}

//*****************************************************************************************************

#endif
