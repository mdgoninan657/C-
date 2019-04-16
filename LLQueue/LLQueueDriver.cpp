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

#include "LLQueue.h"
#include "Node.h"
#include <iostream>

using namespace std;

//*****************************************************************************************************
template <typename Type>
void displayQueue(LLQueue <Type> & queue);

template <typename Type>
void addValues(LLQueue <Type> & queue, int values[], const int SIZE);

template <typename Type>
int getAvg(LLQueue <Type> & queue);

template <typename Type>
void clearQueue(LLQueue <Type> & queue);


//*****************************************************************************************************

int main()
{
	LLQueue <int> queue;
	int dataOut;
	const int SIZE = 11;
	int values[SIZE] = { 3,7,9,12,33,51,67,89,1,42,11 };

	cout << "*******************Add the values: *******************" << endl;
	addValues(queue, values, SIZE);
	displayQueue(queue);
	cout << "Now Queue is ";
	if (!queue.isEmpty())
	{
		cout << "not empty" << endl;
	}
	else
	{
		cout << "empty" << endl;
	}

	cout << "Now Queue is";
	if (!queue.isFull())
	{
		cout << " not full" << endl;
	}
	else
	{
		cout << "full" << endl;
	}

	dataOut = getAvg(queue);
	cout << "Avg is: " << dataOut << endl;

	queue.viewFront(dataOut);
	cout << "Front Value is: " << dataOut << endl;

	queue.viewRear(dataOut);
	cout << "Rear Value is: " << dataOut << endl;

	dataOut = queue.getSize();
	cout << "Size is: " << dataOut << endl;

	cout << "*******************Clear the Queue: *******************" << endl;

	clearQueue(queue);
	cout << "Now the queue is ";
	if (!queue.isEmpty())
	{
		cout << "not empty" << endl;
	}
	else
	{
		cout << "empty" << endl;
	}

	return 0;
}

//*****************************************************************************************************

template <typename Type>
void displayQueue(LLQueue <Type> & queue)
{
	LLQueue <int> qCpy;
	int dataOut;
	while (!queue.isEmpty())
	{
		queue.viewFront(dataOut);
		cout << dataOut << " ";
		queue.dequeue(dataOut);
		qCpy.enqueue(dataOut);
	}
	cout << endl;
	while (!qCpy.isEmpty())
	{
		qCpy.dequeue(dataOut);
		queue.enqueue(dataOut);
	}

}

//*****************************************************************************************************

template <typename Type>
void addValues(LLQueue <Type> & queue, int values[], const int SIZE)
{
	LLQueue <int> qCpy;
	if (queue.isEmpty())
	{
		for (int i = 0; i < SIZE; i++)
		{
			queue.enqueue(values[i]);
		}
	}
}

//*****************************************************************************************************

template <typename Type>
int getAvg(LLQueue <Type> & queue)
{
	LLQueue <int> qCpy;
	int sum = 0;
	int avg = 0;
	int count = 0;
	int dataOut;

	while (!queue.isEmpty())
	{
		queue.dequeue(dataOut);
		sum += dataOut;
		count++;
		qCpy.enqueue(dataOut);
	}
	while (!qCpy.isEmpty())
	{
		qCpy.dequeue(dataOut);
		queue.enqueue(dataOut);
	}

	avg = sum / count;

	return avg;
}

//*****************************************************************************************************

template <typename Type>
void clearQueue(LLQueue <Type> & queue)
{
	int dataOut;

	while (!queue.isEmpty())
	{
		queue.dequeue(dataOut);
	}

}

//*****************************************************************************************************
/*
*******************Add the values : *******************
3 7 9 12 33 51 67 89 1 42 11
Now Queue is not empty
Now Queue is not full
Avg is : 29
Front Value is : 3
Rear Value is : 11
Size is : 11
* ******************Clear the Queue : *******************
Now the queue is empty
Press any key to continue . . .
*/