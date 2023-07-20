#include "shell.h"

char *get_next_path_segment(char *pathstr, int *idx);
char *join_path(char *dir, char *file);

char *dup_chars(char *str, int start, int stop);

int is_cmd(info_t *info, char *path);

char *find_path(info_t *info, char *pathstr, char *cmd) {

  int idx = 0;
  char *path;
  char *dir;
  while (1) {
    dir = get_next_path_segment(pathstr, &idx);
    path = join_path(dir, cmd);
    
    if (is_cmd(info, path)) {
      return path;
    }

    free(dir);
    if (!pathstr[idx]) {
      break;
    }
  }

  return NULL;
}

char *get_next_path_segment(char *pathstr, int *idx) {
  char *start = pathstr + *idx;
  char *end = strchr(start, ':');
  size_t len = end ? (size_t) (end - start) : strlen(start);

  char *segment = dup_chars(start, 0, len);
  *idx += len + 1;

  return segment;  
}

char *join_path(char *dir, char *file) {
  char *path = malloc(strlen(dir) + strlen(file) + 2);

  path = _strcat(path, dir);
  path = _strcat(path, "/");
  path = _strcat(path, file);

  return path;
}
