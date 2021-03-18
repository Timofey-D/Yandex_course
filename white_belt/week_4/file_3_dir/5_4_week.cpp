#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void readFromFile(std::string filename);

int main(void)
{
/*
	std::string filename;
	std::cin >> filename;
	filename += ".txt";
*/
	readFromFile("input.txt");

	return 0;
}


void readFromFile(std::string filename)
{
	std::fstream file(filename);

	if (file.is_open())
	{
		int N = 0;
		int M = 0;
		
		file >> N;
		file >> M;

		int save_m = M;

		for (int line = 0; line < N; line++)
		{
			std::cout << std::right << std::setw(10);
			for (int column = 0, number = 0; column < M && file >> number; column++)
			{
				file.ignore(1);
				std::cout << std::setw(10) << number;
				if (column != (M - 1))
				{
					std::cout << " ";
				}	
			}
			if (line != N - 1)
			{
				std::cout << std::endl;
			}
		}		
	}
}
