#include "pch.h"
#include "CppUnitTest.h"
#include "..\pr1\cars.h"
#include <sstream>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(ValidAlphabetFormat)
		{
			std::vector<std::string> cases{
				"B123GC24 2023.3.31"
				"E814CB03 2023.9.3"
				"Y666CT99 2023.12.2"
				"O623YB83 2024.2.29"
			};
			for (int i = 0; i < cases.size(); i++) {
				istringstream ist(cases[i]);
				Car car;
				try {
					car.load(ist);
				}
				catch (runtime_error& e) {
					Assert::AreEqual(e.what(), "Invalid alphabet format in numbers!");
				}
			}
		};
		TEST_METHOD(InvalidAlphabetFormat) 
		{
			std::vector<std::string> cases{
				"B1234C24 2023u3.31"
			};
			for (int i = 0; i < cases.size(); i++) {
				istringstream ist(cases[i]);
				Car car;
				try {
					car.load(ist);
					Assert::Fail();
				}
				catch (runtime_error& e) {
					return;
				}
			}
		};
		TEST_METHOD(ValidateNumber)
		{
			std::vector<std::string> cases{
				"qwerreet`"
			};
			for (int i = 0; i < cases.size(); i++) {
				Car car;
				try {
					car.validateNumber(cases[i]);
					Assert::Fail();
				}
				catch (runtime_error& e) {
					//Assert::AreEqual(e.what(), "Invalid alphabet format in numbers!");
					return;
				}
			}
		};
	};
}
