// my_sin.cpp: определяет точку входа для приложения.
//

#include <gtest/gtest.h>
#include "task_sudoku.h"

void plotResult(int inArray[9][9], int outArray[9][9], bool isSearch) {
	HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_INTENSITY);
	size_t N = 9;
	if (isSearch)
		std::cout << std::endl << "solution found :)" << std::endl;
	else
		std::cout << std::endl << "solution not found :(" << std::endl;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j % 3 == 0) std::cout << ' ';
			if (inArray[i][j] == 0)
			{
				SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN);
				std::cout << outArray[i][j] << ' ';
			}
			else
			{
				SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_INTENSITY);
				std::cout << outArray[i][j] << ' ';
			}
		}
		if (i % 3 == 2) std::cout << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;

}



TEST(task_GOOD_DATA, size8)
{
	
	size_t N = 9;
	int inputArray[9][9] = {
	{ 0, 0, 0,   0, 0,0,  0, 0,0},
	{ 0, 3, 0,   0, 0,0,  0, 0,0},
	{ 0, 0, 4,   0, 0,0,  0, 0,0},

	{ 0, 0, 0,   0, 0,0,  0, 0,0},
	{ 0, 0, 0,   0, 8,0,  0, 0,0},
	{ 0, 0, 0,   0, 0,0,  0, 0,0},

	{ 0, 0, 0,   0, 0,0,  0, 0,0},
	{ 0, 0, 0,   0, 0,0,  0, 0,0},
	{ 1, 9, 6,   0, 0,0,  0, 0,0},
	};
	int copyArray[9][9];

	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N; j++) {
			copyArray[i][j] = inputArray[i][j];
		}
	}
	bool isSearch = searcher(inputArray);

    plotResult(copyArray, inputArray, isSearch);
	EXPECT_TRUE(isSearch);
}



TEST(task_VOID_DATA, size8)
{

	size_t N = 9;
	int inputArray[9][9] = {
	{ 0, 0, 0,   0, 0,0,  0, 0,0},
	{ 0, 0, 0,   0, 0,0,  0, 0,0},
	{ 0, 0, 0,   0, 0,0,  0, 0,0},

	{ 0, 0, 0,   0, 0,0,  0, 0,0},
	{ 0, 0, 0,   0, 0,0,  0, 0,0},
	{ 0, 0, 0,   0, 0,0,  0, 0,0},

	{ 0, 0, 0,   0, 0,0,  0, 0,0},
	{ 0, 0, 0,   0, 0,0,  0, 0,0},
	{ 0, 0, 0,   0, 0,0,  0, 0,0},
	};
	int copyArray[9][9];

	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N; j++) {
			copyArray[i][j] = inputArray[i][j];
		}
	}

	bool isSearch = searcher(inputArray);
	plotResult(copyArray, inputArray, isSearch);
	EXPECT_TRUE(isSearch);
}


TEST(task_BAD_DATA, size8)
{
	size_t N = 9;
	int inputArray[9][9] = {
	{ 1, 1, 0,   0, 0,0,  0, 0,0},
	{ 0, 0, 0,   0, 0,0,  0, 0,0},
	{ 0, 0, 0,   0, 0,0,  0, 0,0},

	{ 0, 0, 0,   0, 0,0,  0, 0,0},
	{ 0, 0, 0,   0, 0,0,  0, 0,0},
	{ 0, 0, 0,   0, 0,0,  0, 0,0},

	{ 0, 0, 0,   0, 0,0,  0, 0,0},
	{ 0, 0, 0,   0, 0,0,  0, 0,0},
	{ 0, 0, 0,   0, 0,0,  0, 0,0},
	};
	int copyArray[9][9];

	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N; j++) {
			copyArray[i][j] = inputArray[i][j];
		}
	}

	bool isSearch = searcher(inputArray);
	plotResult(copyArray, inputArray, isSearch);
	EXPECT_TRUE(!isSearch);
}
TEST(task_PICTURE_FROM_THE_INTERNET, size8)
{
	size_t N = 9;
	int inputArray[9][9] = {
	{ 0, 0, 0,   0, 9,0,  8, 2,0},
	{ 0, 2, 0,   0, 0,0,  5, 0,9},
	{ 7, 0, 9,   0, 1,0,  0, 0,0},

	{ 0, 6, 2,   7, 0,1,  0, 9,0},
	{ 0, 0, 0,   0, 6,0,  0, 0,0},
	{ 0, 8, 0,   3, 0,9,  1, 4,0},

	{ 0, 0, 0,   0, 8,0,  9, 0,2},
	{ 8, 0, 4,   0, 0,0,  0, 3,0},
	{ 0, 1, 6,   0, 3,0,  0, 0,0},
	};
	int copyArray[9][9];

	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N; j++) {
			copyArray[i][j] = inputArray[i][j];
		}
	}

	bool isSearch = searcher(inputArray);
	plotResult(copyArray, inputArray, isSearch);
	EXPECT_TRUE(isSearch);
}
int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}