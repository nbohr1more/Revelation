//
//  curl_version.h
//  curlcpp
//
//  Created by Giuseppe Persico on 30/03/14.
//

#ifndef __curlcpp__curl_version__
#define __curlcpp__curl_version__

#include <curl/curl.h>
#include <string>
#include <list>

#ifndef _MSC_VER
#define NOEXCEPT noexcept
#else
#define NOEXCEPT throw()
#endif

using std::string;
using std::list;

// Curl vesion wrapper. You can use this class to obtain information about curl library
namespace curl {
class curl_info {
public:
	curl_info();
	curl_info( const CURLversion );
	const string get_host() const NOEXCEPT;
	const string get_ssl_version() const NOEXCEPT;
	const string get_libz_version() const NOEXCEPT;
	const string get_ares() const NOEXCEPT;
	const string get_libidn() const NOEXCEPT;
	const string get_libssh_version() const NOEXCEPT;
	const unsigned int get_version_number() const NOEXCEPT;
	const int get_features() const NOEXCEPT;
	const int get_ares_number() const NOEXCEPT;
	const int get_iconv_version_number() const NOEXCEPT;
	const long get_ssl_version_number() const NOEXCEPT;
	const list<string> get_protocols() const NOEXCEPT;
private:
	const curl_version_info_data *version;
};
}

#endif /* defined(__curlcpp__curl_version__) */