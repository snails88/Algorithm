#include <iostream>

using Comparer = bool (*)(int, int);

bool Less(int a, int b) { return a < b; }

template<typename T>
struct Greater
{
	bool operator()(T& a, T& b) { return a > b; }
};

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SelectionSort(int* array, const int length, Comparer comparer = Less)
{
	if (length < 1)
		return;

	for (int i = 0; i < length - 1; i++)
	{
		int valueIndex = i;

		for (int j = i + 1; j < length; j++)
		{
			if (comparer(array[valueIndex], array[j]))
			{
				valueIndex = j;
			}
		}

		if (valueIndex != i)
			Swap(array[i], array[valueIndex]);
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

	//Greater<int> greater;
	SelectionSort(array, length, 
		[](int a, int b)
		{
			return a > b;
		});

	std::cout << "정렬 후 \n";
	PrintArray(array, length);
}