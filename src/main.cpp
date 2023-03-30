#include <iostream>
#include "ua_parser.hpp"

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		std::cerr << "At least 1 argument is required\n";
		return 0;
	}
	for(char** arg = argv + 1, **argEnd = argv + argc; arg != argEnd; ++arg)
	{
		std::cout << '\n' << *arg << " => " << (unsigned int)ua_parser::parse(*arg) << '\n';
	}
}
