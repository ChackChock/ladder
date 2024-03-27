#include "pch.h"
#include "CppUnitTest.h"
#include "../ladder/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestcalculateLaddersNumber
{
	TEST_CLASS(TestcalculateLaddersNumber)
	{
	public:

		TEST_METHOD(SampleTest)
		{
			int result = calculateLaddersNumber(7, 6);
			Assert::AreEqual(4, result);
		}

		TEST_METHOD(OneCube)
		{
			int result = calculateLaddersNumber(2, 1);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(TwoCube)
		{
			int result = calculateLaddersNumber(3, 2);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(ThreeCube)
		{
			int result = calculateLaddersNumber(4, 3);
			Assert::AreEqual(2, result);
		}

		TEST_METHOD(EightCube)
		{
			int result = calculateLaddersNumber(9, 8);
			Assert::AreEqual(6, result);
		}

		TEST_METHOD(ElevenCube)
		{
			int result = calculateLaddersNumber(12, 11);
			Assert::AreEqual(12, result);
		}
	};
}
