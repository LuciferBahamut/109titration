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

int start(int ac, char **av);

int error_handling(char *file);
void write_error(char *str);
int my_strlen(char const *str);

#endif
