/*
** EPITECH PROJECT, 2018
** my_octal
** File description:
** octal
*/

#include <unistd.h>
#include "my.h"

int my_octal(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 8) {
        my_octal(nb / 8);
        my_octal(nb % 8);
    } else
        my_putchar(nb + '0');
    return (nb);
}
