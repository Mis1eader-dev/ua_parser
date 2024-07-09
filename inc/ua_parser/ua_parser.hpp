#include <cstdint>
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
	};
	struct DeviceInfo
	{
		Info type;
		bool isMobile = false;
	};
	DeviceInfo parseInfo(std::string_view userAgent);



	enum OS : uint8_t
	{
		OS_UNKNOWN,
		OS_WINDOWS,
		OS_MAC_OS,
		OS_LINUX,
		OS_CHROME_OS,
		OS_ANDROID,
		OS_IOS,
	};
	struct DeviceOS
	{
		OS os;
		bool isMobile = false;
	};
	DeviceOS parseOS(std::string_view userAgent);
}
