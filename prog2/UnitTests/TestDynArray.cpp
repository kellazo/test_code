#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Punto 2D_String/DinamicArray.h"
#include "../Punto 2D_String/FuncionesSinClasificar.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(DynArrayTests)
	{
	public:
		
		TEST_METHOD(BubbleSort)
		{
			cDynArray<int> Array;
			Array.Push(9);
			Array.Push(5);
			Array.Push(12);
			Array.Push(3);
			Array.Push(10);
			Array.Push(0);
			Array.Push(11);
			Array.Push(6);
			Array.Push(2);
			Array.Push(1);
			Array.Push(8);
			Array.Push(4);
			Array.Push(7);

			Array.BubbleSortOptimized();

			for (int n = 0; n < Array.Count(); n++)
			{
				Assert::AreEqual(Array[n], n);
			}


		}

	};
}