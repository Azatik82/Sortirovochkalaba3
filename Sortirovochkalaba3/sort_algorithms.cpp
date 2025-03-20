#include "sort_algorithms.h"  // Подключение заголовочного файла
#include <vector>  // Подключение библиотеки для работы с векторами

namespace SortingAlgorithms {  // Пространство имён для алгоритмов сортировки
    void countingSort(std::vector<int>& arr) {  // Реализация сортировки подсчётом
        if (arr.empty()) return;  // Если массив пуст, выходим

        int minVal = arr[0], maxVal = arr[0];  // Находим минимальное и максимальное значения
        for (int num : arr) {
            if (num < minVal) minVal = num;
            if (num > maxVal) maxVal = num;
        }

        int range = maxVal - minVal + 1;  // Вычисляем диапазон значений
        std::vector<int> counts(range, 0);  // Создаём массив для подсчёта

        for (int num : arr) counts[num - minVal]++;  // Подсчитываем количество каждого элемента

        int idx = 0;  // Индекс для восстановления массива
        for (int i = range - 1; i >= 0; --i) {  // Восстанавливаем массив в порядке убывания
            while (counts[i]--) arr[idx++] = i + minVal;
        }
    }

    void merge(std::vector<int>& arr, int left, int mid, int right) {  // Функция слияния
        int n1 = mid - left + 1;  // Размер левого подмассива
        int n2 = right - mid;  // Размер правого подмассива
        std::vector<int> L(n1), R(n2);  // Временные массивы

        for (int i = 0; i < n1; ++i) L[i] = arr[left + i];  // Копируем данные во временные массивы
        for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;  // Индексы для слияния
        while (i < n1 && j < n2) {  // Сливаем массивы, сохраняя порядок убывания
            if (L[i] >= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }

        while (i < n1) arr[k++] = L[i++];  // Дописываем оставшиеся элементы
        while (j < n2) arr[k++] = R[j++];
    }

    void mergeSort(std::vector<int>& arr, int left, int right) {  // Реализация сортировки слиянием
        if (left >= right) return;  // Базовый случай рекурсии
        int mid = left + (right - left) / 2;  // Находим середину
        mergeSort(arr, left, mid);  // Сортируем левую часть
        mergeSort(arr, mid + 1, right);  // Сортируем правую часть
        merge(arr, left, mid, right);  // Сливаем отсортированные части
    }
}