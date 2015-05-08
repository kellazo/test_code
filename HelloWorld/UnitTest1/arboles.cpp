#include "stdafx.h"
#include "CppUnitTest.h"
#include "../HelloWorld/BinaryTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(arboles)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Tree<char> Arbolito;
			node<char>* puntero;
			node<char>* punteroBis;
			puntero = Arbolito.Add('F');
			punteroBis = Arbolito.Add('B', puntero);
			puntero = Arbolito.Add('G', puntero);
			puntero = Arbolito.Add('H', puntero);
			puntero = Arbolito.Add('I', puntero);

			Arbolito.Add('A', punteroBis);
			punteroBis = Arbolito.Add('D', punteroBis);

			Arbolito.Add('C', punteroBis);
			Arbolito.Add('E', punteroBis);

			p2List<char> lista;

			Arbolito.VisitInOrder(&lista);

			Assert::AreEqual(lista.Get(0)->value, 'A');
			Assert::AreEqual(lista.Get(1)->value, 'B');
			Assert::AreEqual(lista.Get(2)->value, 'C');
			Assert::AreEqual(lista.Get(3)->value, 'D');
			Assert::AreEqual(lista.Get(4)->value, 'E');
			Assert::AreEqual(lista.Get(5)->value, 'F');
			Assert::AreEqual(lista.Get(6)->value, 'G');
			Assert::AreEqual(lista.Get(7)->value, 'H');
			Assert::AreEqual(lista.Get(8)->value, 'I');
		}

	};
}