#include <iostream>
#include <fstream>
#include <vector>

void writeToFile(std::string file_target, std::string file_source);

int main(void)
{
	
	writeToFile("output.txt", "input.txt");	

	return 0;
}


void writeToFile(std::string file_target, std::string file_source)
{
        std::vector<std::string> lines;

        std::ifstream s_file(file_source);
        std::ofstream t_file(file_target);

        if (s_file.is_open())
        {
                std::string line;
                while (getline(s_file, line))
                {
                        lines.push_back(line);
                }
        }

        for (int i = 0; i < lines.size(); i++)
        {
                t_file << lines[i] << std::endl;
        }
}

