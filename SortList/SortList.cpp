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

// ���� ���� (Squential Sort)
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

// ��ǰ ����(Bubble Sort)
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

// ���� ���� (Insertion Sort)
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

// ���� ����(Merge Sort)
void Merge(int input[], int start, int half, int end, int temp[])
{
	int i{ start };
	int j{ half + 1 };
	int k{};

	// while : ���Ұ� ���� ��
	while (i <= half && j <= end)
	{
		// �� ���� ������
		// ���� �� ����, ū �� ������
		if (input[i] < input[j])
		{
			temp[k++] = input[i++];
		}
		else
		{
			temp[k++] = input[j++];
		}
	}

	// ������ ������ ���
	while (i <= half)
	{
		// ���� �� ��� ����
		temp[k++] = input[i++];
	}

	// �������� ������ ���
	while (j <= end)
	{
		// ���� �� ��� ����
		temp[k++] = input[j++];
	}

	// ���� �迭�� ����
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

	// ����
	PrintArray(array, ARRAY_SIZE);
}