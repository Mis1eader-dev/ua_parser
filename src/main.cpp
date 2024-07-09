#include "ua_parser/ua_parser.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	--argc;
	++argv;
	if(argc < 1)
	{
		std::cerr << "At least 1 argument is required\n";
		return 0;
	}
	for(char** arg = argv, **argEnd = argv + argc; arg != argEnd; ++arg)
	{
		auto deviceInfo = ua_parser::parseInfo(*arg);
		std::cout << '\n' << *arg << " => " << (unsigned int)deviceInfo.type << " (Is Mobile: " << (deviceInfo.isMobile ? "Yes" : "No") << ")\n";
	}
}
