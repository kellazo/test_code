#include <math.h>

#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Punto 2D_String/Point2DTemplate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Point2DTests
{
	TEST_CLASS(Point2DTemplateConstructorTests)
	{
	public:
		TEST_METHOD(Void)
		{
			cPoint2DTemplate<bool> p;
			Assert::IsTrue(p.x == 0 && p.y == 0);
		}

		TEST_METHOD(FloatFloat)
		{
			cPoint2DTemplate<bool> p(true, false);
			Assert::IsTrue(p.x == true && p.y == false);
		}

	};

	TEST_CLASS(Point2DTemplateOperatorTests)
	{
	public:

		TEST_METHOD(OpSum)
		{
			cPoint2DTemplate<bool> p1(true, false);
			cPoint2DTemplate<bool> p2(false, false);
			cPoint2DTemplate<bool> tmp;
			tmp = p1 + p2;
			Assert::IsTrue(tmp.x == p1.x + p2.x && tmp.y == p1.y + p2.y);
		}

		TEST_METHOD(OpSubstract)
		{
			cPoint2DTemplate<bool> p1(10.5f, 10.05f);
			cPoint2DTemplate<bool> p2(10.25f, 20.0f);
			cPoint2DTemplate<bool> tmp;
			tmp = p1 - p2;
			Assert::IsTrue(tmp.x == p1.x - p2.x && tmp.y == p1.y - p2.y);
		}

		TEST_METHOD(OpIncrease)
		{
			cPoint2DTemplate<bool> p1(false, true);
			cPoint2DTemplate<bool> p2(false, false);
			cPoint2DTemplate<bool> tmp(false, true);
			p1 += p2;
			Assert::IsTrue((p1.x == tmp.x + p2.x) && (p1.y == tmp.y + p2.y));

		}

		TEST_METHOD(OpDecrease)
		{
			cPoint2DTemplate<bool> p1(10.50f, 5.25f);
			cPoint2DTemplate<bool> tmp(10.50f, 5.25f);
			cPoint2DTemplate<bool> p2(5.25f, 5.0f);
			p1 -= p2;
			Assert::IsTrue((p1.x == tmp.x - p2.x) && (p1.y == tmp.y - p2.y));
		}

		TEST_METHOD(OpAsign)
		{
			cPoint2DTemplate<bool> p1;
			cPoint2DTemplate<bool> p2(5.25f, 10.78f);
			p1 = p2;
			Assert::IsTrue(p1.x == p2.x && p1.y == p2.y);
		}

		TEST_METHOD(OpEqual)
		{
			cPoint2DTemplate<bool> p1(true, false);
			cPoint2DTemplate<bool> p2(true, false);
			cPoint2DTemplate<bool> p3(true, true);
			cPoint2DTemplate<bool> p4(false, false);

			if (p1 == p3 || p1 == p4 || p3 == p4) { Assert::IsTrue(false); }
			else if (p1 == p2) { Assert::IsTrue(true); }
			else Assert::IsTrue(false);
		}

		TEST_METHOD(OpDifferent)
		{
			cPoint2DTemplate<bool> p1(true, false);
			cPoint2DTemplate<bool> p2(true, false);
			cPoint2DTemplate<bool> p3(true, true);
			cPoint2DTemplate<bool> p4(false, false);

			if (p1 != p2) { Assert::IsTrue(false); }
			else if (p1 != p3 && p1 != p4 && p3 != p4){ Assert::IsTrue(true); }
			else { Assert::IsTrue(false); }
		}
	};

	TEST_CLASS(Point2DTemplateMethodsTests)
	{
	public:

		TEST_METHOD(SetToZero)
		{
			cPoint2DTemplate<bool> p(55, 1968);
			p.SetToZero();
			Assert::IsTrue(p.IsZero());
		}

		TEST_METHOD(IsZero)
		{
			cPoint2DTemplate<bool> p1;
			cPoint2DTemplate<bool> p2(5.0f, 0.0f);

			Assert::IsTrue(p1.IsZero() == true && p2.IsZero() != true);
		}

		TEST_METHOD(Distance)
		{
			cPoint2DTemplate<int> p1, p2;
			cPoint2DTemplate<int> p3(5, 5);
			cPoint2DTemplate<int> p4(-70, -26);

			bool test1, test2, test3, test4;
			test1 = test2 = test3 = test4 = false;
			if (p1.Distance(p2) == 0)
			{
				test1 = true;
			}
			if (p1.Distance(p3) == (int)hypot(5, 5))
			{
				test2 = true;
			}
			if (p1.Distance(p4) == (int)hypot(-70, -26))
			{
				test3 = true;
			}
			if (p3.Distance(p4) == (int)hypot(75, 31))
			{
				test4 = true;
			}

			Assert::IsTrue(test1 && test2 && test3 && test4);
		}

	};

}