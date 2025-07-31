#include "sieve.h"

namespace sieve {

std::vector<int> primes(int n) {
	std::vector<int> ans;

	if (n > 1){
		std::vector<bool> sieve(n + 1, true);
		int p = 2;
		ans.push_back(2);
		while (p <= n) {
			if (sieve[p])
				for (int i = 2 * p; i <= n; i += p)
					sieve[i] = false;
			p++;
		}
		for (int i = 3; i <= n; i += 2)
			if (sieve[i]) ans.push_back(i);
	}

	return ans;
}

}  // namespace sieve
