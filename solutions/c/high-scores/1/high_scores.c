#include <string.h>

#include "high_scores.h"

int32_t latest(const int32_t *scores, size_t scores_len){
	return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len){
	int32_t max = INT32_MIN;
	for (size_t i = 0; i < scores_len; i++){
		if (scores[i] > max){
			max = scores[i];
		}
	}

	return max;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output){
	memset(output, INT32_MIN, 3);
	size_t added = 0;

	for (size_t i = 0; i < scores_len; i++){
		if (scores[i] > output[2]){
			added++;
			output[2] = scores[i];
			for (size_t k = 2; k > 0; k--){
				if (output[k] > output[k - 1]){
					int32_t tmp = output[k];
					output[k] = output[k - 1];
					output[k - 1] = tmp;
				}
			}
		}
	}

	return added < 3 ? added : 3;
}