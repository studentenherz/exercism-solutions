#include "clock.h"

namespace date_independent {

namespace {

std::string two_digits(int n){
	return (n < 10 ? "0" : "") + std::to_string(n);
}

}

clock::clock(int hour, int minute): _hour{hour}, _minute{minute} {}

clock::operator std::string() const {
	return two_digits(_hour) + ":" + two_digits(_minute);
}

clock clock::at(int hour, int minute){
	int min_remainder = minute % 60;
	int min_2_hour = minute / 60 + (min_remainder < 0 ? -1 : 0);
	min_remainder = (min_remainder + 60) % 60;

	return clock(((hour + min_2_hour) % 24 + 24) % 24, min_remainder);
}

clock clock::plus(int added){
	added += _minute;
	int min_remainder = added % 60;
	int min_2_hour = added / 60 + (min_remainder < 0 ? -1 : 0);
	_minute = (min_remainder + 60) % 60;
	_hour = ((_hour + min_2_hour) % 24 + 24) % 24;

	return *this;
}

bool clock::operator==(const clock& other) const {
	return _hour == other._hour && _minute == other._minute;
}

bool clock::operator!=(const clock& other) const {
	return !(*this == other);
}


}  // namespace date_independent
