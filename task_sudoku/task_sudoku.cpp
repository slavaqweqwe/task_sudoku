// task_sudoku.cpp: определяет точку входа для приложения.
//

#include "task_sudoku.h"



std::set<int> SearchColumnRowAndSquare(int Array[9][9], size_t i, size_t j) {

	size_t N = 9;
	size_t sqrtN = 3;
	std::set<int> possibleValues = { 1,2,3,4,5,6,7,8,9 };

	for (size_t n = 0; n < N; n++) {
		if ((Array[i][n] > 0) & (n!=j)) {
			possibleValues.erase(Array[i][n]);
		}
	}

	for (size_t n = 0; n < N; n++) {
		if ((Array[n][j] > 0) & (n != i)) {
			possibleValues.erase(Array[n][j]);
		}
	}

	size_t SquareNumColumn = i / sqrtN;
	size_t SquareNumRow = j / sqrtN;
	for (size_t ni = 0; ni < sqrtN; ni++) {
		for (size_t nj = 0; nj < sqrtN; nj++) {
			if ((Array[SquareNumColumn * sqrtN + ni][SquareNumRow * sqrtN + nj] > 0) & (SquareNumColumn * sqrtN + ni!=i) & (SquareNumRow * sqrtN + nj!=j)) {
				possibleValues.erase(Array[SquareNumColumn * sqrtN + ni][SquareNumRow * sqrtN + nj]);
			}
		}
	}
	return possibleValues;
}
void detectVariants(int Array[9][9], std::vector<std::set<int>>& VariantsForAdd) {
	size_t N = 9;


	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N; j++) {
			if (*VariantsForAdd[i + j * N].begin() != -1) {
				VariantsForAdd[i + j * N] = SearchColumnRowAndSquare(Array, i, j);
			}
			else {
				auto a = SearchColumnRowAndSquare(Array, i, j);
				if (SearchColumnRowAndSquare(Array, i, j).count(Array[i][j]) == 0) {
					VariantsForAdd[i + j * N] = { -2 };
				}

			}
		}
	}
}




bool searcher(int inputArray[9][9] )
{


	size_t N = 9;
	bool solutionFound = false;
	size_t addrMini = -1, addrMinj = -1, minValue=9;
	int Array[9][9];
	//cout << inputArray[0][0];

	std::vector<std::set<int>> VariantsForAdd(N*N) ;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Array[i][j] = inputArray[i][j];

			if (Array[i][j] == 0) {
				
				VariantsForAdd[i + j * N] = { 1,2,3,4,5,6,7,8,9 };
			}
			else {
				VariantsForAdd[i + j * N] = { -1 };
			}
		}
	}

	while (true)
	{
		bool isOneVariant=false;
		bool isVariant = true;
		minValue = 10;
		addrMini = -1;
		addrMinj = -1;
		detectVariants(Array, VariantsForAdd);
		for (size_t i = 0; i < N; i++) {
			for (size_t j = 0; j < N; j++) {
				if (VariantsForAdd[i + j * N].empty()  | (*VariantsForAdd[i + j * N].begin()==-2)) {
					isVariant = false;
					break;
				}
				else if ( (VariantsForAdd[i + j * N].size() == 1) & ( *VariantsForAdd[i + j * N].begin()>0 ) ) {
					isOneVariant = true;
					Array[i][j] = *VariantsForAdd[i + j * N].begin();
					VariantsForAdd[i + j * N] = { -1 };
				}
				else if (*VariantsForAdd[i + j * N].begin() > 0){
					if (VariantsForAdd[i + j * N].size() < minValue) {
						addrMini = i;
						addrMinj = j;
						minValue = VariantsForAdd[i + j * N].size();
					}
				}
			}
			if (!isVariant) { break; }
		}

		if (!isVariant) {
			break;
		}

		if (!isOneVariant)
		{

			if (addrMini == -1) {
				solutionFound = true;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						inputArray[i][j] = Array[i][j];
					}
				}
				break;
			}

			int assumptionArray[9][9];
			std::set<int>::iterator it;

			for (auto it: VariantsForAdd[addrMini + addrMinj * N]) {
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						assumptionArray[i][j] = Array[i][j];
					}
				}
				assumptionArray[addrMini][addrMinj] = it;

				solutionFound=searcher(assumptionArray);

				if (solutionFound) {
					for (int i = 0; i < N; i++) {
						for (int j = 0; j < N; j++) {
							inputArray[i][j] = assumptionArray[i][j];
						}
					}
					break;
				}

			}

			return solutionFound;
		}
	}
	return solutionFound;
}





