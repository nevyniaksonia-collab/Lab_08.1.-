#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08.1.рек/Lab_08.1.рек.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest811
{
	TEST_CLASS(UnitTest811)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Assert::AreEqual(0, Count("", 0));
            Assert::AreEqual(0, Count("abc", 0));
            Assert::AreEqual(1, Count("no", 0));
            Assert::AreEqual(4, Count("nono on xyz", 0));
		}
		TEST_METHOD(TestMethod2)
		{
            char* buffer;
            char* result;
            const char* input_str;

            input_str = "no";
            buffer = new char[10]; buffer[0] = '\0';
            result = Replace(input_str, buffer, buffer, 0);
            Assert::AreEqual(std::string("***"), std::string(result));
            delete[] buffer;

            input_str = "on";
            buffer = new char[10]; buffer[0] = '\0';
            result = Replace(input_str, buffer, buffer, 0);
            Assert::AreEqual(std::string("***"), std::string(result));
            delete[] buffer;

            input_str = "abc";
            buffer = new char[10]; buffer[0] = '\0';
            result = Replace(input_str, buffer, buffer, 0);
            Assert::AreEqual(std::string("abc"), std::string(result));
            delete[] buffer;

            input_str = "nono on xyz";
            buffer = new char[50]; buffer[0] = '\0';
            result = Replace(input_str, buffer, buffer, 0);
            Assert::AreEqual(std::string("****** *** xyz"), std::string(result));
            delete[] buffer;
		}
	};
}
