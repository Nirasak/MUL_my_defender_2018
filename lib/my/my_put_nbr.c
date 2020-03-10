/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** afficher un int
*/

#include <unistd.h>
#include "my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else
        my_putchar(nb + '0');
    return (nb);
}
