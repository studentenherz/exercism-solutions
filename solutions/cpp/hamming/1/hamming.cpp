#include "hamming.h"

#include <stdexcept>

namespace hamming {

size_t compute(std::string strand1, std::string strand2){
	if (strand1.length() != strand2.length()){
		throw std::domain_error("Can't compute hamming distance of sequences of different lengths");
	}
	size_t dist{0};
	for (size_t i = 0; i < strand1.length(); i++){
		if (strand1[i] != strand2[i]){
			dist++;
		}
	}
	return dist;
}

}  // namespace hamming
