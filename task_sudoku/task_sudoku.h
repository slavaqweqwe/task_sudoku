// task_sudoku.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once


#include <set>
#include <vector>


std::set<int> SearchColumnRowAndSquare(int Array[9][9], size_t i, size_t j);
void detectVariants(int Array[9][9], std::vector<std::set<int>>& s);
bool searcher(int inputArray[9][9]);
