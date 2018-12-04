#ifndef BASEREFS_H
#define BASEREFS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <exception>
#include <openssl/md5.h>
//#include <unistd.h>
/*!
 * \brief _get_md5_str
 * \param value source string
 * \return MD5 hash value
 */
static inline std::string _get_md5_str(const std::string& value) {
	uint8_t md5_digest[MD5_DIGEST_LENGTH];
	MD5
	(
		reinterpret_cast<const uint8_t*>(value.c_str()),
		value.length(),
		md5_digest
	);

	char md5_str[MD5_DIGEST_LENGTH*2+1];

	for (int i(0); i < MD5_DIGEST_LENGTH; ++i) {
		sprintf(&md5_str[i*2], "%02x", static_cast<uint16_t>(md5_digest[i]));
	}
	md5_str[sizeof md5_str - 1] = 0;
	return std::string(md5_str);
}

#endif // BASEREFS_H
