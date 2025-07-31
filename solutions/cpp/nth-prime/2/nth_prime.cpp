#include "nth_prime.h"

namespace nth_prime {

bool is_prime(int x, const std::vector<int>& primes){
    for (auto p : primes){
        if (p * p > x) return true;
        if (x % p == 0) return false;
    }
    return true;
}

int nth(int n){
    if (n < 1) throw std::domain_error("n should be larger than 0");
    if (n == 1) return 2;
    std::vector<int> primes{2};
    int i = 1;
    for (int x = 3; ; x +=2 ){
        if (is_prime(x, primes)){
            if (++i == n) return x;
            primes.push_back(x);
        }
    }
}

}  // namespace nth_prime
