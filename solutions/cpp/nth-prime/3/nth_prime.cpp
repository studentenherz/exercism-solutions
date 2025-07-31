#include "nth_prime.h"

#include <algorithm>

namespace nth_prime {

namespace {

bool is_prime(int x, const std::vector<int>& primes){
    for (auto p : primes){
        if (p * p > x) return true;
        if (x % p == 0) return false;
    }
    return true;
		// return std::none_of(primes.begin(), primes.end(), [x](int p){return x % p == 0;});
}

} // end of anonymous namespace

int nth(int n){
    if (n < 1) throw std::domain_error("n should be larger than 0");
    if (n == 1) return 2;
    std::vector<int> primes{2};
		primes.reserve(n);
    for (int x = 3; ; x +=2 ){
        if (is_prime(x, primes)){
            primes.push_back(x);
            if ((int) primes.size() == n) return x;
        }
    }
}

}  // namespace nth_prime
