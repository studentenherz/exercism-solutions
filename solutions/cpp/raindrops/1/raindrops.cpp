#include "raindrops.h"

namespace raindrops {

std::string convert(int number) {
	std::string ans;
	if (number % 3 == 0)
		ans += "Pling";
	if (number % 5 == 0)
		ans += "Plang";
	if (number % 7 == 0)
		ans += "Plong";
	return ans.size() ? ans : std::to_string(number);
}

}  // namespace raindrops
