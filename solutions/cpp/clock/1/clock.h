#if !defined(CLOCK_H)
#define CLOCK_H

#include <string>

namespace date_independent {

class clock{
	int _hour;
	int _minute;

	clock(int hour, int minute);
public:
	static clock at(int hour, int minute);
	clock plus(int added);

	bool operator==(const clock& other) const;
	bool operator!=(const clock& other) const;
	operator std::string() const;
};

}  // namespace date_independent

#endif // CLOCK_H