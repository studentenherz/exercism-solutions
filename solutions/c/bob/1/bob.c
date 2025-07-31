#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "bob.h"

short is_all_caps(char *str, int len);
short is_whitespace(char a);
char *strip_whitespace(char *str, int len);

char *hey_bob(char *greeting){
	int len = strlen(greeting);

	char *striped = strip_whitespace(greeting, len);
	len = strlen(striped);

	short question = striped[len - 1] == '?' ? 1 : 0;
	short uppercase = is_all_caps(striped, len);
	short silence = (len == 0) ? 4 : 0;

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

short is_all_caps(char *str, int len){
	short upper = 0;
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

short is_whitespace(char a){
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

	int size = (end - start) * sizeof(char);
	if (size < 0) size = 0;
	size++; // for the \0 character
	char *striped_str = (char *) malloc(size);	
	memcpy(striped_str, &str[start], size);

	return striped_str;
}