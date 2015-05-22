#include <stdio.h>
#include <assert.h>

#ifndef __cDList__
#define __cDList__


/////////
//Nodes//
/////////

template <class TYPE>
struct DNode
{
	TYPE value;
	DNode<TYPE>* next;
	DNode<TYPE>* previous;
	};

//////////////////////
//Double Linked List//
/////////////////////

template <class TYPE>
class cDList
{
private:
	DNode<TYPE>* start;
	DNode<TYPE>* end; //Despite this pointer isn't really necessary for the class cDList to work, it can agilize some other methods
	unsigned int  size;

public:
	cDList(){ start = NULL; end = NULL; size = 0; }

	~cDList() { Clear(); }

	TYPE& operator[] (const unsigned int index)
	{
		DNode<TYPE>* pointer = start;
		for (int n = 0; n < index; n++)
		{
			if (n >= size) { assert(false); }
			pointer = pointer->next;
		}
		return pointer->value;
	}

	const TYPE& operator[] (const unsigned int index) const
	{
		DNode<TYPE>* pointer = start;
		for (int n = 0; n < index; n++)
		{
			if (n >= size) { assert(false); }
			pointer = pointer->next;
		}
		return pointer->value;
	}

	int BubbleSortData()
	{
		/*int counter = 0;
bool done = false;
DNode<TYPE>* pointer = start;

while (done == false)
{
pointer = start;
done = true;
while (pointer != NULL && pointer->next != NULL)
{
counter++;
if (pointer->value > pointer->next->value)
{
Swap(pointer->value, pointer->next->value);
done = false;
}
pointer = pointer->next;
}
}
printf(" BubbleSort Data \n %i\n", counter);
return counter;*/ return 0;
	}

	int BubbleSort()
	{
		int counter = 0;
		bool done = false;
		DNode<TYPE>* pointer = start;
		DNode<TYPE>* pointer2;

		while (done == false)
		{
			pointer = start;
			done = true;
			while (pointer != NULL && pointer->next != NULL)
			{
				counter++;
				pointer2 = pointer->next;
				if (pointer->value > pointer2->value)
				{
					if (pointer != start)
					{    pointer->previous->next = pointer2;    }
					else
					{    start = pointer2;    }
					if (pointer2 != end)
					{    pointer2->next->previous = pointer;    }
					else
					{    end = pointer;    }
					pointer->next = pointer2->next;
					pointer2->previous = pointer->previous;
					pointer->previous = pointer2;
					pointer2->next = pointer;
					done = false;
				}
				else
				{    pointer = pointer2;    }
			}
		}
		printf(" BubbleSort \n %i\n", counter);
		return counter;
	}

	void Swap(DNode<TYPE>* a, DNode<TYPE>* b)
	{
		bool swappedEnd = false;
		bool swappedStart = false;
		if (a != start)
		{
			a->previous->next = b;
		}
		else
		{
			start = b;
			swappedStart = true;
		}
		if (a != end)
		{
			a->next->previous = b;
		}
		else
		{
			end = b;
			swappedEnd = true;
		}
		if (b == start && swappedStart == false)
		{
			start = a;
		}
		else
		{
			b->previous->next = a;
		}
		if (b == end && swappedEnd == false)
		{
			end = a;
		}
		else
		{
			b->next->previous = a;
		}

		DNode<TYPE>* tmp = a->next;
		a->next = b->next;
		b->next = tmp;

		tmp = a->previous;
		a->previous = b->previous;
		b->previous = tmp;
	}

	DNode<TYPE>* GetLast() const
	{
		return end;
	}

	DNode<TYPE>* GetFirst() const
	{
		return start;
	}

	DNode<TYPE>* Get(const int N) const
	{
		DNode<TYPE>* tmp = start;
		for (int p = 0; p < N; p++)
		{
			if (tmp == NULL)
			{
				
				return 0;
				break;
			}
			tmp = tmp->next;
		}
		return tmp;
	}

	DNode<TYPE>*  Add(const TYPE valor)
	{
		DNode<TYPE>* createdDNode = new DNode<TYPE>;
		createdDNode->value = valor;
		createdDNode->next = NULL;
		if (end != NULL)
		{
			end->next = createdDNode;
		}
		createdDNode->previous = end;
		end = createdDNode;

		if (start == NULL)
		{
			start = createdDNode;
		}
		size++;
		return createdDNode;
	}

	bool  Del(DNode<TYPE>* nDel)
	{
		if (nDel != NULL && start != NULL && end != NULL)
		{
			if (nDel)
			{
				if (nDel->next != NULL)
				{
					nDel->next->previous = nDel->previous;   //The value "previous" from the node which follows nDel, which was before nDel itself, is now the node before nDel.
				}
				else
				{
					end = nDel->previous;
				}
				if (nDel->previous != NULL)
				{
					nDel->previous->next = nDel->next;       //Here we do the same, but with the "next" value, so both nodes now "ignore" nDel.
				}
				else
				{
					start = nDel->next;
				}
			}
			else
			{
				return false;
			}
			delete nDel;
			size--;
			return true;
		}

		return false;
	}
	

	void  Clear()
	{
		while (start != NULL)
		{
			end = start->next;
			delete start;
			start = end;
		}
		size = 0;
	}

	unsigned int Count() const
	{
		return size;
	}
};

#endif //__cDList__