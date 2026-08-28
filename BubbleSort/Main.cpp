#include <iostream>
#include <functional>

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//using Comparer = bool (*)(int, int);
typedef bool (*Comparer)(int, int);

bool Less(int a, int b)
{
	return a < b;
}

bool Greater(int a, int b)
{
	return a > b;
}

//void BubbleSort(int* array, const int length, Comparer comparer = Greater)
void BubbleSort(int* array, const int length, std::function<bool(int, int)> comparer = Greater)
{
	if (length <= 1)
		return;

	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (comparer(array[j], array[j + 1]))
			{
				Swap(array[j], array[j + 1]);
			}
		}
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

	//BubbleSort(array, length, Greater);
	//BubbleSort(array, length, 
	//	[](int a, int b) -> bool
	//	{
	//		return a > b;
	//	}
	//);

	std::cout << "정렬 후 \n";
	PrintArray(array, length);
}