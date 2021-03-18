#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void readFromFile(std::string filename);

int main(void)
{

	readFromFile("input.txt");

	return 0;
}


void readFromFile(std::string filename)
{
	std::ifstream file(filename);
	
	if (file.is_open())
	{
		std::string line;
		while (getline(file, line))
		{
			std::cout << line << std::endl;
		}
	}
}
