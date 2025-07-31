#if !defined(NTH_PRIME_H)
#define NTH_PRIME_H

namespace nth_prime {

#include <vector>
#include <stdexcept>

bool is_prime(int, const std::vector<int>&);
int nth(int);

}  // namespace nth_prime

#endif // NTH_PRIME_H