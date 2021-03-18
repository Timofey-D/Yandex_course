
#include <iostream>
#include <fstream>
#include <iomanip>

void readFile(std::string filename);

int main(void)
{
	readFile("input.txt");

	return 0;
}


void readFile(std::string filename)
{
	std::ifstream r_file(filename);

	if (r_file.is_open())
	{
		double number = 0;
		std::cout << std::fixed << std::setprecision(3);
		while (r_file >> number)
		{
			std::cout << number << std::endl;
		}
	}
}
