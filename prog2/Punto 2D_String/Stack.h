#include <stdio.h>
#include "FuncionesSinClasificar.h" 

#define STACK_BLOCK_SIZE 16

#ifndef __STACK__
#define __STACK__

template <class TYPE>
class cStack
{
private:
	unsigned int numElements;
	unsigned int allocatedMemory;
	TYPE* data;

	void Reallocate(const int newSize)
	{
		TYPE* newData = new TYPE[newSize];
		allocatedMemory = newSize;
		if (data != NULL)
		{
			for (int n = 0; n <= MIN(newSize, numElements); n++)
			{
				newData[n] = data[n];
			}

			delete data;
		}
		data = newData;
		numElements = MIN(newSize, numElements);
	}

public:
	cStack(){ data = NULL; numElements = 0; allocatedMemory = 0; }

	~cStack()
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
		if (numElements + 1 > allocatedMemory)
		{
			Reallocate(allocatedMemory + STACK_BLOCK_SIZE);
		}
		data[numElements] = value;
		numElements++;
	}

	TYPE Pop()
	{
		if (numElements >= 1)
		{
			numElements--;
			return data[numElements];
		}
		return NULL;

	}

	TYPE PeekLast()
	{
		if (numElements >= 1)
		{
			return data[numElements-1];
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

		if (index < numElements)
			result = &data[index];

		return result;
	}

};

#endif //__STACK__