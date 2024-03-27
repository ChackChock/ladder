#include "pch.h"
#include "CppUnitTest.h"
#include "../ladder/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestisNumberCorrect
{
	TEST_CLASS(TestisNumberCorrect)
	{
	public:

		TEST_METHOD(SampleTest)
		{
			ErrorCode code = isNumberCorrect(20);
			Assert::AreEqual(static_cast<int>(code), static_cast<int>(ErrorCode::NoError));
		}

		TEST_METHOD(NumberInRangeOfAcceptableValues)
		{
			ErrorCode code = isNumberCorrect(6);
			Assert::AreEqual(static_cast<int>(code), static_cast<int>(ErrorCode::NoError));
		}

		TEST_METHOD(NumberOutsideMaximumLimit)
		{
			ErrorCode code = isNumberCorrect(101);
			Assert::AreEqual(static_cast<int>(code), static_cast<int>(ErrorCode::IncorrectNumber));
		}

		TEST_METHOD(NumberIsZero)
		{
			ErrorCode code = isNumberCorrect(0);
			Assert::AreEqual(static_cast<int>(code), static_cast<int>(ErrorCode::IncorrectNumber));
		}

		TEST_METHOD(CouldNotFoundOpenInputFile)
		{
			ErrorCode code = isNumberCorrect(-2);
			Assert::AreEqual(static_cast<int>(code), static_cast<int>(ErrorCode::IncorrectInputFile));
		}

		TEST_METHOD(DataIsNotNaturalNumber)
		{
			ErrorCode code = isNumberCorrect(-1);
			Assert::AreEqual(static_cast<int>(code), static_cast<int>(ErrorCode::IncorrectInputData));
		}
	};
}
