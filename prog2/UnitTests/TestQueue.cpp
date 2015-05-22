#include "stdafx.h"
#include "CppUnitTest.h"

#include <stdio.h>
#include "../Punto 2D_String/Queue.h"
#include "../Punto 2D_String/FuncionesSinClasificar.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(TestQueue)
	{
	public:

		TEST_METHOD(TestMethod0)
		{
			cQueue<int> Queue;
			Queue.Push(5);
			Assert::AreEqual(1, 1);
		}
		
		TEST_METHOD(TestMethod1)
		{
			cQueue<int> Queue;

			for (int n = 0; n < 600; n++)
			{
				Queue.Push(n);
			}
			for (int n = 0; n < 210; n++)
			{
				Assert::AreEqual(Queue.Pop(), n);
			}
			for (int n = 0; n < 100; n++)
			{
				Queue.Push(600 + n);
			}
			for (int n = 0; n < 490; n++)
			{
				Assert::AreEqual(Queue.Pop(), (n + 210));
			}
		}

		TEST_METHOD(TestMethod2)
		{
			cQueue<int> Queue;

			for (int n = 0; n < 15; n++)
			{
				Queue.Push(n);
			}
			for (int n = 0; n < 10; n++)
			{
				Assert::AreEqual(Queue.Pop(), n);
			}
			for (int n = 0; n < 30; n++)
			{
				Queue.Push(n+15);
			}
			for (int n = 0; n < 35; n++)
			{
				Assert::AreEqual(Queue.Pop(), n + 10);
			}
			
		}

	};
}