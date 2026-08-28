#include <iostream>
#include <functional>

void InsertionSort(int* array, int length, std::function<bool(int, int)> comparer = std::less<int>())
{
	if (length <= 1)
		return;

	for (int i = 1; i < length; i++)
	{
		int keyValue = array[i];
		int j = i - 1;

		while (j >= 0 && comparer(array[j], keyValue))
		{
			array[j + 1] = array[j];
			--j;
		}

		array[j + 1] = keyValue;
	}
}


void PrintArray(int* array, const int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i];
		if (i < length - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "\n";
}

int main()
{
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	//const int length = sizeof(array) / sizeof(array[0]);
	const int length = _countof(array);

	std::cout << "정렬 전 \n";
	PrintArray(array, length);

	InsertionSort(array, length, 
		[](int a, int b)
		{
			return a > b;
		}
	);

	std::cout << "정렬 후 \n";
	PrintArray(array, length);
}