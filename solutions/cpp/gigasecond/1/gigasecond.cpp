#include "gigasecond.h"

namespace gigasecond {

boost::posix_time::ptime advance(const boost::posix_time::ptime& datetime, int seconds) {
	return datetime + boost::posix_time::time_duration(0, 0, seconds);
}


}  // namespace gigasecond
