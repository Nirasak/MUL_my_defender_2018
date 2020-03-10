/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** flag p
*/

#include "my.h"

long my_hexa_long(long nb)
{
    if (nb >= 16) {
        my_hexa_long(nb / 16);
        my_hexa_long(nb % 16);
    } else if (nb >= 10 && nb < 16)
        my_putchar(nb + 87);
    else
        my_putchar(nb + '0');
    return (nb);
}
