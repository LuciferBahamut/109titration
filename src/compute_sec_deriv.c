/*
** EPITECH PROJECT, 2020
** 109titration
** File description:
** compute the second derivative
*/

#include "titration.h"

static double compute_forward_bis(values_t *v, int i)
{
    double res = 0;

    v->h = (v->tabx[i + 1] - v->tabx[i]);
    res = (v->dev[i + 1] - v->dev[i]) / v->h;
    return (res);
}

static double compute_backward_bis(values_t *v, int i)
{
    double res = 0;

    v->hprime = (v->tabx[i] - v->tabx[i - 1]);
    res = (v->dev[i] - v->dev[i - 1]) / v->hprime;
    return (res);
}

void compute_sec_derivative(values_t *v)
{
    double stock = 0;
    double stock1 = 0;

    for(int i = 2; i != v->nb - 2; i++) {
        stock = compute_forward_bis(v, i);
        stock1 = compute_backward_bis(v, i);
        v->sec[i] = ((stock * v->hprime) + (stock1 * v->h)) / (v->h + v->hprime);
    }
}
