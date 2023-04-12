/*
 * Queue.cpp
 *
 *  Created on: Nov 20, 2019
 *      Author: J. Alex Burke
 */

#include "Queue.h"

Queue::Queue(int s)
{
	size=s;
	count=0;
	front=0;
	rear=-1;
	array=new char[size];
}

Queue::~Queue()
{
	delete[] array;
}
bool Queue:: enqueue(char dataIn)
{
	if(count==size)
		return false;
	rear=rear+1%size;
	array[rear]=dataIn;
	count++;
	return true;
}
bool Queue::dequeue(char& dataOut)
{
	if(isEmpty())
		return false;
	dataOut=array[front];
	front=(front+1)%size;
	count--;
	return true;
}
bool Queue::isEmpty()
{
	if(count==0)
		return true;
	else
		return false;
}
