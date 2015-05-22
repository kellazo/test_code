#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Punto 2D_String/Point2D.h"
#include "../Punto 2D_String/String.h"
#include "../Punto 2D_String/FuncionesSinClasificar.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SwapTests
{
	TEST_CLASS(TestSwap)
	{
	public:
		
		TEST_METHOD(SwapInt)
		{
			int a = 5;
			int b = 10;
			Swap(a, b);
			Assert::IsTrue(b == 5 && a == 10);
		}

		TEST_METHOD(SwapFloat)
		{
			float a = 5.88f;
			float b = 10.0045f;
			Swap(a, b);
			Assert::IsTrue(b == 5.88f && a == 10.0045f);
		}

		TEST_METHOD(SwapDouble)
		{
			double a = 5.88785;
			double b = 10.0045948;
			Swap(a, b);
			Assert::IsTrue(b == 5.88785 && a == 10.0045948);
		}

		TEST_METHOD(SwapChar)
		{
			char a = 'd';
			char b = 'b';
			Swap(a, b);
			Assert::IsTrue(b == 'd' && a == 'b');
		}


		TEST_METHOD(SwapPoint2D)
		{
			cPoint2D a(50,7.25f);
			cPoint2D b(100, 45.99f);

			cPoint2D a2(50, 7.25f);
			cPoint2D b2(100, 45.99f);

			Swap(a, b);
			Assert::IsTrue(b == a2 && a == b2);
		}

		TEST_METHOD(SwapString)
		{
			cString a("Deberia ser A");
			cString b("Yo soy B");

			Swap(a, b);
			Assert::IsTrue(b == "Deberia ser A" && a == "Yo soy B");
		}

	};
}