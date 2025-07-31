#if !defined(BINARY_SEARCH_TREE_H)
#define BINARY_SEARCH_TREE_H

#include <initializer_list>
#include <memory>

namespace binary_search_tree {

template<typename T>
class binary_tree{
	T _val;
	std::unique_ptr<binary_tree<T>> _left = nullptr;
	std::unique_ptr<binary_tree<T>> _right = nullptr;
public:
	binary_tree(const T& val);
	~binary_tree() noexcept = default;

	T data(void) const;
	const std::unique_ptr<binary_tree<T>>& left(void) const;
	const std::unique_ptr<binary_tree<T>>& right(void) const;

	void insert(const T& val);
};

}  // namespace binary_search_tree

#endif // BINARY_SEARCH_TREE_H