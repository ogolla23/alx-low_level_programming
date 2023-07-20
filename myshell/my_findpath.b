#include "shell.h"

// Function to check if a command is present in a directory
int is_command_present(info_t *info, const char *path, const char *cmd) {
    char *full_path = NULL;
    int result = 0;

    // Create the full path by concatenating the directory path and command
    if (path && *path) {
        int path_len = _strlen(path);
        int cmd_len = _strlen(cmd);
        int full_path_len = path_len + 1 + cmd_len + 1; // path + '/' + cmd + '\0'
        full_path = (char *)malloc(full_path_len);

        if (full_path) {
            _strcpy(full_path, path);
            _strcat(full_path, "/");
            _strcat(full_path, cmd);

            // Check if the full path is a valid command
            if (is_cmd(info, full_path))
                result = 1;
        }
    }

    // Free allocated memory and return the result
    free(full_path);
    return result;
}

// Function to find the command in the specified paths
char *find_path(info_t *info, char *pathstr, char *cmd) {
    int i = 0, curr_pos = 0;
    char *path;

    if (!pathstr)
        return NULL;

    // Check if the command starts with "./" and if it is a valid command
    if ((_strlen(cmd) > 2) && starts_with(cmd, "./")) {
        if (is_cmd(info, cmd))
            return cmd;
    }

    while (1) {
        if (!pathstr[i] || pathstr[i] == ':') {
            path = dup_chars(pathstr, curr_pos, i);

            // Append the command to the directory path and check if it is a valid command
            if (*path) {
                _strcat(path, "/");
                _strcat(path, cmd);
            } else {
                _strcpy(path, cmd);
            }

            if (is_cmd(info, path))
                return path;

            if (!pathstr[i])
                break;

            curr_pos = i + 1; // Move to the next path
        }

        i++;
    }

    return NULL;
}

