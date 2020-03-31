/*
** EPITECH PROJECT, 2020
** 109titration
** File description:
** compute
*/

#include "titration.h"

static void find_prec_eq_point(values_t *v)
{
}

static void find_eq_point(values_t *v)
{
    v->eq_p = v->tabx[1];
    for (int i = 0; i != v->nb - 1; i++) {
        if (v->dev[i] < v->dev[i + 1])
            v->eq_p = v->tabx[i + 1];
    }
}

void titration(values_t *v)
{
    compute_derivate(v);
    display_derivative(v);
    find_eq_point(v);
    display_equivalence(v);
    compute_sec_derivative(v);
    display_sec_derivative(v);
}
