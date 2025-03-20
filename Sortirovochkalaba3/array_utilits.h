#pragma once  // Защита от повторного включения
#include <vector>  // Подключение библиотеки для работы с векторами
#include <string>  // Подключение библиотеки для работы со строками

namespace ArrayUtils {  // Пространство имён для работы с массивами
    enum class ArrayType {  // Перечисление для типов массивов
        RANDOM,  // Случайные числа
        SORTED,  // Упорядоченный массив
        REVERSED,  // Обратный порядок
        PARTIALLY_SHUFFLED  // Частично перемешанный массив
    };

    std::vector<int> generateArray(int size, ArrayType type);  // Функция для генерации массива
    bool isSorted(const std::vector<int>& arr);  // Функция для проверки сортировки
}