#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "bob.h"

int is_all_caps(char *str, int len);
int is_whitespace(char a);
char *strip_whitespace(char *str, int len);

char *hey_bob(char *greeting){
	int len = strlen(greeting);

	char *striped = strip_whitespace(greeting, len);
	len = strlen(striped);

	int question = len > 0 ? (striped[len - 1] == '?' ? 1 : 0) : 0;
	int uppercase = is_all_caps(striped, len);
	int silence = (len == 0) ? 4 : 0;

	free(striped);

	if (question && !uppercase){
		return "Sure.";
	}
	if (!question && uppercase){
		return "Whoa, chill out!";
	}
	if (question && uppercase) {
		return "Calm down, I know what I'm doing!";
	}
	if (silence){
		return "Fine. Be that way!";
	}

	return "Whatever.";
}

int is_all_caps(char *str, int len){
	int upper = 0;
	for (int i = 0; i < len; i++){
		if('a' <= str[i] && str[i] <= 'z'){
			return 0;
		}
		if('A' <= str[i] && str[i] <= 'Z'){
			upper = 1;	
		}
	}
	return upper;
}

int is_whitespace(char a){
	return (a == ' ') || (a == '\n') || (a == '\t') || (a == '\r');
}

char *strip_whitespace(char *str, int len){
	int start = 0;
	while(start < len && is_whitespace(str[start])){
		start++;
	}
	int end = len - 1;
	while(end > start && is_whitespace(str[end])){
		end--;
	}

	int size = (end - start + 1);

	char *striped_str = (char *) malloc((size + 1)* sizeof(char)); // +1 for the \0
	memcpy(striped_str, &str[start], size * sizeof(char));
	striped_str[size] = '\0';

	return striped_str;
}