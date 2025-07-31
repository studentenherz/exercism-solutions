#include "prime_factors.h"

namespace prime_factors {

bool is_prime(const std::vector<int>& primes, int x){
	for (int p : primes){
		if (x % p == 0) return false;
		if (p * p > x) return true;
	}
	return true;
}

void add_next_prime(std::vector<int>& primes){
	int x = primes.back() + (primes.back() % 2 == 0 ? 1 : 2);
	while (!is_prime(primes, x)) x += 2;
	primes.push_back(x);
}

std::vector<int> of(int n) {
	std::vector<int> primes{2};
	std::vector<int> factors;

	while(n > 1){
		int p = primes.back();
		
		while (n % p == 0){
			factors.push_back(p);
			n /= p;
		}
		
		if (p * p > n){
			if (n != 1) factors.push_back(n);
			return factors;
		}

		add_next_prime(primes);
	}

	return factors;
}

}  // namespace prime_factors
