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

bool	compare_chars(char a, char b, char c, char d)
{
	return (!(a == b || a == c || a == d || b == c || b == d || c == d));
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
		char a,b,c,d;
		for (int i = 3; i < inputline.size(); i++)
		{
			a = inputline[i];
			b = inputline[i - 1];
			c = inputline[i - 2];
			d = inputline[i - 3];
			if (compare_chars(a, b, c, d))
			{
				sum = i + 1;
				std::cout << "first packet start at index " << sum << std::endl;
				break;
			}
		}
	}
	inputfile.close();
	return (0);
}