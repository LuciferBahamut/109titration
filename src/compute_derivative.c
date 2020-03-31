/*
** EPITECH PROJECT, 2020
** 109titration
** File description:
** compute the first derivative
*/

#include "titration.h"

static double compute_forward(values_t *v, int i)
{
    double res = 0;

    v->h = (v->tabx[i + 1] - v->tabx[i]);
    res = (v->taby[i + 1] - v->taby[i]) / v->h;
    return (res);
}

static double compute_backward(values_t *v, int i)
{
    double res = 0;

    v->hprime = (v->tabx[i] - v->tabx[i - 1]);
    res = (v->taby[i] - v->taby[i - 1]) / v->hprime;
    return (res);
}

void compute_derivate(values_t *v)
{
    double stock = 0;
    double stock1 = 0;

    for (int i = 1; i != v->nb - 1; i++) {
        stock = compute_forward(v, i);
        stock1 = compute_backward(v, i);
        v->dev[i] = ((stock * v->hprime) + (stock1 * v->h)) / (v->h + v->hprime);
    }
}
