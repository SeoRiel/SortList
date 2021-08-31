#include "SortHeader.h"

// ���� ����(Selection Sort)
// TC : O(n^2)
// SC : O(n)
void SelectionSort(int input[], int size)
{
	// 0���� size���� 
	for (int i = 0; i < size; ++i)
	{
		int minIndex = i;

		for (int j = i; j < size; ++j)
		{
			if (input[j] < input[minIndex])
			{
				minIndex = j;
			}
		}

		Swap(input[i], input[minIndex]);
	}
}