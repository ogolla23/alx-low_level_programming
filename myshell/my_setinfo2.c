#include "shell.h"
void set_info(info_t *info, char **av)
{
    info->fname = av[0];
    if (info->arg)
    {
        info->argv = tokenize_argument(info->arg);
        info->argc = count_args(info->argv);
        replace_alias(info);
        replace_vars(info);
    }
}

char **tokenize_argument(char *arg)
{
    char **argv = strtow(arg, " \t");
    if (!argv)
    {
        argv = malloc(sizeof(char *) * 2);
        if (argv)
        {
            argv[0] = _strdup(arg);
            argv[1] = NULL;
        }
    }
    return argv;
}

int count_args(char **argv)
{
    int i;
    for (i = 0; argv && argv[i]; i++)
        ;
    return i;
}
