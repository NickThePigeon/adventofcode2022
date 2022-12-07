#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string.h>

bool compare_set_chars(std::string &set)
{
	for (int i = 0; i < set.size(); i++)
	{
		for (int j = 0; j < set.size(); j++)
		{
			if (set[i] == set[j] && i != j)
				return (false);
		}
	}
	return (true);
}

int	main(void)
{
	std::ifstream	inputfile;
	std::string		inputline;
	int				sum;

	sum = 0;
	inputfile.open("file.txt");

	while (std::getline(inputfile, inputline))
	{
		std::string set;
		for (int i = 14; i < inputline.size(); i++)
		{
			set = inputline.substr(i - 14, 14);
			if (compare_set_chars(set))
			{
				sum = i;
				std::cout << "first packet start at index " << sum << std::endl;
				break;
			}
			set.clear();
		}
	}
	inputfile.close();
	return (0);
}