#include "SortHeader.h"

// Äü Á¤·Ä (Quick Sort)
// TC : O(n log n)
// SC : O(n)
void QuickSort(int input[], int left, int right)
{
	int i{ left }, j{ right };
	int pivot{ input[(left + right) / 2] };

	do
	{
		while (input[i] < pivot)
		{
			i++;
		}
		while (input[j] > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			Swap(input[i], input[j]);
			i++;
			j--;
		}

	} while (i <= j);

	if (left < j)
	{
		QuickSort(input, left, j);
	}

	if (i < right)
	{
		QuickSort(input, i, right);
	}
}