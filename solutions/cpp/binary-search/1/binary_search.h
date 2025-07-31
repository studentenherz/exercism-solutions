#if !defined(BINARY_SEARCH_H)
#define BINARY_SEARCH_H

#include <vector>
#include <stdexcept>

namespace binary_search {

template<typename T>
std::size_t find(const std::vector<T>& data, const T& value){
		if (data.size()){
			auto left = data.begin();
			auto right = data.end();
			while (left <= right){
					auto it = left + (right - left) / 2;
					if (*it == value) { return it - data.begin();}
					if (*it > value){ right = it - 1; }
					else { left = it + 1; }
			}
		}
    throw std::domain_error("404");
}

}  // namespace binary_search

#endif // BINARY_SEARCH_H