#include "collatz_conjecture.h"

#include <stdexcept>

namespace collatz_conjecture {

int steps(int n){
    if (n <= 0){
        throw std::domain_error("n should be a positive number");
    }
    
    int s = 0;
    while (n != 1){
        n = (n % 2 == 0 ? n / 2 : 3 * n + 1);
        s++;
    }
    return s;
}

}  // namespace collatz_conjecture
