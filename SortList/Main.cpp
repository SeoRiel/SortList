#include "SortHeader.h"

int main()
{
	const int ARRAY_SIZE{ 5 };
	int array[ARRAY_SIZE]{ 8, 7, 2, 3, 1 };

	// SquentialSort(array, ARRAY_SIZE);
	// SelectionSort(array, ARRAY_SIZE);
	// BubbleSort(array, ARRAY_SIZE);
	// InsertionSort(array, ARRAY_SIZE);

	//int temp[ARRAY_SIZE];
	//MergeSort(array, 0, ARRAY_SIZE - 1, temp);
	QuickSort(array, 0, ARRAY_SIZE - 1);


	// Ãâ·Â
	PrintArray(array, ARRAY_SIZE);
}