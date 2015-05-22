#include "stdafx.h"
#include "CppUnitTest.h"



#include "../Punto 2D_String/Tree.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(TestTree)
	{
	public:

		/*Arbrol con el que se ejecutan los tests:

			   ___F___
			   __B__    G
			   A  _D_   H
			   C E   I
			   */

		TEST_METHOD(PreOrder_Rec)
		{
			cTree<char> Arbolito;
			TreeNode<char>* puntero;
			TreeNode<char>* punteroBis;
			puntero = Arbolito.Add('F');
			punteroBis = Arbolito.Add('B', puntero);
			puntero = Arbolito.Add('G', puntero);
			puntero = Arbolito.Add('H', puntero);
			Arbolito.Add('I', puntero);
			Arbolito.Add('A', punteroBis);
			punteroBis = Arbolito.Add('D', punteroBis);
			Arbolito.Add('C', punteroBis);
			Arbolito.Add('E', punteroBis);
			cDList<char> lista;

			Arbolito.VisitPreOrder_Rec(&lista);

			Assert::AreEqual(lista.Get(0)->value, 'F');
			Assert::AreEqual(lista.Get(1)->value, 'B');
			Assert::AreEqual(lista.Get(2)->value, 'A');
			Assert::AreEqual(lista.Get(3)->value, 'D');
			Assert::AreEqual(lista.Get(4)->value, 'C');
			Assert::AreEqual(lista.Get(5)->value, 'E');
			Assert::AreEqual(lista.Get(6)->value, 'G');
			Assert::AreEqual(lista.Get(7)->value, 'H');
			Assert::AreEqual(lista.Get(8)->value, 'I');


		}

		TEST_METHOD(PreOrder)
		{
			cTree<char> Arbolito;
			TreeNode<char>* puntero;
			TreeNode<char>* punteroBis;
			puntero = Arbolito.Add('F');
			punteroBis = Arbolito.Add('B', puntero);
			puntero = Arbolito.Add('G', puntero);
			puntero = Arbolito.Add('H', puntero);
			Arbolito.Add('I', puntero);
			Arbolito.Add('A', punteroBis);
			punteroBis = Arbolito.Add('D', punteroBis);
			Arbolito.Add('C', punteroBis);
			Arbolito.Add('E', punteroBis);

			cDList<char> lista;

			Arbolito.VisitPreOrder(&lista);

			Assert::AreEqual(lista.Get(0)->value, 'F');
			Assert::AreEqual(lista.Get(1)->value, 'B');
			Assert::AreEqual(lista.Get(2)->value, 'A');
			Assert::AreEqual(lista.Get(3)->value, 'D');
			Assert::AreEqual(lista.Get(4)->value, 'C');
			Assert::AreEqual(lista.Get(5)->value, 'E');
			Assert::AreEqual(lista.Get(6)->value, 'G');
			Assert::AreEqual(lista.Get(7)->value, 'H');
			Assert::AreEqual(lista.Get(8)->value, 'I');
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(PostOrder_Rec)
		{
			cTree<char> Arbolito;
			TreeNode<char>* puntero;
			TreeNode<char>* punteroBis;
			puntero = Arbolito.Add('F');
			punteroBis = Arbolito.Add('B', puntero);
			puntero = Arbolito.Add('G', puntero);
			puntero = Arbolito.Add('H', puntero);
			puntero = Arbolito.Add('I', puntero);

			Arbolito.Add('A', punteroBis);
			punteroBis = Arbolito.Add('D', punteroBis);

			Arbolito.Add('C', punteroBis);
			Arbolito.Add('E', punteroBis);

			cDList<char> lista;

			Arbolito.VisitPostOrder_Rec(&lista);

			Assert::AreEqual(lista.Get(0)->value, 'A');
			Assert::AreEqual(lista.Get(1)->value, 'C');
			Assert::AreEqual(lista.Get(2)->value, 'E');
			Assert::AreEqual(lista.Get(3)->value, 'D');
			Assert::AreEqual(lista.Get(4)->value, 'B');
			Assert::AreEqual(lista.Get(5)->value, 'I');
			Assert::AreEqual(lista.Get(6)->value, 'H');
			Assert::AreEqual(lista.Get(7)->value, 'G');
			Assert::AreEqual(lista.Get(8)->value, 'F');


		}

		TEST_METHOD(PostOrder)
		{
			cTree<char> Arbolito;
			TreeNode<char>* puntero;
			TreeNode<char>* punteroBis;
			puntero = Arbolito.Add('F');
			punteroBis = Arbolito.Add('B', puntero);
			puntero = Arbolito.Add('G', puntero);
			puntero = Arbolito.Add('H', puntero);
			puntero = Arbolito.Add('I', puntero);

			Arbolito.Add('A', punteroBis);
			punteroBis = Arbolito.Add('D', punteroBis);

			Arbolito.Add('C', punteroBis);
			Arbolito.Add('E', punteroBis);

			cDList<char> lista;

			Arbolito.VisitPostOrder(&lista);

			Assert::AreEqual(lista.Get(0)->value, 'A');
			Assert::AreEqual(lista.Get(1)->value, 'C');
			Assert::AreEqual(lista.Get(2)->value, 'E');
			Assert::AreEqual(lista.Get(3)->value, 'D');
			Assert::AreEqual(lista.Get(4)->value, 'B');
			Assert::AreEqual(lista.Get(5)->value, 'I');
			Assert::AreEqual(lista.Get(6)->value, 'H');
			Assert::AreEqual(lista.Get(7)->value, 'G');
			Assert::AreEqual(lista.Get(8)->value, 'F');
		}

		TEST_METHOD(InOrder_Rec)
		{
			cTree<char> Arbolito;
			TreeNode<char>* puntero;
			TreeNode<char>* punteroBis;
			puntero = Arbolito.Add('F');
			punteroBis = Arbolito.Add('B', puntero);
			puntero = Arbolito.Add('G', puntero);
			puntero = Arbolito.Add('H', puntero);
			puntero = Arbolito.Add('I', puntero);

			Arbolito.Add('A', punteroBis);
			punteroBis = Arbolito.Add('D', punteroBis);

			Arbolito.Add('C', punteroBis);
			Arbolito.Add('E', punteroBis);

			cDList<char> lista;

			Arbolito.VisitInOrder_Rec(&lista);

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

		TEST_METHOD(Clear)
		{
			cTree<char> Arbolito;
			TreeNode<char>* puntero;
			TreeNode<char>* punteroBis;
			puntero = Arbolito.Add('F');
			punteroBis = Arbolito.Add('B', puntero);
			puntero = Arbolito.Add('G', puntero);
			puntero = Arbolito.Add('H', puntero);
			puntero = Arbolito.Add('I', puntero);
			Arbolito.Add('A', punteroBis);
			punteroBis = Arbolito.Add('D', punteroBis);
			Arbolito.Add('C', punteroBis);
			Arbolito.Add('E', punteroBis);

			Arbolito.Clear();

			Arbolito.Add('P');

			cDList<char> lista;

			Arbolito.VisitInOrder_Rec(&lista);

			Assert::IsTrue(lista.Count() == 1);
			Assert::AreEqual(lista.Get(0)->value, 'P');

		}

		TEST_METHOD(Add)
		{
			cTree<char> Arbolito;
			TreeNode<char>* TestingPointers[4];
			TreeNode<char>* puntero;
			TreeNode<char>* punteroBis;
			puntero = Arbolito.Add('F');
			punteroBis = Arbolito.Add('B', puntero);
			puntero = Arbolito.Add('G', puntero);
			TestingPointers[0] = puntero = Arbolito.Add('H', puntero);
			puntero = Arbolito.Add('I', puntero);
			Arbolito.Add('A', punteroBis);
			punteroBis = Arbolito.Add('D', punteroBis);
			Arbolito.Add('C', punteroBis);
			TestingPointers[1] = Arbolito.Add('E', punteroBis);
			Arbolito.Add('J', punteroBis);
			Arbolito.Add('K', punteroBis);
			Arbolito.Add('L', punteroBis);
			Arbolito.Add('M', punteroBis);
			Arbolito.Add('N', punteroBis);
			Arbolito.Add('O', punteroBis);
			TestingPointers[2] = puntero = Arbolito.Add('P', punteroBis);
			puntero = Arbolito.Add('Q', puntero);
			puntero = Arbolito.Add('R', puntero);
			puntero = Arbolito.Add('S', puntero);
			Arbolito.Add('T', puntero);
			Arbolito.Add('U', puntero);
			Arbolito.Add('V', puntero);
			Arbolito.Add('X', puntero);
			TestingPointers[3] = Arbolito.Add('Y', puntero);
			Arbolito.Add('Z', puntero);

			Assert::AreEqual(TestingPointers[0]->data, 'H');
			Assert::AreEqual(TestingPointers[1]->data, 'E');
			Assert::AreEqual(TestingPointers[2]->data, 'P');
			Assert::AreEqual(TestingPointers[3]->data, 'Y');

		}

	};
}