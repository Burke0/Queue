/*
 * prog4.cpp
 *
 *  Created on: Nov 20, 2019
 *      Author: J. Alex Burke
 */
#include "Queue.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
bool isMatch(int[],int[], int);
void generateKnowList(char suspect, int knowList[], std::string buddies[], int buddiesListSize);

int main()
{

	int size=25;
	string buddies[size];
	int knowList[size];
	int copKnowList[size]={1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1};


	ifstream in;
	in.open("buddies.txt");
	if (!in)
	{
		cerr << "Unable to open file";
		exit(1);
	}
	for(int i=0;i<size;i++)
		in>>buddies[i];
	for(char c='A';c<='Z';c++)
	{
		generateKnowList(c, knowList, buddies, size);
		if(isMatch(knowList,copKnowList,size))
		{
			cout<<"I know who the burglar is, it is "<<c<<endl;
			return 0;
		}
	}
}
//This function resets knowList to all 0's.
//Then uses a queue to follow chain of buddies from the suspect setting each of their positions in the know list to 1 when they are queued.
//Each time a buddy is dequeued it adds all of their buddies that are not already on the know list to the queue.
//This is repeated until the queue is empty.
void generateKnowList(char suspect, int knowList[], std::string buddies[], int size)
{
	for(int i=0;i<size;i++)
		knowList[i]=0;
	Queue q;
	q.enqueue(suspect);
	while(q.isEmpty()==false)
	{
		char temp;
		q.dequeue(temp);
		knowList[(int)temp-65]=1;
		for(int i=0;i<size;i++)
		{
			if(buddies[i][0]==temp)
			{
				for(int n=0; n<buddies[i].length(); n++)
				{
					if(buddies[i][n]!=temp && knowList[((int)buddies[i][n]-65)]==0)
					{
						q.enqueue(buddies[i][n]);
						knowList[((int)buddies[i][n]-65)]=1;
					}
				}
			}
		}
	}


}
//compares the two integer lists to see if they match
bool isMatch(int list1[], int list2[],int size)
{
	for(int i=0;i<size;i++)
	{
		if(list1[i]!=list2[i])
			return false;
	}
		cout<<"match found!"<<endl;
		return true;
}

