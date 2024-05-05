#include "simple_shell.h"

/**
 * count_words - count the number of words in a string based on delimiters
 * @str: the string to parse
 * @delimiters: the set of delimiter characters
 * @word_sizes: an array to store the size of each word
 *
 * Return: the number of words found in the string.
 */
unsigned int count_words(const char *str, const char *delimiters, unsigned int *word_sizes) {
    bool in_word = false;
    unsigned int word_count = 0;
    const char *ptr = str;

    while (*ptr) {
        if (is_delimiter(*ptr, delimiters)) {
            if (in_word) {
                in_word = false;
            }
        } else {
            if (!in_word) {
                in_word = true;
                word_count++;
            }
            word_sizes[word_count - 1]++;
        }
        ptr++;
    }

    return word_count;
}
