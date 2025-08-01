#if !defined(GIGASECOND_H)
#define GIGASECOND_H

#include "boost/date_time/posix_time/posix_time.hpp"

namespace gigasecond {

boost::posix_time::ptime advance(const boost::posix_time::ptime& datetime, int seconds = 1e9);

}  // namespace gigasecond

#endif // GIGASECOND_H