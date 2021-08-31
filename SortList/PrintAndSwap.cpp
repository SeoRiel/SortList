#include <iostream>
#include "SortHeader.h"

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