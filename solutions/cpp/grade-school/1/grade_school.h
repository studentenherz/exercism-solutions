#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <map>
#include <vector>
#include <string>

namespace grade_school {

using roster_t = std::map<int, std::vector<std::string>>;

class school{
	roster_t _roster;
	const std::vector<std::string> _empty;
public:
	const roster_t& roster() const;
	void add(const std::string& name, int grade);
	const std::vector<std::string>& grade(int grade) const;
};

}  // namespace grade_school

#endif // GRADE_SCHOOL_H