#include "sort_algorithms.h"  // ����������� ������������� �����
#include <vector>  // ����������� ���������� ��� ������ � ���������

namespace SortingAlgorithms {  // ������������ ��� ��� ���������� ����������
    void countingSort(std::vector<int>& arr) {  // ���������� ���������� ���������
        if (arr.empty()) return;  // ���� ������ ����, �������

        int minVal = arr[0], maxVal = arr[0];  // ������� ����������� � ������������ ��������
        for (int num : arr) {
            if (num < minVal) minVal = num;
            if (num > maxVal) maxVal = num;
        }

        int range = maxVal - minVal + 1;  // ��������� �������� ��������
        std::vector<int> counts(range, 0);  // ������ ������ ��� ��������

        for (int num : arr) counts[num - minVal]++;  // ������������ ���������� ������� ��������

        int idx = 0;  // ������ ��� �������������� �������
        for (int i = range - 1; i >= 0; --i) {  // ��������������� ������ � ������� ��������
            while (counts[i]--) arr[idx++] = i + minVal;
        }
    }

    void merge(std::vector<int>& arr, int left, int mid, int right) {  // ������� �������
        int n1 = mid - left + 1;  // ������ ������ ����������
        int n2 = right - mid;  // ������ ������� ����������
        std::vector<int> L(n1), R(n2);  // ��������� �������

        for (int i = 0; i < n1; ++i) L[i] = arr[left + i];  // �������� ������ �� ��������� �������
        for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;  // ������� ��� �������
        while (i < n1 && j < n2) {  // ������� �������, �������� ������� ��������
            if (L[i] >= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }

        while (i < n1) arr[k++] = L[i++];  // ���������� ���������� ��������
        while (j < n2) arr[k++] = R[j++];
    }

    void mergeSort(std::vector<int>& arr, int left, int right) {  // ���������� ���������� ��������
        if (left >= right) return;  // ������� ������ ��������
        int mid = left + (right - left) / 2;  // ������� ��������
        mergeSort(arr, left, mid);  // ��������� ����� �����
        mergeSort(arr, mid + 1, right);  // ��������� ������ �����
        merge(arr, left, mid, right);  // ������� ��������������� �����
    }
}