// »ðÀÔ Á¤·Ä (Insertion Sort)
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