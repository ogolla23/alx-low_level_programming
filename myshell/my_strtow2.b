#include "shell.h"

int count_words(char *str, char d);
char **allocate_memory(int numwords);
int split_string(char *str, char **s, int numwords, char d);

char **strtow2(char *str, char d)
{
    int numwords;
    char **s;

    if (str == NULL || str[0] == '\0')
        return NULL;

    numwords = count_words(str, d);
    if (numwords == 0)
        return NULL;

    s = allocate_memory(numwords);
    if (!s)
        return NULL;

    if (split_string(str, s, numwords, d) == -1)
        return NULL;

    return s;
}

int count_words(char *str, char d)
{
    int i, numwords = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] != d && str[i + 1] == d) ||
            (str[i] != d && !str[i + 1]) || str[i + 1] == d)
            numwords++;
    }

    return numwords;
}

char **allocate_memory(int numwords)
{
    char **s = malloc((1 + numwords) * sizeof(char *));
    if (!s)
        return NULL;

    return s;
}

int split_string(char *str, char **s, int numwords, char d)
{
    int i, j, k, m;

    for (i = 0, j = 0; j < numwords; j++)
    {
        while (str[i] == d && str[i] != d)
            i++;

        k = 0;
        while (str[i + k] != d && str[i + k] && str[i + k] != d)
            k++;

        s[j] = malloc((k + 1) * sizeof(char));
        if (!s[j])
        {
            for (k = 0; k < j; k++)
                free(s[k]);
            free(s);
            return -1;
        }

        for (m = 0; m < k; m++)
            s[j][m] = str[i++];

        s[j][m] = '\0';
    }

    s[j] = NULL;
    return 0;
}

