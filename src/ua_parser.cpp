#include "ua_parser/ua_parser.hpp"

using namespace ua_parser;

uint8_t ua_parser::parse(std::string_view s)
{
	{
		auto findParen = s.find('(');
		if(findParen == s.npos)
			return DEVICE_UNKNOWN;

		s.remove_prefix(findParen + 1);
	}
	if(s.size() < 3)return DEVICE_UNKNOWN; // Smallest match is 3 characters ("X11")
	
	if(s.starts_with("Linux; Android"))return DEVICE_ANDROID | MOBILE;
	else if(s.starts_with("iP"))
	{
		s.remove_prefix(2);
		if(s.starts_with("hone"))return DEVICE_IPHONE | MOBILE;
		if(s.starts_with("ad"))return DEVICE_IPAD | MOBILE;
		if(s.starts_with("od"))return DEVICE_IPOD | MOBILE;
	}
	else if(s.starts_with("Windows "))
	{
		s.remove_prefix(8);
		if(s.starts_with("NT"))return DEVICE_WINDOWS;
		if(s.starts_with("Phone"))return DEVICE_WINDOWS_PHONE | MOBILE;
	}
	else if(s.starts_with("Macintosh"))return DEVICE_MAC_OS;
	else if(s.starts_with("X11"))
	{
		s.remove_prefix(3);
		if(s.starts_with("; CrOS"))return DEVICE_CHROME_OS;
		return DEVICE_LINUX;
	}
	return DEVICE_UNKNOWN;
}
