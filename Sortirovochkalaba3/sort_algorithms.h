#pragma once  // ������ �� ���������� ��������� �����
#include <vector>  // ����������� ���������� ��� ������ � ���������

namespace SortingAlgorithms {  // ������������ ��� ��� ���������� ����������
    void countingSort(std::vector<int>& arr);  // ���������� ������� ���������� ���������
    void mergeSort(std::vector<int>& arr, int left, int right);  // ���������� ������� ���������� ��������
}