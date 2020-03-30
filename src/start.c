/*
** EPITECH PROJECT, 2020
** start
** File description:
** project
*/

#include "titration.h"
#include "error_msg.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static char **my_split(char *src, int nb)
{
    char **str = malloc(sizeof(char *) * nb);
    int i = 0;
    int k = 0;

    for (int j = 0; src[i] != '\0'; i++) {
        if (src[i] == ';' || src[i] == '\n')
            j++;
        str[j] = malloc(sizeof(char) * (i + 1));
    }
    i = 0;
    for (int j = 0; src[i] != '\0'; i++, k++) {
        if (src[i] == ';' || src[i] == '\n') {
            str[j][k] = '\0';
            j++;
            i++;
            k = 0;
        }
        str[j][k] = src[i];
    }
    str[nb] = NULL;
    return (str);
}

static int count_line(char *file)
{
    int nb = 0;

    for (int i = 0; file[i] != '\0'; i++)
        if (file[i] == '\n' || file[i] == ';')
            nb++;
    return (nb);
}

static void recup_values(char *file, values_t *v)
{
    int nb = count_line(file);
    char **split = my_split(file, nb);

    nb = nb / 2;
    v->tabx = malloc(sizeof(double) * nb);
    v->taby = malloc(sizeof(double) * nb);
    for (int i = 0, j = 0, k = 0; split[i] != NULL; i++) {
        if (i % 2 == 0) {
            v->tabx[j] = atof(split[i]);
            j++;
        }
        else {
            v->taby[k] = atof(split[i]);
            k++;
        }
    }
    for (int i = 0; split[i] != NULL; i++)
        free(split[i]);
    free(split);
}

static void open_file(char **av, values_t *v)
{
    int fd = 0;
    struct stat st;
    char *buffer;

    fd = open(av[1], O_RDONLY);
    stat(av[1], &st);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    read(fd, buffer, st.st_size);
    buffer[st.st_size + 1] = '\0';
    recup_values(buffer, v);
}

int start(int ac, char **av, values_t *v)
{
    if (ac != 2) {
        write_error(STR_ERROR_ARG);
        return (ERROR);
    }
    if (my_strcmp(av[1], "-h"))
        return (display_help());
    if (error_handling(av[1]))
        return (ERROR);
    v = malloc(sizeof(values_t));
    open_file(av, v);
    return (SUCCESS);
}
