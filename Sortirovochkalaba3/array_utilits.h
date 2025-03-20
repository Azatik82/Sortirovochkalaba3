#pragma once  // ������ �� ���������� ���������
#include <vector>  // ����������� ���������� ��� ������ � ���������
#include <string>  // ����������� ���������� ��� ������ �� ��������

namespace ArrayUtils {  // ������������ ��� ��� ������ � ���������
    enum class ArrayType {  // ������������ ��� ����� ��������
        RANDOM,  // ��������� �����
        SORTED,  // ������������� ������
        REVERSED,  // �������� �������
        PARTIALLY_SHUFFLED  // �������� ������������ ������
    };

    std::vector<int> generateArray(int size, ArrayType type);  // ������� ��� ��������� �������
    bool isSorted(const std::vector<int>& arr);  // ������� ��� �������� ����������
}