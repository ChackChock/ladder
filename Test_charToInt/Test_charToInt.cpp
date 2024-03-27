#include "pch.h"
#include "CppUnitTest.h"
#include "../ladder/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestcharToInt
{
	TEST_CLASS(TestcharToInt)
	{
	public:

		TEST_METHOD(SampleTest)
		{
			int result = charToInt("5-3");
			Assert::AreEqual(result, -1);
		}

		TEST_METHOD(ArrayStartsWithMinus)
		{
			int result = charToInt("-53");
			Assert::AreEqual(result, -1);
		}

		TEST_METHOD(MinusInMiddleOfArray)
		{
			int result = charToInt("55-31");
			Assert::AreEqual(result, -1);
		}

		TEST_METHOD(MinusAtEndOfArray)
		{
			int result = charToInt("53-");
			Assert::AreEqual(result, -1);
		}
		TEST_METHOD(ArrayConsistsOfDigits)
		{
			int result = charToInt("53");
			Assert::AreEqual(result, 53);
		}
	};
}
