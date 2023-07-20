#include "shell.h"

char **strtow(char *str, char *d)
{
  if (!valid_input(str, d))
    return NULL;

  int num_words = count_words(str, d);
  if (num_words == 0)
    return NULL;

  char **words = malloc((num_words + 1) * sizeof(char *));
  if (!words)
    return NULL;

  int i;
  for (i = 0; i < num_words; i++) {
    words[i] = get_next_word(str, d);
    str = find_next_delim(str, d);
  }
  words[i] = NULL;

  return words;
}

int valid_input(char *str, char *d)
{
  return str != NULL && str[0] != 0;
}

int count_words(char *str, char *d)
{
int i, num_words = 0;
  for (i = 0; str[i] != '\0'; i++) {
    if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
      num_words++;
  }
  return num_words;
}
char *get_next_word(char *str, char *d)
{
int len = 0;
  while (*str && !is_delim(*str, d))
    len++, str++;

  char *word = malloc(len + 1);
  if (!word)
    return NULL;
  _strncpy(word, str - len, len);
  word[len] = 0;

  return word;
}

char *find_next_delim(char *str, char *d)
{
while (*str && !is_delim(*str, d))
    str++;
  if (*str)
    str++;
  return str;
}



