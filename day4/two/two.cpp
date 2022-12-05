#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string.h>

struct valuepair
{
	int	first_num;
	int second_num;
};


int	compare(valuepair &first, valuepair &second) {
	if (first.first_num >= second.first_num && first.first_num <= second.second_num)
		return (1);
	else if (first.second_num >= second.first_num && first.second_num <= second.second_num)
		return (1);
	else if (second.first_num >= first.first_num && second.first_num <= first.second_num)
		return (1);
	else if (second.second_num >= first.first_num && second.second_num <= first.second_num)
		return (1);
	return (0);
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
		valuepair first_pair;
		valuepair second_pair;
		std::string		temp_line;

		first_pair.first_num = atoi(inputline.c_str());
		temp_line = inputline.substr((inputline.find('-') + 1));
		first_pair.second_num = atoi(temp_line.c_str());
		temp_line = inputline.substr((inputline.find(',') + 1));
		second_pair.first_num = atoi(temp_line.c_str());
		temp_line = inputline.substr((inputline.rfind('-') + 1));
		second_pair.second_num = atoi(temp_line.c_str());

		sum += compare(first_pair, second_pair);
		// std::cout << "first pair.first_num = " << first_pair.first_num << std::endl;
		// std::cout << "first pair.second_num = " << first_pair.second_num << std::endl;
		// std::cout << "second pair.first_num = " << second_pair.first_num << std::endl;
		// std::cout << "second pair.second_num = " << second_pair.second_num << std::endl;

		// temp_line = strchr(inputline.c_str(), "-");
	}
	std::cout << "the total score = " << sum << std::endl;
	inputfile.close();
	return (0);
}