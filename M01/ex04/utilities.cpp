#include "utilities.hpp"

/**
 * @brief this function will replace all the "s1" occurances in the string "str"
 * with the string "s2"
 * @param str original string
 * @param s1 substring need to be compared with
 * @param s2 string need to be susbtituted
 * @return std::string will return the updated string, or will return "str" in the
 * event "str" is an empty string
*/
std::string replaceAll(const std::string str, const std::string s1, const std::string s2) {

	std::string result;
	size_t		i = 0;

	if(str.empty())
		return (str);
	while(i < str.size()) {
		if (str.compare(i, s1.size(), s1) == 0) {
			result += s2;
			i += s1.size();
		} else {
			result += str[i];
			i++;
		}
	}
	return (result);
}
