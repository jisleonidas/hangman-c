#include "header.h"

void add_word(FILE *words_file, char (*words)[MAX_WORD_LENGTH], char *word);
char strip_line(FILE *words_file, char (*words)[MAX_WORD_LENGTH], char *word);

void read_words(char r_words[100][MAX_WORD_LENGTH])
{
        int i, j;
        char ch, word[MAX_WORD_LENGTH];
        char words[MAX_WORDS][MAX_WORD_LENGTH] = {'\0'}; /* Intialize empty string*/
        FILE *words_file;

        words_file = fopen("words.txt", "r");

        add_word(words_file, words, word);

        /* for (i = 0; i < 100; i++) /* Testing to see if function */
        /*        printf("%s\n", words[i]); /* works properly.*/

        for (i = 0; i < MAX_WORDS; i++) {
                strcpy(r_words[i], words[i]);
        }

        fclose(words_file);
}

void add_word(FILE *words_file, char (*words)[MAX_WORD_LENGTH], char *word)
{
        int word_num = 0;
        char final_char;
        for (word_num = 0; word_num < MAX_WORDS; word_num++) {
                /*
                if (strip_line(words_file, words, word) == '\n') {
                        strcpy(words[word_num], word);
                        word_num;
                }
                */
                final_char = strip_line(words_file, words, word);
                strcpy(words[word_num], word);
                if (final_char == EOF)
                        break;
        }
}

char strip_line(FILE *words_file, char (*words)[MAX_WORD_LENGTH], char *word)
{
        int i, j;
        char ch;

        i = 0; /* index of char in current word */
        ch == ' ';
        while (i < MAX_WORD_LENGTH-1) {
                ch = getc(words_file);
                if (ch == EOF || ch == '\n')
                        break;
                word[i] = ch; /* current word being stripped. */
                i++;
        }
        word[i] = '\0';
        /*
        if (ch == '\n') {
                add_word(words_file, words, word);
        }
        */

        return ch;
}