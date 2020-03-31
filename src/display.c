/*
** EPITECH PROJECT, 2020
** 109titration
** File description:
** display the values
*/

#include "titration.h"
#include <stdio.h>

void display_derivative(values_t *v)
{
    printf("Derivative:\n");
    printf("\n");
}

void display_sec_derivative(values_t *v)
{
    printf("\nSecond derivative:\n");
    printf("\n");
}

void display_sec_derivative_esti(values_t *v)
{
    printf("Second derivative estimated:\n");
    printf("\n");
}

void display_equivalence(values_t *v)
{
    printf("Equivalence point at %.1f ml\n", v->eq_p);
}