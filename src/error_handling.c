/*
** EPITECH PROJECT, 2020
** 109titration
** File description:
** error_handling
*/

#include "titration.h"
#include "error_msg.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int check_buffer(char *buff)
{
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n' || buff[i] == ';' || buff[i] == '.')
            continue;
        if (buff[i] < '0' || buff[i] > '9') {
            write_error(STR_ERROR_INV);
            return (TRUE);
        }
    }
    return (FALSE);
}

static char *read_file(int fd, char *file)
{
    struct stat st;
    char *buffer;
    int rd = 0;

    stat(file, &st);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    rd = read(fd, buffer, st.st_size);
    if (rd == -1 || rd == 0)
        return (NULL);
    return (buffer);
}

int error_handling(char *file)
{
    int fd = open(file, O_RDONLY);
    char *buffer;

    if (fd == -1) {
        write_error(STR_ERROR_OPEN);
        return (TRUE);
    }
    if ((buffer = read_file(fd, file)) == NULL) {
        close(fd);
        free(buffer);
        return (TRUE);
    }
    if (check_buffer(buffer)) {
        close(fd);
        free(buffer);
        return (TRUE);
    }
    close(fd);
    free(buffer);
    return (FALSE);
}
