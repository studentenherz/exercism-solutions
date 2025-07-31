#include <math.h>

#include "armstrong_numbers.h"

static int recursive_exp(int base, int exponent){
	if (exponent == 0){
		return 1;
	}
	
	if (exponent % 2 == 0){
		int half_pow = recursive_exp(base, exponent / 2);
		return half_pow * half_pow;
	}
	else{
		return base * recursive_exp(base, exponent - 1);
	}
}

bool is_armstrong_number(int candidate){
	int n = log10(candidate) + 1;
	int candidate_cpy = candidate;

	int sum = 0;
	candidate_cpy = candidate;
	for (int i = 0; i < n; i++){
		sum += recursive_exp(candidate_cpy % 10, n);
		candidate_cpy /= 10;
	}

	return sum == candidate;
}
