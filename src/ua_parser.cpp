#include "ua_parser/ua_parser.hpp"
#include <cstdint>
#include <string_view>

// Based on this list: 

// Prefix: "Mozilla/5.0 ("
// Since it could be anything other than Mozilla/5.0,
// we will only look for the part that is common.
static constexpr std::string_view
	prefix = " (";
static constexpr uint8_t
	minPrefixLen = 1, // Must contain at least one character before [prefix]
	minUALen = 3; // Smallest match is 3 characters ("X11")

ua_parser::DeviceInfo ua_parser::parseInfo(std::string_view userAgent)
{
	if(userAgent.size() < (::minPrefixLen + prefix.size() + minUALen))
		return { DEVICE_UNKNOWN };

	{
		auto findParen = userAgent.find(::prefix.back());
		if(findParen == userAgent.npos)
			return { DEVICE_UNKNOWN };

		userAgent.remove_prefix(findParen + 1);
	}

	if(userAgent.size() < ::minUALen)return { DEVICE_UNKNOWN };
	


	/// Detection begins here
	if(userAgent.starts_with("Linux; Android"))return { DEVICE_ANDROID, true };
	else if(userAgent.starts_with("iP"))
	{
		userAgent.remove_prefix(2);
		if(userAgent.starts_with("hone"))return { DEVICE_IPHONE, true };
		if(userAgent.starts_with("ad"))return { DEVICE_IPAD, true };
		if(userAgent.starts_with("od"))return { DEVICE_IPOD, true };
	}
	else if(userAgent.starts_with("Windows "))
	{
		userAgent.remove_prefix(8);
		if(userAgent.starts_with("NT"))return { DEVICE_WINDOWS };
		if(userAgent.starts_with("Phone"))return { DEVICE_WINDOWS_PHONE, true };
	}
	else if(userAgent.starts_with("Macintosh"))return { DEVICE_MAC_OS };
	else if(userAgent.starts_with("X11"))
	{
		userAgent.remove_prefix(3);
		if(userAgent.starts_with("; CrOS"))return { DEVICE_CHROME_OS };
		return { DEVICE_LINUX };
	}
	return { DEVICE_UNKNOWN };
}

ua_parser::DeviceOS ua_parser::parseOS(std::string_view userAgent)
{
	if(userAgent.size() < (::minPrefixLen + prefix.size() + minUALen))
		return { OS_UNKNOWN };

	{
		auto findParen = userAgent.find(::prefix.back());
		if(findParen == userAgent.npos)
			return { OS_UNKNOWN };

		userAgent.remove_prefix(findParen + 1);
	}

	if(userAgent.size() < ::minUALen)return { OS_UNKNOWN };
	


	/// Detection begins here
	if(userAgent.starts_with("Linux; Android"))return { OS_ANDROID, true };
	else if(userAgent.starts_with("iP"))
	{
		userAgent.remove_prefix(2);
		if(userAgent.starts_with("hone"))return { OS_IOS, true };
		if(userAgent.starts_with("ad"))return { OS_IOS, true };
		if(userAgent.starts_with("od"))return { OS_IOS, true };
	}
	else if(userAgent.starts_with("Windows "))
	{
		userAgent.remove_prefix(8);
		if(userAgent.starts_with("NT"))return { OS_WINDOWS };
		if(userAgent.starts_with("Phone"))return { OS_WINDOWS, true };
	}
	else if(userAgent.starts_with("Macintosh"))return { OS_MAC_OS };
	else if(userAgent.starts_with("X11"))
	{
		userAgent.remove_prefix(3);
		if(userAgent.starts_with("; CrOS"))return { OS_CHROME_OS };
		return { OS_LINUX };
	}
	return { OS_UNKNOWN };
}
