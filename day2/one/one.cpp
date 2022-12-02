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
	int				sum;

	sum = 0;
	inputfile.open("file.txt");

	/* A = rock
	   B = paper
	   C = Scissor
	   X = rock 1
	   Y = paper 2
	   Z = Scissor 3 */

	while (std::getline(inputfile, inputline))
	{	
		if ("A Y" == inputline)
			sum += 8;
		else if ("A X" == inputline)
			sum += 4;
		else if ("A Z" == inputline)
			sum += 3;	
		else if ("B Y" == inputline)
			sum += 5;	
		else if ("B X" == inputline)
			sum += 1;	
		else if ("B Z" == inputline)
			sum += 9;	
		else if ("C Y" == inputline)
			sum += 2;	
		else if ("C X" == inputline)
			sum += 7;	
		else if ("C Z" == inputline)
			sum += 6;
	}
	std::cout << "the total score = " << sum << std::endl;
	return (0);
}