// ���� ����(Merge Sort)
// TC : O(n log n)
// OC : O(n)
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