#include "pch.h"
#include "CppUnitTest.h"
#include "../Project_opp_3.3C/Money.cpp"
#include "../Project_opp_3.3C/Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestopp33C
{
	TEST_CLASS(UnitTestopp33C)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			unsigned char c;
			Money a(10, 15);
			c = a.GetKopiyku();
			Assert::AreEqual(c, (unsigned char)15);
		}
	};
}
