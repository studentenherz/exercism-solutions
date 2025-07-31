#include "grains.h"

#include<limits>

namespace grains {

unsigned long long square(unsigned long long index) {
	return 1ULL << (index - 1);
}

unsigned long long total() {
	return (sizeof(unsigned long long) == 8 // since C++11 long long is at least 64 bits wide
		? std::numeric_limits<unsigned long long>::max() // if it's only 64 bits wide the above calculation would overflow
		: (1ULL << 64) - 1 // if it's more than 64 bits wide the above is not what we want but we can compute this without overflow
	);
}

}  // namespace grains
