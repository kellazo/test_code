#include <stdlib.h>
#include "DLinkedList.h"
#include "Stack.h"
#include "Queue.h"

template <class TYPE>
class TreeNode
{
	
public:
	TreeNode(){ data = NULL; parent = NULL; }
	TreeNode(TYPE _data){ data = _data; parent = NULL; }

	TreeNode<TYPE>* parent;
	cDList<TreeNode<TYPE>*> branches;
	TYPE data;

	void VisitPostOrder_Rec(cDList <TYPE>* list) const
	{
		int nNodes = branches.Count();
		for (int n = 0; n < nNodes; n++)
		{
			branches.Get(n)->value->VisitPostOrder_Rec(list);
		}
		list->Add(data);
	}

	void VisitPreOrder_Rec(cDList <TYPE>* list) const
	{
		list->Add(data);
		int nNodes = branches.Count();
		for (int n = 0; n < nNodes; n++)
		{
			branches.Get(n)->value->VisitPreOrder_Rec(list);
		}
	}

	void VisitInOrder_Rec(cDList <TYPE>* list) const
	{
		int nNodes = branches.Count();
		int n = 0;

		for (; n < nNodes/2; n++)
		{
			branches.Get(n)->value->VisitInOrder_Rec(list);
		}

		list->Add(data);
		
		for (; n < nNodes; n++)
		{
			branches.Get(n)->value->VisitInOrder_Rec(list);
		}
	}

};

template <class TYPE>
class cTree
{
	
	TreeNode<TYPE>* rootNode;

public:

	//Constructor
	cTree() { rootNode = NULL; }


	//Destructor
	~cTree() { Clear(); }


	//Getters
	const TreeNode<TYPE>* GetRoot() const { return rootNode; }


	//Visit
	void VisitPreOrder_Rec(cDList <TYPE>* list) const { rootNode->VisitPreOrder_Rec(list); }
	void VisitPostOrder_Rec(cDList <TYPE>* list) const { rootNode->VisitPostOrder_Rec(list); }
	void VisitInOrder_Rec(cDList <TYPE>* list) const { rootNode->VisitInOrder_Rec(list); }

	void VisitPreOrder (cDList <TYPE>* list) const
	{
		cStack<TreeNode<TYPE>*> Stack;
		TreeNode<TYPE>* node = rootNode;
		while (node!=NULL)
		{
			list->Add(node->data);
			for (int n = node->branches.Count()-1; n >= 0; n--)
			{
				Stack.Push(node->branches.Get(n)->value);
			}
			node = Stack.Pop();
		}
	}
	
	void VisitPostOrder(cDList <TYPE>* list) const
	{
		cStack<TreeNode<TYPE>*> Stack;
		cStack<TreeNode<TYPE>*> StackFinal;
		TreeNode<TYPE>* node = rootNode;
		while (node != NULL)
		{
			StackFinal.Push(node);
			for (int n = 0; n < node->branches.Count(); n++)
			{
				Stack.Push(node->branches.Get(n)->value);
			}
			node = Stack.Pop();
		}
		while (true)
		{
			node = StackFinal.Pop();
			if (node == NULL) { break; }
			list->Add(node->data);
		}
	}

	void VisitInOrder(cDList <TYPE>* list) const
	{
		cStack<TreeNode<TYPE>*> Stack;
		cStack<TreeNode<TYPE>*> Stack2;
		TreeNode<TYPE>* node = rootNode;
		while (node != NULL)
		{
			int m = node->branches.Count();
			for (int n = m / 2; m > n; m--)
			{
				Stack.Push(node->branches.Get(m - 1)->value);
			}
			Stack.Push(node);
			Stack2.Push(node);
			for (; m > 0; m--)
			{
				Stack.Push(node->branches.Get(m - 1)->value);
			}
			while (Stack.PeekLast() == Stack2.PeekLast() && Stack.PeekLast() != NULL)
			{
				node = Stack.Pop();
				list->Add(Stack2.Pop()->data);
			}
			node = Stack.Pop();

		}
	}

	
	//Add
	TreeNode<TYPE>* Add(const TYPE& data, TreeNode<TYPE>* parent = NULL)
	{
		if (parent == NULL && rootNode != NULL)
		{
			return NULL;
		}
		TreeNode<TYPE>* newNode = new TreeNode<TYPE>(data);
		if (rootNode == NULL)
		{
			newNode->parent = NULL;
			rootNode = newNode;
		}
		else if (parent != NULL)
		{
			parent->branches.Add(newNode);
			newNode->parent = parent;
		}
		return newNode;
	}


	//Clear
	void Clear(TreeNode<TYPE>* nodeToErase = NULL)
	{
		if (nodeToErase == NULL && rootNode != NULL)
		{
			nodeToErase = rootNode;
		}
		if (nodeToErase && nodeToErase != NULL)
		{
			if (nodeToErase->branches.GetFirst() != NULL)
			{
				int nNodes = nodeToErase->branches.Count();
				for (int n = 0; n < nNodes; n++)
				{
					Clear(nodeToErase->branches.Get(n)->value);
				}
			}
			delete nodeToErase;
		}
		if (nodeToErase == rootNode)
		{
			rootNode = NULL;
		}
	}

};