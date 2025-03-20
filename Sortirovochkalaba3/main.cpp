#include "sort_algorithms.h"  // Подключение заголовочного файла с алгоритмами сортировки
#include "array_utilits.h"  // Подключение заголовочного файла для работы с массивами
#include <iostream>  // Подключение библиотеки для ввода/вывода
#include <chrono>  // Подключение библиотеки для замера времени
#include <iomanip>  // Подключение библиотеки для форматирования вывода
#include <vector>  // Подключение библиотеки для работы с векторами
#include <string>  // Подключение библиотеки для работы со строками

template<typename Func>
double measureTime(const std::vector<int>& original, Func sortFunc, int K) {  // Функция для замера времени
    auto start = std::chrono::high_resolution_clock::now();  // Начало замера
    for (int i = 0; i < K; ++i) {  // Повторяем сортировку K раз
        std::vector<int> copy = original;  // Копируем массив
        sortFunc(copy);  // Сортируем копию
    }
    auto end = std::chrono::high_resolution_clock::now();  // Конец замера
    return std::chrono::duration<double>(end - start).count() / K;  // Возвращаем среднее время
}

void testCorrectness() {  // Тестирование корректности сортировки
    std::vector<int> testArray = { 3, 1, 4, 1, 5, 9, 2, 6 };  // Тестовый массив
    auto test1 = testArray, test2 = testArray;  // Копии массива

    SortingAlgorithms::countingSort(test1);  // Сортировка подсчётом
    SortingAlgorithms::mergeSort(test2, 0, test2.size() - 1);  // Сортировка слиянием

    std::cout << "CountingSort test: " << (ArrayUtils::isSorted(test1) ? "OK" : "FAIL") << "\n";  // Проверка результата
    std::cout << "MergeSort test:    " << (ArrayUtils::isSorted(test2) ? "OK" : "FAIL") << "\n\n";  // Проверка результата
}

void runBenchmarks() {  // Запуск бенчмарков
    const std::vector<int> sizes = { 1000, 10000, 100000 };  // Размеры массивов
    const int K = 100;  // Количество повторений

    for (int size : sizes) {  // Проходим по каждому размеру
        std::cout << "\nSize: " << size << std::endl;

        auto random = ArrayUtils::generateArray(size, ArrayUtils::ArrayType::RANDOM);  // Генерация массивов
        auto sorted = ArrayUtils::generateArray(size, ArrayUtils::ArrayType::SORTED);
        auto reversed = ArrayUtils::generateArray(size, ArrayUtils::ArrayType::REVERSED);
        auto partial = ArrayUtils::generateArray(size, ArrayUtils::ArrayType::PARTIALLY_SHUFFLED);

        std::vector<std::pair<std::vector<int>, std::string>> testData = {  // Тестовые данные
            {random, "Random"},
            {sorted, "Sorted"},
            {reversed, "Reversed"},
            {partial, "Partial"}
        };

        for (const auto& data : testData) {  // Проходим по каждому типу массива
            const std::vector<int>& arr = data.first;  // Массив
            const std::string& name = data.second;  // Название типа

            std::cout << "  " << name << ":" << std::endl;  // Выводим название типа
            double timeCounting = measureTime(arr, [](auto& v) { SortingAlgorithms::countingSort(v); }, K);  // Замер времени для CountingSort
            double timeMerge = measureTime(arr, [](auto& v) { SortingAlgorithms::mergeSort(v, 0, v.size() - 1); }, K);  // Замер времени для MergeSort

            std::cout << std::fixed << std::setprecision(6)  // Форматированный вывод
                << "    CountingSort: " << timeCounting << "s\n"
                << "    MergeSort:    " << timeMerge << "s\n";
        }
    }
}

int main() {  // Основная функция
    testCorrectness();  // Тестирование корректности
    runBenchmarks();  // Запуск бенчмарков
    return 0;  // Завершение программы
}