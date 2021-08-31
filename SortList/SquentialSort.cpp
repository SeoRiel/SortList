#include "SortHeader.h"

// 순차 정렬 (Squential Sort)
// TC : O(n^2)
// SC : O(n)
void SquentialSort(int input[], int count)
{
	for (int i = 0; i < count - 1; ++i)
	{
		for (int j = i + 1; j < count; ++j)
		{
			if (input[i] < input[j])
			{
				Swap(input[i], input[j]);
			}
		}
	}
}