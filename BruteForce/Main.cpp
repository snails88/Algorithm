#include <iostream>
#include <cstring>

int StringLength(const char* string)
{
	int count = 0;

	while (string[count] != '\0')
	{
		++count;
	}

	return count;
}

int FindPatternIndex(const char* text, const char* pattern)
{
	const int textLength = static_cast<int>(strlen(text));
	const int testLength = StringLength(text);
	const int patternLength = static_cast<int>(strlen(pattern));

	for (int i = 0; i <= textLength - patternLength; i++)
	{
		int patternIndex = 0;

		while (patternIndex < patternLength && text[i + patternIndex] == pattern[patternIndex])
		{
			++patternIndex;
		}
		if (patternIndex == patternLength)
			return i;
	}

	return -1;
}

int FindMaxValue(const int* array, const int length)
{
	int maxValue = array[0];

	for (int i = 1; i < length; i++)
	{
		if (array[i] > maxValue)
			maxValue = array[i];
	}

	return maxValue;
}

int FindValueIndex(const int array[], const int length, const int target)
{
	for (int i = 0; i < length; i++)
	{
		if (array[i] == target) 
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	const int array[] = { 1,3,5,7,9,11,13,15 };
	const int length = sizeof(array) / sizeof(array[0]);
	const int target = 11;

	int result = FindValueIndex(array, length, target);

	if (result != -1)
	{
		std::cout << "검색성공. 인덱스 : " << result << "\n";
	}
	else
		std::cout << "검색 실패.\n";

	int maxValue = FindMaxValue(array, length);

	std::cout << "최댓값 : " << maxValue << "\n";

	int resultIndex = FindPatternIndex("원선재초천재", "초천재");
}