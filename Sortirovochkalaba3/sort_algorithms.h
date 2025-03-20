#pragma once  // Защита от повторного включения файла
#include <vector>  // Подключение библиотеки для работы с векторами

namespace SortingAlgorithms {  // Пространство имён для алгоритмов сортировки
    void countingSort(std::vector<int>& arr);  // Объявление функции сортировки подсчётом
    void mergeSort(std::vector<int>& arr, int left, int right);  // Объявление функции сортировки слиянием
}