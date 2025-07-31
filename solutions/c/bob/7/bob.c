#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "bob.h"

typedef struct{
	int len;
	const char *str;
} str_view_t;

static bool is_all_caps(str_view_t);
static inline bool is_whitespace(char a);
static str_view_t strip_whitespace(const char *str);


char *hey_bob(const char *greeting){
	str_view_t striped = strip_whitespace(greeting);

	bool question = striped.len > 0 && striped.str[striped.len - 1] == '?';
	bool uppercase = is_all_caps(striped);
	bool silence = striped.len == 0;

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

bool is_all_caps(str_view_t str_view){
	bool upper = false;
	for (int i = 0; i < str_view.len; i++){
		if('a' <= str_view.str[i] && str_view.str[i] <= 'z'){
			return false;
		}
		if('A' <= str_view.str[i] && str_view.str[i] <= 'Z'){
			upper = true;	
		}
	}
	return upper;
}

bool is_whitespace(char a){
	return (a == ' ') || (a == '\n') || (a == '\t') || (a == '\r');
}

str_view_t strip_whitespace(const char *str){
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

	str_view_t str_view = {.len=size, .str=&str[start]};

	return str_view;
}