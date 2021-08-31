#include "SortHeader.h"

// 거품 정렬(Bubble Sort)
// TC : Ot(n^2)
// SC : Os(n)
void BubbleSort(int input[], int count)
{
	for (int step = 0; step < count - 1; ++count)
	{
		for (int i = 0; i < count - step - 1; ++i)
		{
			if (input[i] > input[i + 1])
			{
				Swap(input[i], input[i + 1]);
			}
		}
	}

}