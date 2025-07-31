#if !defined(BINARY_SEARCH_TREE_H)
#define BINARY_SEARCH_TREE_H

#include <initializer_list>
#include <memory>

namespace binary_search_tree {

template<typename T>
class binary_tree{
	const T _val;
	std::unique_ptr<binary_tree<T>> _left = nullptr;
	std::unique_ptr<binary_tree<T>> _right = nullptr;
	binary_tree<T>* const _parent = nullptr;
public:
	explicit binary_tree(const T& val): _val{val} {}

	const T& data() const { return _val; }
	const std::unique_ptr<binary_tree<T>>& left() const { return _left; }
	const std::unique_ptr<binary_tree<T>>& right() const { return _right; }

	void insert(const T& val) {
		if (_val < val){
			if (_right) _right->insert(val);
			else _right = std::unique_ptr<binary_tree<T>>{new binary_tree<T>(val, this)};
		}
		else{
			if (_left) _left->insert(val);
			else _left = std::unique_ptr<binary_tree<T>>{new binary_tree<T>(val, this)};
		}
	}

	class const_iterator{
		friend class binary_tree;

		const binary_tree<T>* _ptr = nullptr;
	public:
		using value_type = const T;
		using difference_type = int;
		using pointer = value_type*;
		using reference = value_type&;
		using iterator_category = std::forward_iterator_tag;

		const_iterator() {}
		
		void operator=(const const_iterator& other) { _ptr = other._ptr; }

		bool operator==(const const_iterator& other) const { return _ptr == other._ptr; }
		bool operator!=(const const_iterator& other) const { return _ptr != other._ptr; }

		reference operator*() const { return _ptr->_val; }

		const_iterator& operator++(){
			if (_ptr){
				if (_ptr->_right){
					_ptr = leftmost_ptr(*_ptr->_right);
				}
				else {
					while (_ptr->_parent && _ptr->_parent->_val < _ptr->_val){
						_ptr = _ptr->_parent;
					}
					_ptr = _ptr->_parent;
				}
			}
			return *this;
		}

		const_iterator operator++(int /* i */){
			const_iterator temp = *this;
			++(*this);
			return temp;
		}
	private:
		const_iterator(const binary_tree<T>* ptr = nullptr): _ptr{ptr} {}
	};

	using itetator = const_iterator;

	const_iterator begin() const {
		return const_iterator{leftmost_ptr(*this)};
	}

	const_iterator end() const {
		return const_iterator{nullptr};
	}

private:
	binary_tree(const T& val, binary_tree<T>* parent): _val{val}, _parent{parent}  {}

	static const binary_tree<T>* leftmost_ptr(const binary_tree<T>& root) {
		if (root._left) return leftmost_ptr(*root._left);
		return &root;
	}

};

}  // namespace binary_search_tree

#endif // BINARY_SEARCH_TREE_H