#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string.h>

typedef std::vector<std::vector<int>>::iterator map_iter;
typedef std::vector<int>::iterator inmap_iter;

int		count_trees(std::vector<std::vector<int>> map)
{
	int visible_trees;

	visible_trees = map.size() * 2;
	visible_trees += (map[0].size() * 2) - 4;

	for (int y = 1; y < map.size() - 1; y++)
	{
		for (int x = 1; x < map[y].size() - 1; x++)
		{
			if (map[y][x] > map[y][x + 1])
				visible_trees++;
			else if (map[y][x] > map[y][x - 1])
				visible_trees++;
			else if (map[y][x] > map[y - 1][x])
				visible_trees++;
			else if (map[y][x] > map[y + 1][x])
				visible_trees++;
		}
	}
	return (visible_trees);
}

void	print_map(std::vector<std::vector<int>> map)
{
	for (int i = 0; i < map.size(); ++i)
	{
		for (inmap_iter it = map[i].begin(); it != map[i].end(); ++it)
		{
			std::cout << *it;
		}
		std::cout << std::endl;
	}
}
	

int	main(void)
{
	std::ifstream	inputfile;
	std::string		inputline;
	std::vector<std::vector<int>> map;
	std::vector<int>			temp_holder;
	int				trees;

	inputfile.open("example.txt");

	int k = 0;
	while (std::getline(inputfile, inputline))
	{
		for (int i = 1; i < inputline.size(); i++)
			temp_holder.push_back(inputline[i] - '0');
		map.push_back(temp_holder);
		temp_holder.clear();
	}
	print_map(map);
	trees = count_trees(map);
	std::cout << "there are " << trees << " visible trees" << std::endl;
	inputfile.close();
	return (0);
}