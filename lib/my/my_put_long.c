/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** printf
*/

#include <unistd.h>
#include "my.h"

long my_put_long(long nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_long(nb / 10);
        my_put_long(nb % 10);
    } else
        my_putchar(nb + '0');
    return (nb);
}
