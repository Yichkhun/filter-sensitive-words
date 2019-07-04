#ifndef __COMMON__
#define __COMMON__

#include <vector>
#include <string>

namespace msgop
{
	//clear string illegal character
	void string_trim(std::string & aparam_in, std::string & aparam_out);
	//split utf8 character
	void split_utf8(std::string aword, std::vector<std::string>& avec);
};

#endif //__COMMON__
