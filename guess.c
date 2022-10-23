#include "header.h"

int guess_handler(char *obfus_word, char *word)
{
        char ch;
        int one_ch_input = FALSE, guess_correct, rem_guesses;
        rem_guesses = MAX_GUESSES;

        while (rem_guesses > 0) {
                printf("Question word: %s\n", obfus_word);
                printf("Enter your guess (one character): ");
                ch = getchar();
                one_ch_input = skipgarb();
                if (one_ch_input) {
                        guess_correct = check_guess(ch, obfus_word, word);
                        if (!guess_correct)
                                rem_guesses -= 1;
                }
                else {
                        printf("Please enter only one character.\n");
                }
        }
}

int check_guess(char ch, char *obfus_word, char *word)
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
                        if (ch == word[i]) {
                                print("Your guess is correct! Continue playing.");
                                obfus_word[i] = ch;
                                return TRUE;
                        }
                return FALSE;
        }
}