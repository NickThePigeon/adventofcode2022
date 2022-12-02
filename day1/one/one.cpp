#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdlib.h>

int	main(void)
{
	std::ifstream	inputfile;
	std::string		inputline;
	std::list<int>  mylist;
	int				sum;

	sum = 0;
	inputfile.open("file.txt");
	while (std::getline(inputfile, inputline))
	{	
		if (inputline.length() == 0)
		{
			mylist.push_back(sum);
			sum = 0;
			continue;
		}
		sum += std::atoi(inputline.c_str());
	}
	mylist.push_back(sum);
	auto total = std::max_element(mylist.begin(), mylist.end());
	std::cout << "the max sum = " << *total << std::endl;
	return (0);
}