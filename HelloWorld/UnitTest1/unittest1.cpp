#include "stdafx.h"
#include "CppUnitTest.h"
#include "../HelloWorld/Point2f.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1) // macro
	{
	public:
		
		TEST_METHOD(TestPoint2f) //es una macro
		{
			// TODO: Agregar aquí el código de la prueba
			Point2f punt;
	
			punt.setZero();
			Assert::IsTrue(punt.isZero()); //crida propietat estatica classe que es diu assert i estem cridant el metode istrue :: crida metode static
		}

		TEST_METHOD(TestPoint2f) //es una macro
		{
			// TODO: Agregar aquí el código de la prueba
			Point2f punt, p2, p3;

			p2.x = 1.0f;
			p2.y = 3.0f;

			p3.x = 1.0f;
			p3.y = 3.0f;

			punt = p2 + p3;;

			Assert::IsTrue(punt.isZero()); //crida propietat estatica classe que es diu assert i estem cridant el metode istrue :: crida metode static
		}

	};
}