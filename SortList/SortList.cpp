#include <iostream>

void PrintArray(int input[], int count)
{
	for (int i = 0; i < count; ++i)
	{
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;
}

void Swap(int& x, int& y)
{
	int temp{ x };
	x = y;
	y = temp;

}

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

// 선택 정렬(Selection Sort)
// TC : O(n^2)
// SC : O(n)
void SelectionSort(int input[], int size)
{
	// 0부터 size까지 
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

// 삽입 정렬 (Insertion Sort)
// TC : Ot(n^2)
// SC : Os(n)
void InsertionSort(int input[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		int j{ i };
		int target{ input[i] };

		while (--j >= 0 && target < input[i])
		{
			input[j + 1] = input[j];
			input[j] = target;
		}
	}
}

// 병합 정렬(Merge Sort)
void Merge(int input[], int start, int half, int end, int temp[])
{
	int i{ start };
	int j{ half + 1 };
	int k{};

	// while : 원소가 있을 때
	while (i <= half && j <= end)
	{
		// 한 개씩 꺼내서
		// 작은 수 왼쪽, 큰 수 오른쪽
		if (input[i] < input[j])
		{
			temp[k++] = input[i++];
		}
		else
		{
			temp[k++] = input[j++];
		}
	}

	// 왼쪽이 남았을 경우
	while (i <= half)
	{
		// 남은 수 모두 병합
		temp[k++] = input[i++];
	}

	// 오른쪽이 남았을 경우
	while (j <= end)
	{
		// 남은 수 모두 병합
		temp[k++] = input[j++];
	}

	// 원본 배열에 복사
	k = 0;
	for (int i = start; i <= end; ++i)
	{
		input[i] = temp[k++];
	}
}

void MergeSort(int input[], int start, int end, int temp[])
{
	// base case
	if (start >= end)
	{
		return;
	}

	// recursive case
	int half{ (start + end) / 2 };
	MergeSort(input, start, half, temp);
	MergeSort(input, half + 1, end, temp);

	Merge(input, start, half, end, temp);
}


int main()
{
	const int ARRAY_SIZE{ 5 };
	int array[ARRAY_SIZE]{ 8, 7, 2, 3, 1 };

	// SquentialSort(array, ARRAY_SIZE);
	// SelectionSort(array, ARRAY_SIZE);
	// BubbleSort(array, ARRAY_SIZE);
	// InsertionSort(array, ARRAY_SIZE);

	int temp[ARRAY_SIZE];
	MergeSort(array, 0, ARRAY_SIZE - 1, temp);

	// 정렬
	PrintArray(array, ARRAY_SIZE);
}