#include <stdlib.h>
#include <string.h>

#include "reverse_string.h"

char *reverse(const char *value){
	size_t len = strlen(value);
	char *reversed = malloc(sizeof *reversed * (len + 1));

	for (size_t i = 0; i < len; i++)
		reversed[i] = value[len - 1 - i];
	reversed[len] = '\0';
	
	return reversed;
}