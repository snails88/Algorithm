#include <iostream>

int BinarySearchRecursive(const int* array, const int target, int start, int end)
{
	if (start > end)
	{
		return -1;
	}

	int middle = (start + end) / 2;

	if(array[middle] == target)
		return middle;

	if (array[middle] > target)
	{
		return BinarySearchRecursive(array, target, start, middle - 1);
	}
	else
	{
		return BinarySearchRecursive(array, target, middle + 1, end);	// 위에서 안걸렸으면
	}
	return -1;
}

int BinarySearchIterative(const int* array, const int  length, const int target)
{
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		int middle = (start + end) / 2;
		if (array[middle] == target)
			return middle;

		if (array[middle] > target)
		{
			end = middle - 1;
		}
		else
		{
			start = middle + 1;
		}
	}

	return -1;
}

int main()
{
	const int array[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	const int length = sizeof(array) / sizeof(array[0]);

	const int target = 10;
	int result = BinarySearchRecursive(array, target, 0, length);

	if (result != -1)
		std::cout << "검색 성공. 인덱스 : " << result << "\n";
	else
		std::cout << "검색 실패\n";
}