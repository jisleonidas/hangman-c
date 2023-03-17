#include "header.h"
#include "guess.c"
#include "file.c"

void obfuscate_word(char *word, int *c_count);

int main()
{
	int i, consonant_count; /* No. of consonants in current word. */
	char *word, *obfus_word;
	char words[100][MAX_WORD_LENGTH], copy_word[MAX_WORD_LENGTH];

	read_words(words); /* Read words from file words.txt */
	
	printf("Welcome to a game of HANGMAN!\n");

	for (i = 0; i < 100; i++) {
		consonant_count = 0; /* Reset consonant count for every word. */
		word = words[i]; /* Select (i+1)th word */
		strcpy(copy_word, word); /* Make a copy of actual word */
		obfus_word = word;
		obfuscate_word(word, &consonant_count); /* Obfuscate actual word */
		guess_handler(obfus_word, copy_word, consonant_count);
	}

	return 0;
}

void obfuscate_word(char *word, int *consonant_count)
{
	int i;
	char ch;

	for (i = 0; i < MAX_WORD_LENGTH; i++) {
		ch = *word;
		if (ch == '\0')
			return;
		if (!is_vowel(ch)) {
			*word = '-';
			(*consonant_count)++; /* Brackets are must! */
		}
		word++;
	}
}