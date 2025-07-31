#if !defined(CIRCULAR_BUFFER_H)
#define CIRCULAR_BUFFER_H

#include <vector>
#include <stdexcept>

namespace circular_buffer {

template <typename T>
class circular_buffer{
	std::vector<T> _buffer;
	size_t _size = 0;
	size_t _curr = 0;
public:
	circular_buffer(size_t buffer_size): _buffer(buffer_size) {}

	T read() {
		if (!_size) throw std::domain_error("Can't read from an empty buffer");
		T temp = _buffer[_curr];
		_curr = (_curr + 1) % _buffer.size();
		_size--;
		return temp;
	}

	void write(const T& value){
		if (_size == _buffer.size()) throw std::domain_error("Can't write on full buffer");
		_buffer[(_curr + _size) % _buffer.size()] = value;
		_size++;
	}

	void clear(){ _size = 0; }

	void overwrite(const T& value){
		_buffer[(_curr + _size) % _buffer.size()] = value;
		if (_size < _buffer.size())
			_size++;
		else{
			_curr = (_curr + 1)  % _buffer.size();
		}
	}

};

}  // namespace circular_buffer

#endif // CIRCULAR_BUFFER_H