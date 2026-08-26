#include <iostream>
#include <cstdlib>
#include <ctime>

int RandomRange(int min, int max)
{
	// 나머지 연산을 활용한 방법
	//const int diff = (max - min) + 1;
	//return (rand() % diff) + min;

	const int diff = (max - min) + 1;
	return ((rand() * diff) / (RAND_MAX + 1)) + min;
}

float RandomRange(float min, float max)
{
	float percent = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

	float diff = max - min;
	return (percent * diff) + min;
}


int main()
{
	//RAND_MAX

	int64_t seed = time(nullptr);

	srand(static_cast<uint32_t>(seed));

	for (int i = 0; i < 5; i++)
	{
		//std::cout << "Random Number : " << rand() << "\n";
		std::cout << "Random Number : " << RandomRange(1.f, 20.f) << "\n";
	}
	
}