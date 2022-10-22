#include "header.h"

void obfuscate_word(char *word, int *c_count);

int main()
{
	int consonant_count = 0; /* No. of consonants in current word. */
	char word[MAX_WORD_LENGTH] = "hangman", copy_word[MAX_WORD_LENGTH];

	strcpy(copy_word, word); /* copy to copy_word, the contents of word */

	obfuscate_word(word, &consonant_count);
	/* printf("%d\n", consonant_count); */

	printf("Welcome to a game of HANGMAN!\n");

	printf("Word to be guessed: %s\n", word);

	return 0;
}

void obfuscate_word(char *word, int *consonant_count)
{
	int i;
	char ch;

	for (i = 0; i < MAX_WORD_LENGTH; i++) {
		ch = *word;
		if (ch != '\0')
			if (!is_vowel(ch)) {
				*word = '-';
				(*consonant_count)++; /* Brackets are must! */
			}
		word++;
	}
}