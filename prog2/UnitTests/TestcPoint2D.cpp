#include <math.h>

#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Punto 2D_String/Point2D.h"
#include "../Punto 2D_String/Point2D.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Point2DTests
{
	TEST_CLASS(Point2DConstructorTests)
	{
	public:
		TEST_METHOD(Void)
		{
			cPoint2D p;
			Assert::IsTrue(p.x == 0 && p.y == 0);
		}

		TEST_METHOD(FloatFloat)
		{
			cPoint2D p(5.25f, -984.865f);
			Assert::IsTrue(p.x == 5.25f && p.y == -984.865f);
		}

	};

	TEST_CLASS(Point2DOperatorTests)
	{
	public:

		TEST_METHOD(OpSum)
		{
			cPoint2D p1(10.25f, 1000.05f);
			cPoint2D p2(50.50f, 512.25f);
			cPoint2D tmp;
			tmp = p1 + p2;
			Assert::IsTrue(tmp.x == p1.x + p2.x && tmp.y == p1.y + p2.y);
		}

		TEST_METHOD(OpSubstract)
		{
			cPoint2D p1(10.5f, 10.05f);
			cPoint2D p2(10.25f, 20.0f);
			cPoint2D tmp;
			tmp = p1 - p2;
			Assert::IsTrue(tmp.x == p1.x - p2.x && tmp.y == p1.y - p2.y);
		}

		TEST_METHOD(OpIncrease)
		{
			cPoint2D p1(10.5f, 30.25f);
			cPoint2D p2(40.75f, 0.50f);
			cPoint2D tmp(10.5f, 30.25f);
			p1 += p2;
			Assert::IsTrue((p1.x == tmp.x + p2.x) && (p1.y == tmp.y + p2.y));

		}

		TEST_METHOD(OpDecrease)
		{
			cPoint2D p1(10.50f, 5.25f);
			cPoint2D tmp(10.50f, 5.25f);
			cPoint2D p2(5.25f, 5.0f);
			p1 -= p2;
			Assert::IsTrue((p1.x == tmp.x - p2.x) && (p1.y == tmp.y - p2.y));
		}

		TEST_METHOD(OpAsign)
		{
			cPoint2D p1;
			cPoint2D p2(5.25f, 10.78f);
			p1 = p2;
			Assert::IsTrue(p1.x == p2.x && p1.y == p2.y);
		}

		TEST_METHOD(OpEqual)
		{
			cPoint2D p1(1.0f, 2.0f);
			cPoint2D p2(1.0f, 2.0f);
			cPoint2D p3(1.0f, 3.0f);
			cPoint2D p4(3.0f, 2.0f);

			if (p1 == p3 || p1 == p4 || p3 == p4) { Assert::IsTrue(false); }
			else if (p1 == p2) { Assert::IsTrue(true); }
			else Assert::IsTrue(false);
		}

		TEST_METHOD(OpDifferent)
		{
			cPoint2D p1(1.0f, 2.0f);
			cPoint2D p2(1.0f, 2.0f);
			cPoint2D p3(1.0f, 3.0f);
			cPoint2D p4(3.0f, 2.0f);

			if (p1 != p2) { Assert::IsTrue(false); }
			else if (p1 != p3 && p1 != p4 && p3 != p4){ Assert::IsTrue(true); }
			else { Assert::IsTrue(false); }
		}
	};

	TEST_CLASS(Point2DMethodsTests)
	{
	public:

		TEST_METHOD(SetToZero)
		{
			cPoint2D p(55, 1968);
			p.SetToZero();
			Assert::IsTrue(p.IsZero());
		}

		TEST_METHOD(Negate)
		{
			cPoint2D p1(25.5f, 100.05f);
			p1.Negate();
			Assert::IsTrue(p1.x == -25.5f && p1.y == -100.05f);
		}

		TEST_METHOD(IsZero)
		{
			cPoint2D p1;
			cPoint2D p2(5.0f, 0.0f);

			Assert::IsTrue(p1.IsZero() == true && p2.IsZero() != true);
		}

		TEST_METHOD(Distance)
		{
			cPoint2D p1, p2;
			cPoint2D p3(5.0f, 5.0f);
			cPoint2D p4(-70.0f, -26.5f);

			bool test1, test2, test3, test4;
			test1 = test2 = test3 = test4 = false;
			if (p1.Distance(p2) == 0)
			{
				test1 = true;
			}
			if (p1.Distance(p3) == hypot(5.0f, 5.0f))
			{
				test2 = true;
			}
			if (p1.Distance(p4) == hypot(-70.0f, -26.5f))
			{
				test3 = true;
			}
			if (p3.Distance(p4) == hypot(75.0f, 31.5f))
			{
				test4 = true;
			}

			Assert::IsTrue(test1 && test2 && test3 && test4);
		}

	};

}