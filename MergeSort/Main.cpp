#include <iostream>
#include <ctime>
#include <Windows.h>

class StatTimer
{
public:
	StatTimer(const std::string& tag)
		: tag(tag)
	{
	}

	void CheckStartStat()
	{
		LARGE_INTEGER counter;
		QueryPerformanceCounter(&counter);
		start = counter.QuadPart;
	}

	void CheckEndStat()
	{
		LARGE_INTEGER counter;
		QueryPerformanceCounter(&counter);
		end = counter.QuadPart;
	}

	void Reset()
	{
		start = end = 0;
	}

	void PrintResult()
	{
		std::cout << "[" << tag << "] elapsed: " << GetElapsed() << "\n";
	}

private:
	float GetElapsed()
	{
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);
		return static_cast<float>(end - start)
			/ static_cast<float>(frequency.QuadPart);
	}

private:
	std::string tag;
	int64_t start = 0;
	int64_t end = 0;
};

typedef bool (*Comparer)(int, int);

bool LessEqual(int a, int b) { return a <= b; }
bool GreaterEqual(int a, int b) { return a >= b; }

void Merge(int* array, int* leftArray, int leftArrayLength, int* rightArray, int rightArrayLength, Comparer comparer = LessEqual)
{
	int leftIndex = 0;
	int rightIndex = 0;
	int mergedIndex = 0;

	while (leftIndex < leftArrayLength && rightIndex < rightArrayLength)
	{
		if (comparer(leftArray[leftIndex], rightArray[rightIndex]))
			array[mergedIndex++] = leftArray[leftIndex++];
		else
			array[mergedIndex++] = rightArray[rightIndex++];
	}

	if (leftIndex < leftArrayLength)
		memcpy(array + mergedIndex, leftArray + leftIndex, sizeof(int) * (leftArrayLength - leftIndex));

	if (rightIndex < rightArrayLength)
		memcpy(array + mergedIndex, rightArray + rightIndex, sizeof(int) * (rightArrayLength - rightIndex));
}

void MergeSort(int* array, int length, Comparer comparer = LessEqual)
{
	if (length <= 1)
		return;

	int middle = length / 2;
	int leftArrayLength = middle;
	int rightArrayLength = length - middle;
	int* leftArray = new int[leftArrayLength] {};
	int* rightArray = new int[rightArrayLength] {};

	memcpy(leftArray, array, sizeof(int) * leftArrayLength);
	memcpy(rightArray, array + leftArrayLength, sizeof(int) * rightArrayLength);

	MergeSort(leftArray, leftArrayLength, comparer);
	MergeSort(rightArray, rightArrayLength, comparer);

	Merge(array, leftArray, leftArrayLength, rightArray, rightArrayLength, comparer);

	delete[] leftArray;
	leftArray = nullptr;
	delete[] rightArray;
	rightArray = nullptr;
}

void Srand()
{
	srand(static_cast<uint32_t>(time(nullptr)));
}

int RandomRange(int min, int max)
{
	int diff = (max - min) + 1;
	return ((diff * rand()) / (RAND_MAX + 1)) + min;
}

int main()
{
	const int length = 30000;

	int* original = new int[length] {};

	for (int i = 0; i < length; i++)
	{
		original[i] = RandomRange(1, length);
	}

	int* array = new int[length];

	memcpy(array, original, sizeof(int) * length);

	auto printArray =
		[](int* array, int length)
		{
			for (int i = 0; i < length; i++)
			{
				std::cout << array[i];
				if (i < length - 1)
					std::cout << ", ";
			}
			std::cout << "\n";
		};
	
	//std::cout << "정렬 전\n";
	//printArray(array, length);

	StatTimer mergeSortTimer("MergeSort");
	mergeSortTimer.CheckStartStat();
	
	MergeSort(array, length);
	
	mergeSortTimer.CheckEndStat();
	mergeSortTimer.PrintResult();

	//std::cout << "정렬 후\n";
	//printArray(array, length);

	delete[] original;
	original = nullptr;
	delete[] array;
	array = nullptr;
}