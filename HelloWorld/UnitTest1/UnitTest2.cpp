#include "stdafx.h"
#include "CppUnitTest.h"
#include "../HelloWorld/Point2f.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Agregar aquí el código de la prueba
			Point2f punt;

			punt.Negate();
			Assert::IsTrue(punt.negate());
		}

	};
}