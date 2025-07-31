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
	binary_tree<T>* _parent;
public:
	explicit binary_tree(const T& val, binary_tree<T>* parent = nullptr): _val{val}, _parent{parent}  {}
	~binary_tree() noexcept = default;

	const T& data() const { return _val; }
	const std::unique_ptr<binary_tree<T>>& left() { return _left; }
	const std::unique_ptr<binary_tree<T>>& right() { return _right; }

	void insert(const T& val) {
		if (val <= _val){
			if (_left) _left->insert(val);
			else _left = std::make_unique<binary_tree<T>>(val, this);
		}
		else{
			if (_right) _right->insert(val);
			else _right = std::make_unique<binary_tree<T>>(val, this);
		}
	}

	class iterator{
		binary_tree<T>* _ptr;
	public:
		using value_type = T;
		using difference_type = int;
		using pointer = T*;
		using reference = const T&;
		using iterator_category = std::forward_iterator_tag;

		iterator(binary_tree<T>* ptr = nullptr): _ptr{ptr} {}
		
		void operator=(const iterator& other) { _ptr = other._ptr; }

		bool operator==(const iterator& other) const { return _ptr == other._ptr; }
		bool operator!=(const iterator& other) const { return _ptr != other._ptr; }

		reference operator*() const { return _ptr->_val; }

		iterator& operator++(){
			if (_ptr){
				if (_ptr->_right){
					_ptr = leftmost_ptr(_ptr->_right.get());
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

		iterator operator++(int /* i */){
			iterator temp = *this;
			++(*this);
			return temp;
		}
	};

	iterator begin() {
		return iterator{leftmost_ptr(this)};
	}

	iterator end() {
		return iterator{nullptr};
	}

private:
	static binary_tree<T>* leftmost_ptr(binary_tree<T>* root) {
		if (root->_left) return leftmost_ptr(root->_left.get());
		return root;
	}

};

}  // namespace binary_search_tree

#endif // BINARY_SEARCH_TREE_H