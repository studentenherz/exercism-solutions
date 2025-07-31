#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "bob.h"

static bool is_all_caps(char *str);
static bool is_whitespace(char a);
static char *strip_whitespace(char *str);

char *hey_bob(char *greeting){
	int len = strlen(greeting);

	char *striped = strip_whitespace(greeting);
	len = strlen(striped);

	bool question = len > 0 && striped[len - 1] == '?';
	bool uppercase = is_all_caps(striped);
	bool silence = len == 0;

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

bool is_all_caps(char *str){
	int upper = 0;
	for (const char *c = str; *c; c++){
		if('a' <= *c && *c <= 'z'){
			return 0;
		}
		if('A' <= *c && *c <= 'Z'){
			upper = 1;	
		}
	}
	return upper;
}

bool is_whitespace(char a){
	return (a == ' ') || (a == '\n') || (a == '\t') || (a == '\r');
}

char *strip_whitespace(char *str){
	int len = strlen(str);

	int start = 0;
	while(start < len && is_whitespace(str[start])){
		start++;
	}
	int end = len - 1;
	while(end > start && is_whitespace(str[end])){
		end--;
	}

	int size = (end - start + 1);

	char *striped_str = malloc(sizeof *striped_str * (size + 1)); // +1 for the \0
	memcpy(striped_str, &str[start], sizeof *striped_str * size);
	striped_str[size] = '\0';

	return striped_str;
}