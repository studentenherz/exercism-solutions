#if !defined(TRIANGLE_H)
#define TRIANGLE_H

#include <stdexcept>

namespace triangle {

using flavor = enum triangle_type {
	scalene,
	isosceles,
	equilateral
};

namespace {

template <typename Ta, typename Tb, typename Tc>
bool is_triangle(Ta a, Tb b, Tc c){
	if (a <= 0 || b <= 0 || c <= 0) return false;
	return (a + b > c && b + c > a && c + a > b);
}

template <typename Ta, typename Tb, typename Tc>
flavor ordered_kind(Ta a, Tb b, Tc c){
	if (a == b){
		if (b == c) return flavor::equilateral;
		return flavor::isosceles;
	}
	return flavor::scalene;
}

} // anonymous namespace


template <typename Ta, typename Tb, typename Tc>
flavor kind(Ta a, Tb b, Tc c){
	if (!is_triangle(a, b, c)) throw std::domain_error("Invalid triangle sides");
	return std::max(ordered_kind(a, b, c), std::max(
		ordered_kind(b, c, a),
		ordered_kind(c, a, b)
	));
}

}  // namespace triangle

#endif // TRIANGLE_H