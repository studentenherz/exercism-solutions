#include "grade_school.h"

#include <algorithm>

namespace grade_school {

const std::vector<std::string> school::_empty;

const roster_t& school::roster() const {
	return _roster;
}

void school::add(const std::string& name, int grade){
	auto& grade_vector = _roster[grade];
	grade_vector.push_back(name);
	std::sort(grade_vector.begin(), grade_vector.end());
}

const std::vector<std::string>& school::grade(int grade) const {
	auto it = _roster.find(grade);
	return (it != _roster.end() ? it->second : _empty);
}

}  // namespace grade_school
