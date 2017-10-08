#include "stdafx.h"
#include <stdlib.h>
#include "../src/MiniLeaderboard.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class MiniLeaderboardSpec
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

#pragma endregion 



		void compareStrings_Leaderboard(char *expected, char * actual) {
			int i = 0;
			while (expected[i] != '\0') {
				Assert::AreEqual(expected[i],actual[i], L"Leaderboard expected and actual string mismatch, copy test case into main and check the output", 1, 2);
				i++ ;
			}
			if (actual[i] != '\0') {
				Assert::Fail("Output string not ended with slash 0");
			}
		}

		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Sample1()
		{
			char *s1 = "abc,3\nbca,4\n";
			char *s2 = "bca,99\n";
			char *s3 = "cca,100\n";
			char * expected = "bca,4,99,0,103\n"
				              "cca,0,0,100,100\n"
							  "abc,3,0,0,3\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}

		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Sample2()
		{
			char *s1 = "abc,3\nbca,4\naaa,12\naab,56\nccc,100\n";
			char *s2 = "bca,99\nccc,100\n";
			char *s3 = "";
			char * expected = "ccc,100,100,0,200\n"
				              "bca,4,99,0,103\n"
							  "aab,56,0,0,56\n"
							  "aaa,12,0,0,12\n"
							  "abc,3,0,0,3\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}

	};
}
