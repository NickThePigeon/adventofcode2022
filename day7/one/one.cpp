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
#include <map>




int	main(void)
{
	std::ifstream				inputfile;
	std::string					inputline;
	std::map<std::string, long long>	dirs;
	std::vector<std::string> 	opendirs;
	std::string 				current_dir;
	std::string					line;
	std::vector<std::string>	total_file;
	long long					sum;
	long long					total_sum;

	int dir_count = 0;
	sum = 0;
	inputfile.open("file.txt");

	while (std::getline(inputfile, inputline))
		total_file.push_back(inputline);

	for (auto it = total_file.begin(); it != total_file.end(); ++it)
	{
		if (*it == "$ ls")
			continue;

		line = *it;
		bool	go_inside = line.find("$ cd") != std::string::npos;
		bool	go_back = line.find("$ cd ..") != std::string::npos;
		if (go_inside && !go_back)
		{
			dir_count++;
			opendirs.push_back(line);
			dirs.insert({line, 0});
		}
		if (go_back)
			opendirs.pop_back();
		sum = atoll(line.c_str());
		if (sum > 0)
		{
			for (auto iter = opendirs.begin(); iter != opendirs.end(); ++iter)
			{
				std::map<std::string, long long>::iterator it = dirs.find(*iter); 
				if (it != dirs.end())
					it->second += sum;
			}
		}
		sum = 0;
	}

	total_sum = 0;
	for (auto it = dirs.cbegin(); it != dirs.cend(); ++it) {
        std::cout << "{" << (*it).first << ": " << (*it).second << "}\n";
		if ((*it).second <= 100000)
			total_sum += (*it).second;
    }
	std::cout << "the total sum = " << total_sum << std::endl;
	std::cout << "dir count = " << dir_count << std::endl;
	inputfile.close();
	return (0);
}