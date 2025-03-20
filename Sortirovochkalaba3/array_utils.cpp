#include "array_utilits.h"  // Подключение заголовочного файла
#include <vector>  // Подключение библиотеки для работы с векторами
#include <cstdlib>  // Подключение библиотеки для работы с rand()
#include <algorithm>  // Подключение библиотеки для работы с std::swap

namespace ArrayUtils {  // Пространство имён для работы с массивами
    std::vector<int> generateRandomArray(int size) {  // Генерация случайного массива
        std::vector<int> arr(size);
        srand(42);  // Фиксированный seed для воспроизводимости
        int maxVal = size / 5;  // Максимальное значение
        for (int& num : arr) num = rand() % (maxVal + 1);  // Заполняем массив случайными числами
        return arr;
    }

    std::vector<int> generateSortedArray(int size) {  // Генерация отсортированного массива
        std::vector<int> arr(size);
        for (int i = 0; i < size; ++i) arr[i] = i + 1;  // Заполняем массив числами от 1 до size
        return arr;
    }

    std::vector<int> generateReversedArray(int size) {  // Генерация массива в обратном порядке
        std::vector<int> arr(size);
        for (int i = 0; i < size; ++i) arr[i] = size - i;  // Заполняем массив числами от size до 1
        return arr;
    }

    std::vector<int> generatePartiallyShuffledArray(int size) {  // Генерация частично перемешанного массива
        auto arr = generateSortedArray(size);  // Создаём отсортированный массив
        srand(42);  // Фиксированный seed
        for (int i = 0; i < size / 10; ++i) {  // Делаем N/10 перестановок
            int a = rand() % size, b = rand() % size;  // Выбираем случайные индексы
            std::swap(arr[a], arr[b]);  // Меняем элементы местами
        }
        return arr;
    }

    std::vector<int> generateArray(int size, ArrayType type) {  // Генерация массива заданного типа
        switch (type) {  // Выбор типа массива
        case ArrayType::RANDOM: return generateRandomArray(size);
        case ArrayType::SORTED: return generateSortedArray(size);
        case ArrayType::REVERSED: return generateReversedArray(size);
        case ArrayType::PARTIALLY_SHUFFLED: return generatePartiallyShuffledArray(size);
        default: return std::vector<int>();  // Возвращаем пустой массив, если тип не определён
        }
    }

    bool isSorted(const std::vector<int>& arr) {  // Проверка сортировки по убыванию
        for (size_t i = 1; i < arr.size(); ++i) {  // Проходим по массиву
            if (arr[i - 1] < arr[i]) return false;  // Если порядок нарушен, возвращаем false
        }
        return true;  // Массив отсортирован
    }
}