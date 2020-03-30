/*
** EPITECH PROJECT, 2020
** start
** File description:
** project
*/

#include "titration.h"
#include "error_msg.h"

int start(int ac, char **av)
{
    if (ac != 2) {
        write_error(STR_ERROR_ARG);
        return (ERROR);
    }
    if (my_strcmp(av[1], "-h"))
        return (display_help());
    if (error_handling(av[1]))
        return (ERROR);
    return (SUCCESS);
}
