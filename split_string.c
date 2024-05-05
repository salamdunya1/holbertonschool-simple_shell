#include  "simple_shell.h"

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
    int c, v;
    char **words;
    char *str_ptr = str;
    bool start = false;
    unsigned int no_of_words;
    unsigned int word_sizes[MAX_WORD_COUNT];

    set_zeros[word_sizes, MAX_WORD_COUNT];
    no_of_words = count_words(str, seperators, word_sizes);

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
            for (v--; v>=0; v--)
                free(words[v]);
            free(words);
            return (NULL);
            
        }

        for (c = 0; c< word_sizes[v]; c++, str_ptr++)
        {
            while (is_delimiter(*str_ptr, separators))
                str_ptr++;

            words[v][c] = *str_ptr;    
            
        };


         words[v][c] = '\0'; 
        
    }

    *word_count = no_of_words;

    words[v] = NULL;

    return (words);
         
}
