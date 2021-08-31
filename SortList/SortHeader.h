#pragma once

void PrintArray(int input[], int count);
void Swap(int& x, int& y);

// 거품 정렬(Bubble Sort)
// TC : Ot(n^2)
// SC : Os(n)
void BubbleSort(int input[], int count);

// 삽입 정렬 (Insertion Sort)
// TC : Ot(n^2)
// SC : Os(n)
void InsertionSort(int input[], int size);

// 병합 정렬(Merge Sort)
// TC : O(n log n)
// OC : O(n)
void MergeSort(int input[], int start, int end, int temp[]);
void Merge(int input[], int start, int half, int end, int temp[]);

// 퀵 정렬 (Quick Sort)
// TC : O(n log n)
// SC : O(n)
void QuickSort(int input[], int left, int right);
