#include <stdio.h>
#include "Log.h"
#ifndef __cSList__
#define __cSList__


/////////
//Nodes//
/////////

template <class TYPE>
struct SNode
{
	TYPE value;
	SNode<TYPE>* next;
};


//////////////////////
//Single Linked List//
//////////////////////

template <class TYPE>
class cSList
{
private:
	SNode<TYPE>* start;

public:
	 cSList(){ start = NULL; }

	 ~cSList() { DelList(); }

	 SNode<TYPE>* GetLast() const
	 {
		 SNode<TYPE>* tmp = start;
		 while (tmp->next != NULL)
		 {
			 tmp = tmp->next;
		 }
		 return tmp;
	 }

	 SNode<TYPE>* GetFirst() const
	 {
		 return start;
	 }

	 SNode<TYPE>* Get(const int N) const
	 {
		 SNode<TYPE>* tmp = start;
		 for (int p = 0; p < N; p++)
		 {
			 if (tmp == NULL)
			 {
				 LOG("Tried to access an inexisting node: %i\n", N);
				 return 0;
				 break;
			 }
			 tmp = tmp->next;
		 }
		 return tmp;
	 }

	 void  Add(const TYPE valor)
	{
		 SNode<TYPE>* createdSNode = new SNode<TYPE>;
		createdSNode->value = valor;
		createdSNode->next = NULL;

		if (start != NULL)
		{
			SNode<TYPE>* nextSNode = start;
			while (nextSNode->next != NULL)
			{
				nextSNode = nextSNode->next;
			}
			nextSNode->next = createdSNode;
		}
		else
		{
			start = createdSNode;
		}
	}

	 bool  Del(SNode<TYPE>* nDel)
	{
		if (nDel != NULL && start != NULL)
		{
			if (nDel != start && start != NULL)
			{
				SNode<TYPE>* tmp = start;
				while (tmp && tmp->next != nDel)
				{
					tmp = tmp->next;
				}
				if (tmp)
				{
					tmp->next = nDel->next;
				}
				else
				{
					return false;
				}
			}
			else
			{
				start = start->next;
			}
			delete nDel;
			return true;
		}
	}

	void  DelList()
	{
		SNode<TYPE>* tmp;
		while (start != NULL)
		{
			tmp = start->next;
			delete start;
			start = tmp;
		}
	}

	unsigned int Count() const
	{
		unsigned int count = 0;
		SNode<TYPE>* nextSNode = start;

		while (nextSNode != NULL)
		{
			nextSNode = nextSNode->next;
			count++;
		}
		return count;
	}
};

#endif //__cSList__