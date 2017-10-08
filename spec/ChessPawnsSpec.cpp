#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "../src/ChessPawns.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class ChessPawnsSpec
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

#define ___ '.'
#define _b_ 'b'
#define _w_ 'w'


		[TestMethod, Timeout(1000)]
		void ChessGame_Samples_Test01()
		{
			char board1[8][8] =
			{
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ _b_, _b_, _b_, _b_, _b_, _b_, _b_, _b_ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ _w_, _w_, _w_, _w_, _w_, _w_, _w_, _w_ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
			};
			char colorWon1;
			int minMoves1 = chessGame(board1, &colorWon1);
			Assert::AreEqual(minMoves1, 0, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon1, '\0', L"Wrong Answer", 1, 2);


			char board2[8][8] =
			{
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, _b_, _b_ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, _b_, ___ },
				{ _w_, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
			};
			char colorWon2;
			int minMoves2 = chessGame(board2, &colorWon2);
			Assert::AreEqual(minMoves2, 2, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon2, 'b', L"Wrong Answer", 1, 2);

			char board3[8][8] =
			{
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, _b_, ___, ___, ___, ___ },
				{ ___, ___, ___, _w_, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
			};
			char colorWon3;
			int minMoves3 = chessGame(board3, &colorWon3);
			Assert::AreEqual(minMoves3, 0, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon3, '\0', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Samples_Test02()
		{
			char board2[8][8] =
			{
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, _b_, _b_ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, _b_, ___ },
				{ _w_, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
			};
			char colorWon2;
			int minMoves2 = chessGame(board2, &colorWon2);
			Assert::AreEqual(minMoves2, 2, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon2, 'b', L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void ChessGame_Samples_Test03()
		{
			
			char board3[8][8] =
			{
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, _b_, ___, ___, ___, ___ },
				{ ___, ___, ___, _w_, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
			};
			char colorWon3;
			int minMoves3 = chessGame(board3, &colorWon3);
			Assert::AreEqual(minMoves3, 0, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon3, '\0', L"Wrong Answer", 1, 2);
		};

	};

}