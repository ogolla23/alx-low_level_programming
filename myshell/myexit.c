#include "shell.h"
#define INVALID -1
#define success_status 0
#define error_status 2
int _myexit(info_t *info)
{
  int exit_status = get_exit_status(info);
  set_exit_status(info, exit_status);
  return -2; 
} 

int get_exit_status(info_t *info) 
{
  if (has_argument(info)) {
    int argument_status = convert_argument(info->argv[1]);
    if (argument_status == INVALID) {
      handle_invalid_input(info);
      return error_status; 
    }
    return argument_status; 
  }
  
  return success_status;
}

int has_argument(info_t *info) 
{
  return info->argv[1] != NULL;
} 

int convert_argument(char *argument)
{
  int argument_status = _erratoi(argument);   
  if (argument_status == -1) 
    return INVALID;
  return argument_status; 
}

void handle_invalid_input(info_t *info)
{
  print_error(info, "Illegal number: ");
  _eputs(info->argv[1]);
  _eputchar('\n');  
}

void set_exit_status(info_t *info, int exit_status) 
{
  info->err_num = exit_status; 
}
