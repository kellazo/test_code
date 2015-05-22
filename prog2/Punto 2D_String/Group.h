#include "DLinkedList.h"

template <class TYPE>
class cGroup
{
public:
	cDList<TYPE> listOfData;

	cGroup() {}
	cGroup(TYPE recieved [])
	{
		Push(recieved);
	}

	void Push(TYPE recieved)
	{
		listOfData.Add(recieved);
	}

	void Push(TYPE recieved[])
	{
		int size = sizeof(recieved) / sizeof(recieved[0]);

			for (int n = 0; n < size; n++)
		{
			listOfData.Add(recieved[n]);
		}
	}

	int Compare(TYPE)
	{

	}

};