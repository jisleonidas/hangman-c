#include "header.h"

int check_guess(char ch, int *rem_guesses, char *obfus_word, char *word);
int match_char(char ch, int *rem_guesses, char *obfus_word, char *word);

int guess_handler(char *obfus_word, char *word, int consonant_count)
{
        char ch;
        char original_word[MAX_WORD_LENGTH];
        int one_ch_input, guess_correct, rem_guesses;

        one_ch_input = FALSE;
        rem_guesses = MAX_GUESSES;

        strcpy(original_word, word);

        while (rem_guesses > 0) {
                printf("\nQuestion word: %s\n", obfus_word);
                printf("Enter your guess (one character): ");
                ch = getchar();

                /* Check if only one character was entered. */
                one_ch_input = skipgarb();

                if (one_ch_input) {
                        guess_correct = check_guess(ch, &rem_guesses,
                                obfus_word, word);
                        if (guess_correct)
                                consonant_count -= 1;
                } else {
                        printf("Please enter only one character.\n");
                }

                /*
                 * Only the consonants are to be guessed in the given word.
                 * If all the consonants have been guessed, print the
                 * congratulatory message.
                 */
                if (consonant_count == 0) {
                        printf("You have guessed the word correctly!");
                        printf(" CONGRATS!\n");
                        printf("The word is: %s\n", original_word);
                        break;
                }
        }

        if (rem_guesses == 0) {
                printf("Sorry. You have run out of attempts. ");
                printf("You have not guessed the word.\n");
        }
}

int check_guess(char ch, int *rem_guesses, char *obfus_word, char *word)
{
        int i;

        if (!is_alpha(ch)) {
                printf("Please enter only letters of the alphabet.\n");
                return FALSE;
        }

        if (is_vowel(ch)) {
                printf("Please enter only consonants.\n");
                return FALSE;
        } else {
                return match_char(ch, rem_guesses, obfus_word, word);
        }
}

int match_char(char ch, int *rem_guesses, char *obfus_word, char *word)
{
        int i;

        for (i = 0; i < MAX_WORD_LENGTH; i++)
                if (ch == word[i]) {
                        printf("Your guess is correct! Continue ");
                        printf("playing.\n");
                        obfus_word[i] = ch;

                        /*
                         * Correctly guessed letter is blotted out from the
                         * actual word against which the input char is matched
                         * so as to not match the same letter at the same
                         * location repeatedly.
                         */
                        word[i] = '-';

                        return TRUE;
                }

        printf("Your guess is wrong.");
        printf("TRY AGAIN.\n");
        *rem_guesses -= 1;
        printf("Remaining attempts: %d\n"
                , *rem_guesses);
        return FALSE;
}