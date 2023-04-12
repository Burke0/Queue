/*
 * Queue.h
 *
 *  Created on: Nov 20, 2019
 *      Author: J. Alex Burke
 */

#ifndef QUEUE_H_
#define QUEUE_H_

class Queue
{
	private:
	char* array; // each item is an int
	int size, count, front, rear;
	public:
	Queue(int s =100);
	~Queue();
	bool enqueue(char dataIn);
	bool dequeue(char& dataOut);
	bool isEmpty();
};

#endif /* QUEUE_H_ */
