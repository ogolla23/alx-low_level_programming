#include "shell.h"
bool valid_command(info_t* info) {

  int i, k;
  
  for (i = 0, k = 0; info->arg[i]; i++) {
    if (!is_delim(info->arg[i], " \t\n")) {
      k++; 
    }
  }

  return (k > 0);
}

void handle_not_found(info_t* info) {

  if (_(info->arg) != '\n') {
    info->status = 127;
    print_error(info, "not found\n");
  }

}

void find_cmd(info_t* info) {

  if (info->linecount_flag == 1) {
    char* path = find_path(info, getenv(info, "PATH="), info->argv[0]);
  }

  if (!valid_command(info)) {
    return;
  }

  char* path = find_path(info, getenv(info, "PATH="), info->argv[0]);

  if (path) {
	  info->path = path;
    fork_cmd(info);
  } else {

    if (interactive(info) || getenv(info, "PATH=") || info->argv[0][0] == '/' 
        && iscmd(info, info->argv[0])) {
      fork_cmd(info);
    } else {
      handle_not_found(info);
    }

  }

}
