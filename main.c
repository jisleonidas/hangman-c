#include <stdio.h>

#define MAX_WORD_LENGTH 15

#define TRUE 1
#define FALSE 0

void obfuscate_word(char *word);
int check_vowel(char ch);

int main()
{

	char word[MAX_WORD_LENGTH] = "hangman";

	obfuscate_word(word);

	printf("Welcome to a game of HANGMAN!\n");

	printf("Word to be guessed: %s\n", word);

	return 0;
}

void obfuscate_word(char *word)
{
	int i;
	char ch;

	for (i = 0; i < 15; i++) {
		ch = *word;
		if (ch != '\0')
			if (!check_vowel(ch))
				*word = '-';
		word++;
	}
}

int check_vowel(char ch)
{
	int i;
	char vowels[5] = "aeiou";

	for (i = 0; i < 5; i++) {
		if (ch == vowels[i])
			return TRUE;
		else
			return FALSE;
	}
}