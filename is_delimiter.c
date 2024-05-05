#include "simple_shell.h"

/**
 * is_delimiter - check if a character is a delimiter
 * @c: the character to check
 * @delimiters: the set of delimiter characters
 *
 * Return: true if the character is a delimiter, false otherwise.
 */
bool is_delimiter(char c, const char *delimiters) {
    const char *d = delimiters;
    while (*d) {
        if (c == *d) {
            return true;
        }
        d++;
    }
    return false;
}
