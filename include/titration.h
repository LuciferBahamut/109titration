/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef _TITRATION_H_
#define _TITRATION_H_

#define SUCCESS 0
#define ERROR 84
#define TRUE 1
#define FALSE 0

typedef struct values_s
{
    double *tabx;
    double *taby;
    int nb;
} values_t;

int start(int ac, char **av, values_t *v);
void open_file(char **av, values_t *v);

int display_help(void);
int error_handling(char *file);

void write_error(char *str);
int my_strlen(char const *str);
int my_strcmp(char const *str1, char const *str2);

#endif
