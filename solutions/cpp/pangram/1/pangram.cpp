#include "pangram.h"

#include <array>

namespace pangram {

bool is_pangram(std::string sentence){
	std::array<bool, 26> checked;
	std::fill(checked.begin(), checked.end(), false);
	size_t n = 0;
	for (auto c: sentence){
		if (std::isalpha(c)){
			size_t idx = std::tolower(c) - 'a';
			if (!checked[idx]){
				checked[idx] = true;
				n++;
			}
		}
	}
	return n == 26;
}

}  // namespace pangram
