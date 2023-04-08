#include <string>
#include <string_view>

namespace ua_parser
{
	enum Info : uint8_t
	{
		DEVICE_UNKNOWN,
		DEVICE_WINDOWS,
		DEVICE_MAC_OS,
		DEVICE_LINUX,
		DEVICE_CHROME_OS,
		DEVICE_ANDROID,
		DEVICE_IPHONE,
		DEVICE_IPAD,
		DEVICE_IPOD,
		DEVICE_WINDOWS_PHONE,
		MOBILE = 1 << 5,
	};

	uint8_t parse(std::string_view s);
}
