#include "header.h"

int guess_handler(char *obfus_word, char *word)
{
        char ch;
        int one_ch_input = FALSE, index_char, guess_correct, rem_guesses;
        rem_guesses = MAX_GUESSES;

        while (TRUE) {
                printf("Enter your guess (one character): ");
                ch = getchar();
                one_ch_input = skipgarb();
                if (one_ch_input) {
                        guess_correct = check_guess(ch, word);
                        if (!guess_correct)
                                rem_guesses -= 1;
                }
                else {
                        printf("Please enter only one character.\n");
                }
        }
}

int check_guess(char ch, char *word)
{
        int i;

        if (!is_alpha(ch)) {
                print("Please enter only letters of the alphabet.");
                return FALSE;
        }
        if (is_vowel(ch)) {
                printf("Please enter only consonants.\n");
        }
        else {
                for (i = 0; i < MAX_WORD_LENGTH; i++)
                        if (ch == word[i])
                                return TRUE;
                return FALSE;
        }
}