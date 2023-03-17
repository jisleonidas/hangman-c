#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 15
#define MAX_GUESSES 8

#define TRUE 1
#define FALSE 0

int skipgarb()
{
        if (getchar() == '\n') {
                return TRUE;
        }
        else {
                while (getchar() != '\n') {
                }
		return FALSE;
        }
}

int is_vowel(char ch)
{
	int i;
	static char vowels[5] = "aeiou";

	for (i = 0; i < 5; i++) {
		if (ch == vowels[i])
			return TRUE;
	}

	return FALSE;
}

int is_alpha(char ch)
{
        int i;
        char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";

	for (i = 0; i < 26; i++) {
		if (ch == alphabet[i])
			return TRUE;
	}
	return FALSE;
}
#endif /* HEADER_H*/