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

int	main(void)
{
	std::ifstream	inputfile;
	std::string		inputline;
	int				sum;

	sum = 0;
	inputfile.open("file2.txt");

/* 	std::vector<std::vector<std::string>>	map = {
		{"[Z]","[N]"},
		{"[M]","[C]","[D]"},
		{"[P]"}
	}; */

	std::vector<std::vector<std::string>>	map = {
		{"[S]","[C]","[V]","[N]"},
		{"[Z]","[M]","[J]","[H]","[N]","[S]"},
		{"[M]","[C]","[T]","[G]","[J]","[N]","[D]"},
		{"[T]","[D]","[F]","[J]","[W]","[R]","[M]"},
		{"[P]","[F]","[H]"},
		{"[C]","[T]","[Z]","[H]","[J]",},
		{"[D]","[P]","[R]","[Q]","[F]","[S]","[L]","[Z]",},
		{"[C]","[S]","[L]","[H]","[D]","[F]","[P]","[W]",},
		{"[D]","[S]","[M]","[P]","[F]","[N]","[G]","[Z]",}
	};

	while (std::getline(inputfile, inputline))
	{
		std::istringstream iss(inputline.c_str());
		std::string placeholder;
		int	to_move,from,to;
		iss >> placeholder >> to_move >> placeholder >> from >> placeholder >> to;
		for (int i = 0; i < to_move; i++)
		{
			map[to - 1].push_back(map[from - 1].back());
			map[from - 1].pop_back();
		}
		// std::cout << "to move = " << to_move << " from = " << from << " to = " << to << std::endl;
	}
	std::cout << "the total score = " << std::endl;
	for (int i = 0; i < map.size(); i++)
		std::cout << map[i].back();
	std::cout << std::endl;
	inputfile.close();
	return (0);
}