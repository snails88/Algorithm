#include <iostream>

int Power(int x, int y)
{
	if (y == 0)
		return 1;

	return x * Power(x, y - 1);
}

int Sum(int number)
{
	if (number == 1)
		return 1;

	return number + Sum(number - 1);
}

int main()
{
	int power = Power(2, 8);

	const int target = 5;
	int result = Sum(target);

	std::cout << "결과: " << result << "\n"; 
}