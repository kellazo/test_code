#include <stdio.h>
#include <assert.h>

#define PI (3.141592653589793)


#include "FuncionesSinClasificar.h"
#include "Point2D.h"
#include "Log.h"
#include "String.h"
#include "SLinkedList.h"
#include "DLinkedList.h"
#include "FuncionesSinClasificar.h"
#include "DinamicArray.h"
#include "Stack.h"
#include "Queue.h"
#include "Tree.h"
#include "Group.h"

class Circle
{
public:
	cPoint2D center;
	float radius;

	Circle() { center.x = 0.0f;  center.y = 0.0f; radius = 0.0f; }
	Circle(cPoint2D _Position, float _Radius) { center.x = _Position.x; center.y = _Position.y; radius = _Radius; }

	float Area() const
	{
		return radius*radius*PI;
	}

	bool Intersetcs(const Circle* toCheck) const
	{
		if (center.Distance(toCheck->center) <= radius + toCheck->radius)
		{
			return true;
		}
		return false;
	}

};

int Fibonacci(int pos)
{
	int n = 1;
	for (unsigned int i = 0, p = i; i < pos; ++i, n += p, p = n - p);
	return n;
}


int main()
{

	cDynArray<int> arr;
	arr.Push(1);
	arr.Push(2);
	arr.Push(3);
	arr.Push(4);
	arr.Push(5);
	arr.Push(6);

	arr.Mirror();

	DNode<int>* pointer1;
	DNode<int>* pointer2;
	

	cDList<int> myList2;
	pointer2 = myList2.Add(10);
	myList2.Add(9);
	myList2.Add(8);
	myList2.Add(7);
	myList2.Add(6);
	myList2.Add(5);
	myList2.Add(4);
	myList2.Add(3);
	myList2.Add(2);
	pointer1 = myList2.Add(1);

	myList2.Swap(pointer1, pointer2);

	myList2.BubbleSort();
	/*cGroup<int> group1();

	int arr[7] = { 1, 2, 3, 4, 5, 6, 7 };

	cGroup<int> group2(arr);

	int a = group2.listOfData.Count();*/

	system("pause");
	
}