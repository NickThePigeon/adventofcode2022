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

std::string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}

typedef std::map<std::string, int>::iterator dirs_iter;
typedef std::vector<std::string>::const_iterator opendirs_iter;

int	main(void)
{
	std::ifstream	inputfile;
	std::string		inputline;
	int				sum;
	std::vector<std::string> opendirs;
	std::map<std::string, int>	dirs;

	sum = 0;
	inputfile.open("file.txt");

	while (std::getline(inputfile, inputline))
	{
		bool go_dir = inputline.find("$ cd") != std::string::npos;
		bool go_back = inputline. find("$ cd ..") != std::string::npos;

		if (inputline == "$ cd /")
			opendirs.push_back(inputline);
		if (go_back)
			opendirs.pop_back();
		else if (go_dir)
			opendirs.push_back(gen_random(3) + inputline);
		else if (isdigit(inputline[0]))
		{
			sum = atoi(inputline.c_str());
			for (opendirs_iter it = opendirs.cbegin(); it != opendirs.cend(); ++it)
			{
				dirs[*it] += sum;
			}
			sum = 0;
		}
	}
	int totalsum1 = 0;
	int totalsum2 = INT_MAX;
	int max_value = dirs.at("$ cd /");
	for (dirs_iter it = dirs.begin(); it != dirs.end(); ++it)
	{
		std::cout << "{" <<(*it).first << "}, : " << (*it).second << std::endl;
		if ((*it).second <= 100000)
			totalsum1 += (*it).second;
		if (((70000000 - max_value) + (*it).second) >= 30000000 && (*it).second < totalsum2)
			totalsum2 = (*it).second;
	}

	std::cout << "part 1: the totalsum = " << totalsum1 << std::endl;
	std::cout << "part 2: the totalsum = " << totalsum2 << std::endl;
	inputfile.close();
	return (0);
}