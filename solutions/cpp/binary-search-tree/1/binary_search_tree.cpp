#include "binary_search_tree.h"

namespace binary_search_tree {

template<typename T>
binary_tree<T>::binary_tree(const T& val): _val(val) {}

template<typename T>
T binary_tree<T>::data(void) const {
	return _val;
}

template<typename T>
const std::unique_ptr<binary_tree<T>>& binary_tree<T>::left(void) const {
	return _left;
}

template<typename T>
const std::unique_ptr<binary_tree<T>>& binary_tree<T>::right(void) const {
	return _right;
}

template<typename T>
void binary_tree<T>::insert(const T& val){
	if (val <= _val){
		if (_left) _left->insert(val);
		else _left = std::make_unique<binary_tree<T>>(val);
	}
	else{
		if (_right) _right->insert(val);
		else _right = std::make_unique<binary_tree<T>>(val);
	}
}

}  // namespace binary_search_tree
