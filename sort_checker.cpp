#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <array>
#include <random>
#include "file_buffer.h"
#include <algorithm>

using namespace std;

int main(int argc, char**argv)
{
	const uint32_t BufferSize = 10 * 1024 * 1024;
	FileBuffer<int32_t> buffer(BufferSize);
	
	//buffer.Open("C:\\dev\\bitbucket\\sorting_problem\\Win32Project1\\Debug\\test.txt");
	buffer.Open("F:\\dev\\bitbucket\\sorting_problem\\external_sort\\Debug\\temp\\tempfile8.data");
	size_t bytesRead = buffer.Read();
	
	std::for_each(buffer.Begin(), buffer.End(), [](int32_t value) { std::cout << value << " "; });
	std::cout << "Size: " << buffer.Size() << std::endl;

	bool isSorted = true;
	while (bytesRead != 0)
	{
		if (bytesRead < BufferSize)
			buffer.Resize(bytesRead);
		isSorted = std::is_sorted(buffer.Begin(), buffer.End());
		if (!isSorted)
			break;

		bytesRead = buffer.Read();
	}

	std::cout << "File is " << (isSorted ? "sorted" : "not sorted") << std::endl;
}