#include <stdio.h>
#include "FuncionesSinClasificar.h"

#ifndef __QUEUE__
#define __QUEUE__
//Cua, Queue ->  FIFO (First in, first out)

#define QUEUE_BLOCK_SIZE 16

template <class TYPE>
class cQueue
{
private:
	unsigned int numElements;
	unsigned int allocatedMemory;
	TYPE* data;
	unsigned int element0;

	void Reallocate(const int newSize)
	{
		TYPE* newData = new TYPE[newSize];
		allocatedMemory = newSize;
		if (data != NULL)
		{
			for (unsigned int n = 0; n <= MIN(newSize, (numElements + element0)); n++)
			{
				newData[n] = data[n];
			}

			delete data;
		}
		data = newData;
		numElements = MIN(newSize, numElements);
	}

public:
	cQueue(){ data = NULL; numElements = 0; element0 = 0; allocatedMemory = 0; }

	~cQueue()
	{
		if (data != NULL) { delete data; }
	}

	const unsigned int Count() const
	{
		return numElements;
	}

	bool Shrink()
	{
		if (numElements < allocatedMemory)
		{
			Reallocate(numElements);
			return true;
		}
		return false;
	}

	void Push(const TYPE value)
	{
		if (numElements + element0 + 1 > allocatedMemory)
		{
			if (element0 >= QUEUE_BLOCK_SIZE)
			{
				for (unsigned int n = 0; n < numElements; n++)
				{
					data[n] = data[element0];
					element0++;
				}
				element0 = 0;
			}
			else
			{
				Reallocate(allocatedMemory + QUEUE_BLOCK_SIZE);
			}
		}
		data[numElements + element0] = value;
		numElements++;
	}

	TYPE Pop()
	{
		if (numElements >= 1)
		{
			numElements--;
			element0++;
			return data[element0 - 1];
		}

		return NULL;

	}

	void Clear()
	{
		numElements = 0;
	}

	const TYPE* Peek(unsigned int index) const
	{
		TYPE* result = NULL;

		if (index + element0 < numElements)
		{
			result = &data[index + element0];
		}

		return result;
	}

};

#endif //__QUEUE__