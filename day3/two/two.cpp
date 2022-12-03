#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
#include <stdlib.h>

int	main(void)
{
	std::ifstream	inputfile;
	std::string		inputline;
	std::string		first_str;
	std::string		second_str;
	std::string		third_str;
	int				sum;

	sum = 0;
	inputfile.open("file.txt");

	while (std::getline(inputfile, inputline))
	{	
		first_str = inputline;
		std::getline(inputfile, inputline);
		second_str = inputline;
		std::getline(inputfile, inputline);
		third_str = inputline;

		unsigned char used[255];
		for (int i = 0; i < 255; i++)
			used[i] = 0;
	
		for (int i = 0; i < first_str.size(); i++)
		{
			used[static_cast<unsigned char>(first_str[i])] = 1;
		}

		for (int i = 0; i < second_str.size(); i++)
		{
			if (used[static_cast<unsigned char>(second_str[i])] == 1)
				used[static_cast<unsigned char>(second_str[i])] = 2;
		}
		for (int i = 0; i < third_str.size(); i++)
		{
			if (used[static_cast<unsigned char>(third_str[i])] == 2)
				used[static_cast<unsigned char>(third_str[i])] = 3;
		}
		for (int i = 0; i < 255; i++)
		{
			if (used[i] == 3)
			{
				if (i >= 97 && i <= 122)
					sum += (i - 96);
				else if (i >= 65 && i <= 90)
					sum += ((i - 64) + 26);
				// std::cout << "unique char = " << static_cast<char>(i) << std::endl;
			}
		}
		// std::cout << "first half = " << first_half << std::endl; 
		// std::cout << "second half = " << second_half << std::endl; 

	}
	std::cout << "the total score = " << sum << std::endl;
	return (0);
}