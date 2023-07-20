#include "shell.h"
/**
* clear_info - initializes info_t struct
* @info: struct address
*/
void clear_info(info_t *info)
{
info->arg = NULL;
info->argv = NULL;
info->path = NULL;
info->argc = 0;
}
/**
* set_info - initializes info_t struct
* @info: struct address
* @av: argument vector
*/

/**
* free_info - frees info_t struct fields
* @info: struct address
* @all: true if freeing all fields
*/
