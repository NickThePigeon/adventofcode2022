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
		from--;
		to--;
		for (int i = 0; i < to_move; i++)
			map[to].push_back(map[from][(map[from].size()) - (to_move - i)]);
		for (int i = 0; i < to_move; i++)
			map[from].pop_back();
	}
	std::cout << "the answer = ";
	for (int i = 0; i < map.size(); i++)
		std::cout << map[i].back();
	std::cout << std::endl;
	inputfile.close();
	return (0);
}