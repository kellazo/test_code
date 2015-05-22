#include <stdio.h>
#include <assert.h>

#include "Stack.h"
#include "FuncionesSinClasificar.h"

#define DYNARRAY_BLOCK_SIZE 16

template <class TYPE>
class cDynArray
{
private:
	unsigned int numElements;
	unsigned int allocatedMemory;
	TYPE* data;

public:
	cDynArray(){ data = NULL; numElements = 0; allocatedMemory = 0; }

	cDynArray(const int MemorySize) { data = new TYPE[MemorySize]; allocatedMemory = MemorySize; numElements = 0; }

	~cDynArray()
	{
		if (data != NULL) { delete data; }
	}

	const unsigned int GetCapacity() const
	{
		return allocatedMemory;
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

	void Push(const TYPE value)
	{
		if (numElements + 1 > allocatedMemory)
		{
			Reallocate(allocatedMemory + DYNARRAY_BLOCK_SIZE);
		}
		data[numElements] = value;
		numElements++;
	}

	bool Pop()
	{
		if (numElements >= 1)
		{
			numElements--;
			return true;
		}
		return false;

	}

	void Clear()
	{
		numElements = 0;
	}

	void Insert(const TYPE value, const int pos)
	{
		if (pos < allocatedMemory)
		{
			if (numElements + 1 > allocatedMemory)
			{
				Reallocate(allocatedMemory + 1);
			}
			for (int n = numElements; n > pos; n--)
			{
				data[n] = data[n - 1];
			}
			data[pos] = value;
			numElements++;
		}
		else
		{
			LOG("\n\nSe intentó insertar un valor fuera de la memoria en un DynArray\n\n");
		}
	}

	void Mirror()
	{
		for (int n = 0; n < (numElements - 1) / 2; n++)
		{
			Swap(data[n], data[numElements - 1 - n]);
		}
	}

	TYPE& operator[] (const unsigned int index)
	{
		if (index < numElements)
		{
			return data[index];
		}
		else
		{
			assert(false);
		}
	}

	const TYPE& operator[] (const unsigned int index) const
	{
		if (index < numElements)
		{
			return data[index];
		}
		else
		{
			assert(false);
		}
	}

	TYPE* At(unsigned int index)
	{
		TYPE* result = NULL;

		if (index < numElements)
			result = &data[index];

		return result;
	}

	const TYPE* At(unsigned int index) const
	{
		TYPE* result = NULL;

		if (index < numElements)
			result = &data[index];

		return result;
	}

	void BubbleSortOld()
	{
		int counter = 0;
		bool done = false;

		while (done == false)
		{
			done = true;
			for (int n = 0; n < numElements - 1; n++)
			{
				counter++;
				if (data[n] > data[n + 1])
				{
					Swap(data[n], data[n + 1]);
					done = false;
				}
			}
		}
		printf(" BubbleSort Old \n %i\n", counter);
	}

	void BubbleSort()
	{
		int counter = 0;
		bool done = false;
		int loops = 1;

		while (done == false)
		{
			done = true;
			for (int n = 0; n < numElements - loops; n++)
			{
				counter++;
				if (data[n] > data[n + 1])
				{
					Swap(data[n], data[n + 1]);
					done = false;
				}
			}
			loops++;
		}
		printf(" BubbleSort \n %i\n", counter);
	}

	void BubbleSortOptimized()
	{
		int counter = 0;
		int correctFromHere = numElements - 1;
		int lastN;

		while (correctFromHere != 0)
		{
			lastN = 0;
			for (int n = 0; n < correctFromHere; n++)
			{
				counter++;
				if (data[n] > data[n + 1])
				{
					Swap(data[n], data[n + 1]);
					lastN = n;
				}
			}
			correctFromHere = lastN;
		}
		printf(" BubbleSort Optimized \n  %i\n", counter);
	}

	void BubbleSortOptimizedAgain()
	{
		int counter = 0;
		int end = numElements - 1;
		int start = 0;

		int lastN;

		while (end != start)
		{
			lastN = 0;
			for (int n = 0; n < end; n++)
			{
				counter++;
				if (data[n] > data[n + 1])
				{
					Swap(data[n], data[n + 1]);
					lastN = n;
				}
			}
			end = lastN;
			if (lastN == start) { break; }

			lastN = numElements;
			for (int n = numElements; n > start; n--)
			{
				counter++;
				if (data[n] < data[n - 1])
				{
					Swap(data[n], data[n - 1]);
					lastN = n;
				}
				start = lastN;
			}

		}
		printf(" BubbleSort Optimized Again \n %i\n", counter);
	}

};
