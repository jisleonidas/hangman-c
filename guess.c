#include "header.h"

int check_guess(char ch, char *obfus_word, char *word);

int guess_handler(char *obfus_word, char *word, int consonant_count)
{
        char ch;
        char original_word[MAX_WORD_LENGTH];
        int one_ch_input, guess_correct, rem_guesses;

        one_ch_input = FALSE;
        rem_guesses = MAX_GUESSES;

        strcpy(original_word, word);

        while (rem_guesses > 0) {
                printf("Question word: %s\n", obfus_word);
                printf("Enter your guess (one character): ");
                ch = getchar();
                one_ch_input = skipgarb();
                if (one_ch_input) {
                        guess_correct = check_guess(ch, obfus_word, word);
                        if (guess_correct) {
                                consonant_count -= 1;
                        }
                        else {
                                printf("Your guess is wrong.");
                                printf("TRY AGAIN.\n");
                        }
                }
                else {
                        printf("Please enter only one character.\n");
                }
                if (consonant_count == 0) {
                        printf("You have guessed the word correctly!");
                        printf(" CONGRATS!\n");
                        printf("The word is: %s\n", original_word);
                        break;
                }
        }
}

int check_guess(char ch, char *obfus_word, char *word)
{
        int i;

        if (!is_alpha(ch)) {
                printf("Please enter only letters of the alphabet.\n");
                return FALSE;
        }
        if (is_vowel(ch)) {
                printf("Please enter only consonants.\n");
        }
        else {
                for (i = 0; i < MAX_WORD_LENGTH; i++)
                        if (ch == word[i]) {
                                printf("Your guess is correct! Continue playing.\n");
                                obfus_word[i] = ch;
                                word[i] = '-';
                                return TRUE;
                        }
                return FALSE;
        }
}