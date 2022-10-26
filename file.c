#include "header.h"

void add_word(FILE *words_file, char *(*words), char *word, int word_num);

int main()
{
        char ch, word[MAX_WORD_LENGTH], *words[100][MAX_WORD_LENGTH];
        FILE *words_file;

        words_file = fopen("words.txt", "r");

        void strip_words();

        for (i = 0; i < 100; i++) /* Testing to see if function */
                printf("%s\n", words[i]); /* works properly.*/
}

void add_word(FILE *words_file, char *(*words), char *word, int word_num)
{
        if (getc(words_file) == '\n') {
                strcpy(words[word_num], word);
                word_num;
        }
        else {
                skipgarb();
        }
}

// void strip_words(FILE *words_file, char *words, char *word)
// {
//         int i, j;

//         while (ch = getc(words_file) != EOF) { /* strip words from file. */
//                 i = 0;
//                 j = 0;
//                 while (ch != '\n')
//                         word[i] = ch; /* current word being stripped. */
//                         i += 1; /* character index in word. */
//                         if (i == MAX_WORD_LENGTH)
//                                 add_word(words_file, &words, word, j);
//         }
// }