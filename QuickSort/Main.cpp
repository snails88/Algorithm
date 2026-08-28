#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <algorithm>

typedef bool (*Comparer)(int, int);

bool LessEqual(int a, int b) { return a <= b; }
bool GreaterEqual(int a, int b) { return a >= b; }

int RandomRange(int min, int max)
{
	int diff = (max - min) + 1;
	return ((diff * rand()) / (RAND_MAX + 1)) + min;
}

void PrintArray(const int* array, int length)
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

int Partition(int* array, int left, int right, Comparer comparer = LessEqual)
{
	int pivot = array[left];
	int low = left + 1;	// 왼쪽에서 오른쪽으로 이동. 피벗보다 큰값 찾음
	int high = right;	// 오른쪽에서 왼쪽. 피벗보다 작은값 찾음

	while (low <= high)
	{
		while (low <= right && comparer(array[low], pivot))
		{
			++low;
		}

		while (high > left && comparer(pivot, array[high]))
		{
			--high;
		}

		if (low > high)
			break;

		std::swap<int>(array[low], array[high]);
	}

	std::swap<int>(array[left], array[high]);

	return high;
}

void QuickSort(int* array, int left, int right, Comparer comparer = LessEqual)
{
	if (left >= right)
		return;

	int pivotIndex = Partition(array, left, right, comparer);

	QuickSort(array, left, pivotIndex - 1, comparer);
	QuickSort(array, pivotIndex + 1, right, comparer);
}

int64_t GetTime()
{
	LARGE_INTEGER counter;
	QueryPerformanceCounter(&counter);

	return counter.QuadPart;
}

float GetElapsedTime(int64_t start, int64_t end)
{
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	return static_cast<float>(end - start) / static_cast<float>(frequency.QuadPart);
}

int main()
{
	srand(static_cast<uint32_t>(time(nullptr)));

	const int length = 1000;

	int original[length] = {};

	for (int i = 0; i < length; i++)
	{
		int value = RandomRange(1, length);
		original[i] = value;
	}

	int array[length] = {};
	memcpy(array, original, sizeof(int) * length);

	//std::cout << "정렬 전 배열\n";
	//PrintArray(array, length);

	int64_t start = GetTime();

	QuickSort(array, 0, length - 1, GreaterEqual);

	int64_t end = GetTime();

	float elapsed = GetElapsedTime(start, end);

	std::cout << "ElapsedTime: " << elapsed << "\n\n";

	//std::cout << "\n정렬 후 배열\n";
	//PrintArray(array, length);
}