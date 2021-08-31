// 병합 정렬(Merge Sort)
// TC : O(n log n)
// OC : O(n)
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