#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <array>
#include <random>

int GenerateRandom(int a, int b)
{
	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(a, b);
	return uniform_dist(e1);
}


int main(int argc, char**argv)
{
	const int32_t size = 103 * 1024 * 1024;
	const std::string inputFilePath = "F:\\dev\\bitbucket\\sorting_problem\\external_sort\\Debug\\test.txt";
	FILE* fp = std::fopen(inputFilePath.c_str(), "wb");
	if (!fp) {
		std::perror("File opening failed");
		return EXIT_FAILURE;
	}

	/*
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<> dis(0, 9);

	std::vector<int> v1(10), v2(10);
	std::generate(v1.begin(), v1.end(), std::bind(dis, std::ref(mt)));
	*/

	std::array<int32_t, size> buffer;
	const int32_t numberOfValues = 103 * 1024 * 1024;
	for (int n = 0; n < numberOfValues; ++n)
	{
		//buffer[n] = GenerateRandom(std::numeric_limits<int32_t>::min(), std::numeric_limits<int32_t>::max());
		buffer[n] = GenerateRandom(0, 100);
		std::cout << buffer[n] << std::endl;
	}

	std::fwrite(buffer.data(), sizeof buffer[0], buffer.size(), fp);
	std::fclose(fp);

	
}