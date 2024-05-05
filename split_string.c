#include  "simple_shell.h"
#define MAX_WORD_COUNT 1024
/**
 * split_string - split a string into words specified by a delimiter(s),
 *                string the pointer to each word (null-terminated)
 *                in an array.
 * 
 * Return: Vector of pointers to string (words).
 *         Remember to free vector after use.
*/

char **split_string(char *str, char *separators, int *word_count)
{
    unsigned int c, v;
    char **words;
    char *str_ptr = str;
    unsigned int no_of_words;
    unsigned int word_sizes[MAX_WORD_COUNT];

    set_zeros(word_sizes, MAX_WORD_COUNT);
    no_of_words = count_words(str, separators, word_sizes);

    if(no_of_words == 0)
       return (NULL);

    words = malloc((sizeof(char *) * no_of_words) + 1);
    if(!words)
       return (NULL);

    for (v = 0; v < no_of_words; v++)
    {
        words[v] = malloc((sizeof(char) * word_sizes[v]) + 1);
        if (!words[v])
        {
            for (unsigned int j = v; j > 0; j--) {
                free(words[j - 1]); 
}
            free(words);
            return (NULL);
            
        }

        c = 0; 
        while (c < word_sizes[v] && !is_delimiter(*str_ptr, separators)) {
            words[v][c] = *str_ptr;
            str_ptr++;
            c++;
        }


         words[v][c] = '\0'; 
        
    }

    *word_count = no_of_words;

    words[v] = NULL;

    return (words);
         
}
