/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** itoa
*/

#include "my.h"

int my_compute_power_it(int nb, int p)
{
    int nb2 = nb;

    if (p < 0)
        return (0);
    else if (p == 0)
        return (1);
    while (p > 1) {
        nb = nb * nb2;
        if (nb2 > 0 && nb < 0)
            return (0);
        p = p - 1;
    }
    return (nb);
}

int my_nblen(int nb)
{
    int j = 0;

    for (; nb != 0; j = j + 1)
        nb = nb / 10;
    return (j);
}

char *my_itoa(int nb)
{
    int len = my_nblen(nb);
    char *str = malloc(sizeof(char) * (len + 2));
    int len2 = len;
    int tmpry = 0;
    int i = 0;

    if (nb == 0) {
        str[i] = '0';
        str[i + 1] = '\0';
        return (str);
    }
    for (; i < len2; i = i + 1) {
        len = len - 1;
        tmpry = nb / my_compute_power_it(10, len);
        nb = nb - (tmpry * my_compute_power_it(10, len));
        str[i] = tmpry + '0';
    }
    str[i] = '\0';
    return (str);
}
