#include <iostream>
#include <string>
#include <vector>

using STD_STR = std::string;
using VEC_STR = std::vector<std::string>;

int main(void)
{
	VEC_STR words;
	STD_STR word;
	auto len = words.size();
	while (std::cin >> word)
	{
		if (!word.empty())
		{
			words.push_back(word);
		}
		else 
		{
			break;
		}
	}

	for(auto &word : words)
	{
		for(auto it = word.begin(); it != word.end() && (!isspace(*it)); it++)	
			*it = toupper(*it);
		std::cout << word << std::endl;
	}
	
	return 0;
}