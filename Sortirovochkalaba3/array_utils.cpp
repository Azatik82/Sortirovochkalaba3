#include "array_utilits.h"  // ����������� ������������� �����
#include <vector>  // ����������� ���������� ��� ������ � ���������
#include <cstdlib>  // ����������� ���������� ��� ������ � rand()
#include <algorithm>  // ����������� ���������� ��� ������ � std::swap

namespace ArrayUtils {  // ������������ ��� ��� ������ � ���������
    std::vector<int> generateRandomArray(int size) {  // ��������� ���������� �������
        std::vector<int> arr(size);
        srand(42);  // ������������� seed ��� �����������������
        int maxVal = size / 5;  // ������������ ��������
        for (int& num : arr) num = rand() % (maxVal + 1);  // ��������� ������ ���������� �������
        return arr;
    }

    std::vector<int> generateSortedArray(int size) {  // ��������� ���������������� �������
        std::vector<int> arr(size);
        for (int i = 0; i < size; ++i) arr[i] = i + 1;  // ��������� ������ ������� �� 1 �� size
        return arr;
    }

    std::vector<int> generateReversedArray(int size) {  // ��������� ������� � �������� �������
        std::vector<int> arr(size);
        for (int i = 0; i < size; ++i) arr[i] = size - i;  // ��������� ������ ������� �� size �� 1
        return arr;
    }

    std::vector<int> generatePartiallyShuffledArray(int size) {  // ��������� �������� ������������� �������
        auto arr = generateSortedArray(size);  // ������ ��������������� ������
        srand(42);  // ������������� seed
        for (int i = 0; i < size / 10; ++i) {  // ������ N/10 ������������
            int a = rand() % size, b = rand() % size;  // �������� ��������� �������
            std::swap(arr[a], arr[b]);  // ������ �������� �������
        }
        return arr;
    }

    std::vector<int> generateArray(int size, ArrayType type) {  // ��������� ������� ��������� ����
        switch (type) {  // ����� ���� �������
        case ArrayType::RANDOM: return generateRandomArray(size);
        case ArrayType::SORTED: return generateSortedArray(size);
        case ArrayType::REVERSED: return generateReversedArray(size);
        case ArrayType::PARTIALLY_SHUFFLED: return generatePartiallyShuffledArray(size);
        default: return std::vector<int>();  // ���������� ������ ������, ���� ��� �� ��������
        }
    }

    bool isSorted(const std::vector<int>& arr) {  // �������� ���������� �� ��������
        for (size_t i = 1; i < arr.size(); ++i) {  // �������� �� �������
            if (arr[i - 1] < arr[i]) return false;  // ���� ������� �������, ���������� false
        }
        return true;  // ������ ������������
    }
}