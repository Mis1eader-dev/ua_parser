#include "ua_parser.hpp"

using namespace ua_parser;

uint8_t ua_parser::parse(std::string_view s)
{
	const auto begin = s.begin(), end = s.end();
	auto it = begin;
	while(it != end)
	{
		if(*it == '(')
		{
			++it;
			break;
		}
		++it;
	}
	s = s.substr(it - begin);
	if(s.size() < 3)return DEVICE_UNKNOWN; // Smallest match is 3 characters
	if(s.starts_with("Linux; Android"))return DEVICE_ANDROID | MOBILE;
	if(s.starts_with("iPhone"))return DEVICE_IPHONE | MOBILE;
	if(s.starts_with("Windows "))
	{
		s = s.substr(8);
		if(s.starts_with("NT"))return DEVICE_WINDOWS;
		if(s.starts_with("Phone"))return DEVICE_WINDOWS_PHONE | MOBILE;
		return DEVICE_UNKNOWN;
	}
	if(s.starts_with("Macintosh"))return DEVICE_MAC_OS;
	if(s.starts_with("X11"))
	{
		s = s.substr(3);
		if(s.starts_with("; CrOS"))return DEVICE_CHROME_OS;
		return DEVICE_LINUX;
	}
	return DEVICE_UNKNOWN;
}
