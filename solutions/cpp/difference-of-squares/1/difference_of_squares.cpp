#include "difference_of_squares.h"

namespace difference_of_squares {

unsigned long long square_of_sum(unsigned long long n){
    return n * n * (n + 1) * (n + 1) / 4;
}
unsigned long long sum_of_squares(unsigned long long n){
    return n * (n + 1) * (2 * n + 1) / 6;
}
unsigned long long difference(unsigned long long n){
    return square_of_sum(n) - sum_of_squares(n);
}

}  // namespace difference_of_squares
