#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	std::ifstream	inputfile;
	std::string		inputline;
	std::string		first_half;
	std::string		second_half;
	int				sum;

	sum = 0;
	inputfile.open("file.txt");

	while (std::getline(inputfile, inputline))
	{	
		unsigned char used[255];
		for (int i = 0; i < 255; i++)
			used[i] = 0;
		
		first_half = inputline.substr(0, (inputline.length() / 2));
		second_half = inputline.substr((inputline.length() / 2), inputline.length() - 1);

		for (int i = 0; i < first_half.size(); i++)
		{
			used[static_cast<unsigned char>(first_half[i])] = 1;
		}

		for (int i = 0; i < second_half.size(); i++)
		{
			if (used[static_cast<unsigned char>(second_half[i])] == 1)
				used[static_cast<unsigned char>(second_half[i])] = 2;
		}
		for (int i = 0; i < 255; i++)
		{
			if (used[i] == 2)
			{
				if (i >= 97 && i <= 122)
					sum += (i - 96);
				else if (i >= 65 && i <= 90)
					sum += ((i - 64) + 26);
				std::cout << "unique char = " << static_cast<char>(i) << std::endl;
			}
		}
		// std::cout << "first half = " << first_half << std::endl; 
		// std::cout << "second half = " << second_half << std::endl; 

	}
	std::cout << "the total score = " << sum << std::endl;
	return (0);
}