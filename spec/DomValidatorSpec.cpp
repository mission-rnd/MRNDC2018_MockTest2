#include "stdafx.h"


#include "./../src/DomValidator.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class DomValidatorSpec
	{
	private:
		TestContext^ testContextInstance;

	public:
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

#pragma region Additional test attributes
		//
		//You can use the following additional attributes as you write your tests:
		//
		//Use ClassInitialize to run code before running the first test in the class
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//Use ClassCleanup to run code after all tests in a class have run
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//Use TestInitialize to run code before running each test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Use TestCleanup to run code after each test has run
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
#pragma endregion 


		[TestMethod, Timeout(3000)]
		void dom_basic_single_tag()
		{
			char *input = "<html></html>";
			int op = isStringValidDom(input);
			int expected = 1;
			Assert::AreEqual(expected, op, L"DOM is valid", 1, 2);

			input = "<html><html>";
			op = isStringValidDom(input);
			expected = -1;
			Assert::AreEqual(expected, op, L"DOM is valid", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void dom_basic_syntax()
		{
			char *input = "<html><head></head></html>";
			int op = isStringValidDom(input);
			int expected = 1;
			Assert::AreEqual(expected, op, L"output is wrong", 1, 2);

			input = "<html><head><head></html>";
			op = isStringValidDom(input);
			expected = -1;
			Assert::AreEqual(expected, op, L"output is wrong", 1, 2);
		}
	};
}
