/*
** EPITECH PROJECT, 2020
** 109titration
** File description:
** compute
*/

#include "titration.h"

double compute_forward(values_t *v, int i)
{
    double res = 0;

    v->h = (v->tabx[i + 1] - v->tabx[i]);
    res = (v->taby[i + 1] - v->taby[i]) / v->h; 
    return (res);
}

double compute_backward(values_t *v, int i)
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
    double coef = 0;

    for (int i = 1; i != v->nb - 1; i++) {
        stock = compute_forward(v, i);
        stock1 = compute_backward(v, i);
        if (v->h < v->hprime) {
            printf("%.2f\t%.2f\n",v->h, v->hprime);
            if (v->h >=1 && v->hprime >= 1) {
                coef = v->hprime / v->h;
                v->dev[i] = ((stock * coef) + stock1) / (v->h + v->hprime);
            }
            else {
                coef = v->h / v->hprime;
                v->dev[i] = (stock + (stock1 * coef)) / (v->h + v->hprime);
            }
            printf("A\n");
        }
        else if (v->h > v->hprime) {
            coef = v->h / v->hprime;
            printf("%.2f\t%.2f\t%.2f\n",v->h, v->hprime, coef);
            v->dev[i] = (stock + (stock1 * coef)) / (v->h + v->hprime);
            printf("B\n");
        }
        else
            v->dev[i] = (stock + stock1) / 2;
        printf("%.2f\t %.2f\n\n", stock, stock1);
    }
}

void titration(values_t *v)
{
    compute_derivate(v);
    display_derivative(v);
}
