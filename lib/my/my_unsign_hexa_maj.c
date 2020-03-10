/*
** EPITECH PROJECT, 2018
** my_unsign_hexa_maj
** File description:
** printf
*/

#include "my.h"

unsigned int my_unsign_hexa_maj(unsigned int nb)
{
    if (nb >= 16) {
        my_unsign_hexa_maj(nb / 16);
        my_unsign_hexa_maj(nb % 16);
    } else if (nb >= 10 && nb < 16)
        my_putchar(nb + 55);
    else
        my_putchar(nb + '0');
    return (nb);
}
