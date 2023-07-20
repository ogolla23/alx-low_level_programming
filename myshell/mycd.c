#include "shell.h"
int _mycd(info_t *info) 
{
  char *dest_dir = get_dest_dir(info);
  int chdir_result = change_directory(dest_dir);
  
  if (chdir_result == -1) {
    handle_chdir_error(info, dest_dir);
  } else {
    update_pwd_env(info); 
  }

  return 0; 
}

char *get_dest_dir(info_t *info)
{
  char *dir = NULL;
  if (!info->argv[1]) 
    dir = _getenv(info, "HOME="); 
  else if (_strcmp(info->argv[1], "-") == 0)
    dir = _getenv(info, "OLDPWD=");
  else 
    dir = info->argv[1];
  
  return dir; 
}

int change_directory(char *dest_dir) 
{
  int chdir_result = chdir(dest_dir);
  
  if (chdir_result == -1) {
    return -1; 
  } 
  
  return 0; 
}

void handle_chdir_error(info_t *info, char *dest_dir) 
{
  print_error(info, "can't cd to ");
  _eputs(dest_dir);
  _eputchar('\n');
}

void update_pwd_env(info_t *info) 
{
char buffer[1024];
  _setenv(info, "OLDPWD", _getenv(info, "PWD="));
  _setenv(info, "PWD", getcwd(buffer, 1024)); 
}
