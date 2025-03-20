#include "sort_algorithms.h"  // ����������� ������������� ����� � ����������� ����������
#include "array_utilits.h"  // ����������� ������������� ����� ��� ������ � ���������
#include <iostream>  // ����������� ���������� ��� �����/������
#include <chrono>  // ����������� ���������� ��� ������ �������
#include <iomanip>  // ����������� ���������� ��� �������������� ������
#include <vector>  // ����������� ���������� ��� ������ � ���������
#include <string>  // ����������� ���������� ��� ������ �� ��������

template<typename Func>
double measureTime(const std::vector<int>& original, Func sortFunc, int K) {  // ������� ��� ������ �������
    auto start = std::chrono::high_resolution_clock::now();  // ������ ������
    for (int i = 0; i < K; ++i) {  // ��������� ���������� K ���
        std::vector<int> copy = original;  // �������� ������
        sortFunc(copy);  // ��������� �����
    }
    auto end = std::chrono::high_resolution_clock::now();  // ����� ������
    return std::chrono::duration<double>(end - start).count() / K;  // ���������� ������� �����
}

void testCorrectness() {  // ������������ ������������ ����������
    std::vector<int> testArray = { 3, 1, 4, 1, 5, 9, 2, 6 };  // �������� ������
    auto test1 = testArray, test2 = testArray;  // ����� �������

    SortingAlgorithms::countingSort(test1);  // ���������� ���������
    SortingAlgorithms::mergeSort(test2, 0, test2.size() - 1);  // ���������� ��������

    std::cout << "CountingSort test: " << (ArrayUtils::isSorted(test1) ? "OK" : "FAIL") << "\n";  // �������� ����������
    std::cout << "MergeSort test:    " << (ArrayUtils::isSorted(test2) ? "OK" : "FAIL") << "\n\n";  // �������� ����������
}

void runBenchmarks() {  // ������ ����������
    const std::vector<int> sizes = { 1000, 10000, 100000 };  // ������� ��������
    const int K = 100;  // ���������� ����������

    for (int size : sizes) {  // �������� �� ������� �������
        std::cout << "\nSize: " << size << std::endl;

        auto random = ArrayUtils::generateArray(size, ArrayUtils::ArrayType::RANDOM);  // ��������� ��������
        auto sorted = ArrayUtils::generateArray(size, ArrayUtils::ArrayType::SORTED);
        auto reversed = ArrayUtils::generateArray(size, ArrayUtils::ArrayType::REVERSED);
        auto partial = ArrayUtils::generateArray(size, ArrayUtils::ArrayType::PARTIALLY_SHUFFLED);

        std::vector<std::pair<std::vector<int>, std::string>> testData = {  // �������� ������
            {random, "Random"},
            {sorted, "Sorted"},
            {reversed, "Reversed"},
            {partial, "Partial"}
        };

        for (const auto& data : testData) {  // �������� �� ������� ���� �������
            const std::vector<int>& arr = data.first;  // ������
            const std::string& name = data.second;  // �������� ����

            std::cout << "  " << name << ":" << std::endl;  // ������� �������� ����
            double timeCounting = measureTime(arr, [](auto& v) { SortingAlgorithms::countingSort(v); }, K);  // ����� ������� ��� CountingSort
            double timeMerge = measureTime(arr, [](auto& v) { SortingAlgorithms::mergeSort(v, 0, v.size() - 1); }, K);  // ����� ������� ��� MergeSort

            std::cout << std::fixed << std::setprecision(6)  // ��������������� �����
                << "    CountingSort: " << timeCounting << "s\n"
                << "    MergeSort:    " << timeMerge << "s\n";
        }
    }
}

int main() {  // �������� �������
    testCorrectness();  // ������������ ������������
    runBenchmarks();  // ������ ����������
    return 0;  // ���������� ���������
}