#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Punto 2D_String/String.h"
#include "../Punto 2D_String/String.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace StringTests
{
	TEST_CLASS(StringConstructorTests)
	{
	public:

		TEST_METHOD(Void)
		{
			cString str1;
			char* str2 = "";
			Assert::IsTrue(strcmp(str1.GetString(), str2) == 0);
		}

		TEST_METHOD(Char)
		{
			cString str1("Hola Mundo");
			char* str2 = "Hola Mundo";
			Assert::IsTrue(strcmp(str1.GetString(), str2) == 0);
		}

		TEST_METHOD(String)
		{
			cString str1("String por chars");
			cString str2(str1);
			Assert::IsTrue(strcmp(str1.GetString(), str2.GetString()) == 0);
		}
	};

	TEST_CLASS(StringOperatorTests)
	{
	public:

		TEST_METHOD(OpEqualChar)
		{
			cString str1("Hola Mundo");
			Assert::IsTrue(str1=="Hola Mundo");
			Assert::IsFalse(str1 == "Diferente");
		}

		TEST_METHOD(OpEqualString)
		{
			cString str1("Hola Mundo");
			cString str2("Hola Mundo");
			cString str3("Diferente");
			Assert::IsTrue(str1 == str2);
			Assert::IsFalse(str1 == str3);
		}

		TEST_METHOD(OpDifferentChar)
		{
			cString str1("Hola Mundo");
			Assert::IsFalse(str1 != "Hola Mundo");
			Assert::IsTrue(str1 != "Diferente");
		}

		TEST_METHOD(OpDifferentString)
		{
			cString str1("Hola Mundo");
			cString str2("Hola Mundo");
			cString str3("Diferente");
			Assert::IsFalse(str1 != str2);
			Assert::IsTrue(str1 != str3);
		}

		TEST_METHOD(OpAssignChar)
		{
			cString str1("Valor Inicial");
			char* str2 = "Valor final";
			str1 = str2;
			Assert::IsTrue(strcmp(str1.GetString(), str2) == 0);
		}

		TEST_METHOD(OpAssignString)
		{
			cString str1("Valor str1");
			cString str2("Valor str2");
			str1 = str2;
			Assert::IsTrue(strcmp(str1.GetString(), str2.GetString()) == 0);
		}

		TEST_METHOD(OpIncreaseChar)
		{
			cString str1("str1");
			str1 += "afegit";
			Assert::IsTrue(strcmp(str1.GetString(), "str1afegit") == 0);
		}

		TEST_METHOD(OpIncreaseString)
		{
			cString str1("str1");
			cString str2("afegit");
			str1 += str2;
			Assert::IsTrue(strcmp(str1.GetString(), "str1afegit") == 0);
		}
	};

	TEST_CLASS(StringMethodsTests)
	{
	public:
		
		TEST_METHOD(Replace)
		{
			cString myString("Wednesday is hump day, but has anyone asked the camel if he’s happy about it?");

			myString.Replace("day", "but");
			myString.Replace("camel", "fox");
			myString.Replace("but", "however");
			myString.Replace("h", "");

			Assert::IsTrue(myString == "Wednesowever is ump owever, owever as anyone asked te fox if e’s appy about it?");
		}
        
		TEST_METHOD(Clear)
		{
			cString str1("Esto es el String");
			cString str2;
			str1.Clear();
			Assert::IsTrue(strcmp(str1.GetString(), str2.GetString()) == 0);
		}

		TEST_METHOD(Len)
		{
			cString str1("Hola Mundo");
			Assert::IsTrue(str1.Len()==10);
		}

		TEST_METHOD(Capacity)
		{
			cString str1("Hola Mundo");
			Assert::IsTrue(str1.Capacity()==11);
		}

		TEST_METHOD(GetString)
		{
			cString str1("Hola Mundo");
			Assert::IsTrue(strcmp(str1.GetString(), str1.GetString()) == 0);
		}
	};
}