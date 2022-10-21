#include <stdio.h>

#define MAX_WORD_LENGTH 15

#define TRUE 1
#define FALSE 0

void obfuscate_word(char *word, int *c_count);
int is_vowel(char ch);

int main()
{
	int consonant_count = 0; /* No. of consonants in current word. */
	char word[MAX_WORD_LENGTH] = "hangman";

	obfuscate_word(word, &consonant_count);
	printf("%d\n", consonant_count);

	printf("Welcome to a game of HANGMAN!\n");

	printf("Word to be guessed: %s\n", word);

	return 0;
}

void obfuscate_word(char *word, int *consonant_count)
{
	int i;
	char ch;

	for (i = 0; i < 15; i++) {
		ch = *word;
		if (ch != '\0')
			if (!is_vowel(ch)) {
				*word = '-';
				(*consonant_count)++; /* Brackets are must! */
			}
		word++;
	}
}

int is_vowel(char ch)
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